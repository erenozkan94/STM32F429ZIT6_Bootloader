/*
 * Bootloader.c
 *
 *  Created on: Feb 17, 2026
 *      Author: RFTRYazilim
 */

#define PAGE_SIZE 256

#include <stm32f429xx.h>
#include <stdbool.h>
#include "CAN_Messages.h"

uint8_t pageBuffer[PAGE_SIZE];
uint16_t bufferIndex = 0;
uint32_t totalReceived = 0;
uint32_t ExpectedFileSize = 0;
uint8_t  ExpectedFileCRC = 0;
uint32_t currentFlashAddress = FLASH_SECTOR2_BASE_ADRESS;
bool JumpToAppFlag = false;
bool ReceipedHeaderFile = false;

extern uint32_t CAN2Mailbox;
extern CAN_HandleTypeDef hcan2;
extern uint8_t CAN2RxData[8];

void CheckAndResetAfterUpdate(void)
{
    uint16_t rollingSum = 0;
    uint8_t calculatedCRC = 0;

    for (uint32_t i = 0; i < ExpectedFileSize; i++)
    {
        uint8_t flashByte = *(volatile uint8_t*)(FLASH_SECTOR2_BASE_ADRESS + i);
        rollingSum += flashByte;

        if (rollingSum > 255)
        {
            rollingSum -= 255;
        }
    }

    calculatedCRC = (uint8_t)rollingSum;
    calculatedCRC ^= 0xFF;

    if (calculatedCRC == ExpectedFileCRC)
    {
    	UIUpdateCompleated(1);

    	uint32_t WaitTick = HAL_GetTick();
		while(HAL_CAN_IsTxMessagePending(&hcan2, CAN2Mailbox))
		{
			if(HAL_GetTick() - WaitTick > 100) break;
		}

        JumpToAppFlag = true;
    }
    else
    {
    	UIUpdateCompleated(0);
        ReceipedHeaderFile = false;
        totalReceived = 0;
    }
}
void GetBinFile(void)
{
	if(CAN2RxData[0] == 16 && ReceipedHeaderFile == false)
	{
		currentFlashAddress = FLASH_SECTOR2_BASE_ADRESS;
		ExpectedFileSize = (uint32_t)(CAN2RxData[1] | (CAN2RxData[2] << 8) |
									 (CAN2RxData[3] << 16) | (CAN2RxData[4] << 24));
		ExpectedFileCRC = CAN2RxData[5];

		totalReceived = 0;
		bufferIndex = 0;
		ReceipedHeaderFile = true;
		UIBINDatasAnswer();
	}
	else if(ReceipedHeaderFile == true)
	{
		for(int i = 0; i < 8; i++)
		{
			if(totalReceived < ExpectedFileSize)
			{
				pageBuffer[bufferIndex++] = CAN2RxData[i];
				totalReceived++;

				if(bufferIndex >= PAGE_SIZE)
				{
					HAL_FLASH_Unlock();
					for (int j = 0; j < PAGE_SIZE; j += 4) {
						uint32_t dataToWrite = *(uint32_t*)(&pageBuffer[j]);
						if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, currentFlashAddress + j, dataToWrite) != HAL_OK)
						{
						    UIUpdateCompleated(0);
						}
					}
					HAL_FLASH_Lock();

					currentFlashAddress += PAGE_SIZE;
					bufferIndex = 0;
				}
			}
		}
		UIBINDatasAnswer();
		if(totalReceived >= ExpectedFileSize)
		{
			if(bufferIndex > 0)
			{
				HAL_FLASH_Unlock();
				for (int j = 0; j < bufferIndex; j += 4) {
					uint32_t dataToWrite = *(uint32_t*)(&pageBuffer[j]);
					HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, currentFlashAddress + j, dataToWrite);
				}
				HAL_FLASH_Lock();
			}
			CheckAndResetAfterUpdate();
			ReceipedHeaderFile = false;
		}
	}
}
uint8_t Bootloader_CRC_Check(uint8_t* frame, uint8_t length)
{
	uint8_t retWert = 0;
	uint16_t dummy = 0;

	for(int i = 0; i <= length; i++)
	{
		dummy += frame[i];

		if(dummy > 255)
			dummy -= 255;
	}

	retWert = (uint8_t)dummy;
	retWert ^= 0xFF;

	return retWert;
}
bool Bootloader_Erase_Flash(void)
{
	HAL_StatusTypeDef eraseStatus = {0};
	FLASH_EraseInitTypeDef FlashEraseInitStruct = {0};
	uint32_t sectorError = 0;

	FlashEraseInitStruct.TypeErase	= FLASH_TYPEERASE_SECTORS;
	FlashEraseInitStruct.Sector 	= FLASH_SECTOR_2;
	FlashEraseInitStruct.NbSectors	= 9;

	HAL_FLASH_Unlock();
	eraseStatus = HAL_FLASHEx_Erase(&FlashEraseInitStruct, &sectorError);
	HAL_FLASH_Lock();

	if(eraseStatus == HAL_OK)
	{
		return true;
	}
	else
	{
		return false;
	}
}
