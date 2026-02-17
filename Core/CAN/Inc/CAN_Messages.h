/*
 * CAN_Messages.h
 *
 *  Created on: Feb 10, 2026
 *      Author: RFTRYazilim
 */

#ifndef CAN_INC_CAN_MESSAGES_H_
#define CAN_INC_CAN_MESSAGES_H_
#define FLASH_SECTOR2_BASE_ADRESS 0x08008000

#include <stdbool.h>
#include <stm32f4xx_hal.h>
typedef enum
{
	UI_Bootloader_Command = 0x100,
	CNTRL_Bootloader_Command = 0x101,
	UI_Update_Request = 0x102,
	CNTRL_Update_Request = 0x103,
	UI_BIN_Datas = 0x104,
	CNTRL_BIN_Datas = 0x105,
	CNTRL_Update_Compleated = 0x106

}CAN_Messages_ID;

typedef enum
{
	CNTRL_Bootloader_Command_DLC = 5,
	CNTRL_Update_Request_DLC = 2,
	CNTRL_BIN_Datas_DLC = 2,
	CNTRL_Update_Compleated_DLC = 2
}CAN_Messages_DLC;


bool FillCANContentAndTransmit(CAN_HandleTypeDef *CANHandle, uint32_t ID , uint8_t DLC);
void UIBootloaderCommandAnswer(void);
void UIBINDatasAnswer(void);
void UIUpdateCompleated(bool IsOkey);
void UIUpdateRequestAnswer(void);
void FindCANMessage(uint32_t ID, uint8_t CAN2RxData[]);
#endif /* CAN_INC_CAN_MESSAGES_H_ */
