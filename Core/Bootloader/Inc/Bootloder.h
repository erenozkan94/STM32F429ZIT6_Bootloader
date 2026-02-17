/*
 * Bootloder.h
 *
 *  Created on: Feb 17, 2026
 *      Author: RFTRYazilim
 */
void CheckAndResetAfterUpdate(void);
void GetBinFile(void);
uint8_t Bootloader_CRC_Check(uint8_t* frame, uint8_t length);
bool Bootloader_Erase_Flash(void);
