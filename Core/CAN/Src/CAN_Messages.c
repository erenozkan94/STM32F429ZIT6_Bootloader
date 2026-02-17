/*
 * CAN_Messages.c
 *
 *  Created on: Feb 10, 2026
 *      Author: RFTRYazilim
 */
#include "CAN_Messages.h"
#include "../../Bootloader/Inc/Bootloder.h"

CAN_TxHeaderTypeDef CAN2TxHeader;
uint8_t CAN2TxData[8] = {0};
uint8_t CAN2RxData[8] = {0};
uint32_t CAN2Mailbox = 0;
bool SendInformation = false;
uint8_t VersionNumber1 = 1;
uint8_t VersionNumber2 = 0;
uint8_t VersionNumber3 = 0;
CAN_HandleTypeDef hcan2;

extern bool EnterBootloader;
extern bool UpdateApp;
extern bool JumpToAppFlag;
extern bool ReceipedHeaderFile;
bool FillCANContentAndTransmit(CAN_HandleTypeDef *CANHandle, uint32_t ID , uint8_t DLC)
{
    if(DLC > 8) DLC = 8;
    CAN2TxHeader.DLC = DLC;
    CAN2TxHeader.RTR = CAN_RTR_DATA;
    CAN2TxHeader.TransmitGlobalTime = DISABLE;

    if(ID > 0x7FF)
    {
    	CAN2TxHeader.ExtId = ID;
    	CAN2TxHeader.IDE = CAN_ID_EXT;
    }
    else
    {
    	CAN2TxHeader.StdId = ID;
    	CAN2TxHeader.IDE = CAN_ID_STD;
    }
    uint32_t timeout = HAL_GetTick();
    while (HAL_CAN_GetTxMailboxesFreeLevel(CANHandle) == 0) {
	if (HAL_GetTick() - timeout > 100)
	{
		return false;
	}
    }
    if (HAL_CAN_AddTxMessage(CANHandle, &CAN2TxHeader, CAN2TxData, &CAN2Mailbox) == HAL_OK) {
        return true;
    }
    return false;
}
void UIBootloaderCommandAnswer() //0x101
{
	if(EnterBootloader == false)
	{
		EnterBootloader = true;
	}
	CAN2TxData[0] = (uint8_t) 0x10;
	CAN2TxData[1] = (uint8_t) EnterBootloader;
	CAN2TxData[2] = (uint8_t) VersionNumber1;
	CAN2TxData[3] = (uint8_t) VersionNumber2;
	CAN2TxData[4] = (uint8_t) VersionNumber3;
	SendInformation = FillCANContentAndTransmit(&hcan2, CNTRL_Bootloader_Command, CNTRL_Bootloader_Command_DLC);
}
void UIUpdateRequestAnswer() //0x103
{
	if(EnterBootloader && UpdateApp)
	{
		uint8_t FLASH_LEVEL;
		FLASH_OBProgramInitTypeDef OB_InitStruct = {0};
		HAL_FLASHEx_OBGetConfig(&OB_InitStruct);
		FLASH_LEVEL = (uint8_t)OB_InitStruct.RDPLevel;
		CAN2TxData[0] = (uint8_t) 0x10;
		if(Bootloader_Erase_Flash() && FLASH_LEVEL == 170)
		{
			CAN2TxData[1] = (uint8_t)  1;
		}
		else
		{
			CAN2TxData[1] = (uint8_t)  0;
		}
		SendInformation = FillCANContentAndTransmit(&hcan2, CNTRL_Update_Request, CNTRL_Update_Request_DLC);
	}
}
void UIBINDatasAnswer() //0x105
{
	CAN2TxData[0] = (uint8_t) 0x10;
	CAN2TxData[1] = (uint8_t) 0x01;
	SendInformation = FillCANContentAndTransmit(&hcan2, CNTRL_BIN_Datas, CNTRL_BIN_Datas_DLC);
}
void UIUpdateCompleated(bool IsOkey) //0x106
{
	CAN2TxData[0] = (uint8_t) 0x10;
	CAN2TxData[1] = (uint8_t) IsOkey;
	SendInformation = FillCANContentAndTransmit(&hcan2, CNTRL_Update_Compleated, CNTRL_Update_Compleated_DLC);
}
void FindCANMessage(uint32_t ID, uint8_t CAN2RxData[])
{
	switch(ID)
	{
		case UI_Bootloader_Command:
		{
			if(CAN2RxData[0] == 16)
			{
				UIBootloaderCommandAnswer();
			}
		}
		break;
		case UI_Update_Request:
		{
			if(CAN2RxData[0] == 16 && CAN2RxData[1] == 1)
			{
				UIUpdateRequestAnswer();
			}
			else
			{
				JumpToAppFlag = true;
			}
		}
		break;
		case UI_BIN_Datas:
			{
				GetBinFile();
			}
			break;
		default:
		break;
	}
}
