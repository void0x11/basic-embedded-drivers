/***********************************/
/* SWC: LCD Driver                 */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 20 June 2024              */
/***********************************/

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_
/*Command Data*/

void App_delayMs(u32 Copy_u32Delay);
void App_delaythreeus(u32 Copy_u32Delay);
void GPIOLCD_PinInti(u8 Copy_u8PortId,u8 Copy_u8PinId);
void Send_LCDData(u8 copy_RowData);
#endif /* LCD_INTERFACE_H_ */
