/***********************************/
/* SWC: LCD Driver                 */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 20 June 2024              */
/***********************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
/*Command Data*/
#define Clear_display 				 0x01
#define Return_home 				 0x02
#define Entry_mode_set 				 0x06
#define Display_OFF_Control		     0x08
#define Display_ON_Control		     0x0C
#define Cursor_or_Display_Shift		 0x80
#define lcd_FunctionReset  			 0x30
#define lcd_FunctionSet8bit 		 0x38

void HLCD_SetCursorLocation(u8 copy_u8Row,u8 copy_u8Column);
void HLCD_WriteCommand(u8 copy_u8CommandID);
void HLCD_WriteData(u8 copy_u8DataValue);
void HLCD_WriteNumber(u32 copy_u8DataValue);
void HLCD_Intiaiztion(void);
void HLCD_WriteString(u8 *string);
void HLCD_ClearDisplay(void);

#endif /* LCD_INTERFACE_H_ */
