/***********************************/
/* SWC: LCD Driver                 */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 20 June 2024              */
/***********************************/

#include"../include/00-LIB/STD_TYPES.h"
#include"../include/00-LIB/BIT_MATH.h"
#include"GPIO_interface.h"
#include"LCD_interface.h"
#include"LCD_private.h"
#include"LCD_config.h"

#define TIM2_CR1 *((volatile u32*)0x40000000)
#define TIM2_SR *((volatile u32*)0x40000010)
#define TIM2_CNT *((volatile u32*)0x40000024)
#define TIM2_PSC *((volatile u32*)0x40000028)

void timmer2_Delay_us(u16 Delay_us){
	/*set as count down*/
	SET_BIT(TIM2_CR1,4);
	TIM2_PSC=7;//AHB1/PSC+1
	TIM2_CNT=Delay_us;
	SET_BIT(TIM2_CR1,0);
	while(GET_BIT(TIM2_SR,0)==0);
	CLR_BIT(TIM2_SR,0);
}
void HLCD_WriteCommand(u8 copy_u8CommandID){

	GPIO_voidSetPinValueDirectAccess   (LCD_RSPORTPIN , LCD_RSPIN, PIN_RST);
	GPIO_voidSetPinValueDirectAccess   (LCD_RWPORTPIN , LCD_RWPIN, PIN_RST);
	GPIO_voidSetPinValueDirectAccess   (LCD_ENPORTPIN , LCD_ENPIN, PIN_SET);

	Send_LCDData  (copy_u8CommandID);

	App_delaythreeus(1);
	GPIO_voidSetPinValueDirectAccess   (LCD_ENPORTPIN , LCD_ENPIN, PIN_RST);
	App_delaythreeus(1);
}
void HLCD_WriteData(u8 copy_u8DataValue){
	GPIO_voidSetPinValueDirectAccess   (LCD_RSPORTPIN , LCD_RSPIN, PIN_SET);
	GPIO_voidSetPinValueDirectAccess   (LCD_RWPORTPIN , LCD_RWPIN, PIN_RST);
	GPIO_voidSetPinValueDirectAccess   (LCD_ENPORTPIN, LCD_ENPIN, PIN_SET);

	Send_LCDData  	(copy_u8DataValue);

	App_delayMs(1);
	GPIO_voidSetPinValueDirectAccess   (LCD_ENPORTPIN, LCD_ENPIN, PIN_RST);
	App_delaythreeus(1);
}

void HLCD_Intiaiztion(void){
	GPIOLCD_PinInti(LCD_DATAPORTPIN0,LCD_DATAPIN0);
	GPIOLCD_PinInti(LCD_DATAPORTPIN1,LCD_DATAPIN1);
	GPIOLCD_PinInti(LCD_DATAPORTPIN2,LCD_DATAPIN2);
	GPIOLCD_PinInti(LCD_DATAPORTPIN3,LCD_DATAPIN3);
	GPIOLCD_PinInti(LCD_DATAPORTPIN4,LCD_DATAPIN4);
	GPIOLCD_PinInti(LCD_DATAPORTPIN5,LCD_DATAPIN5);
	GPIOLCD_PinInti(LCD_DATAPORTPIN6,LCD_DATAPIN6);
	GPIOLCD_PinInti(LCD_DATAPORTPIN7,LCD_DATAPIN7);
	GPIOLCD_PinInti(LCD_RSPORTPIN,LCD_RSPIN);
	GPIOLCD_PinInti(LCD_RWPORTPIN,LCD_RWPIN);
	GPIOLCD_PinInti(LCD_ENPORTPIN,LCD_ENPIN);
	App_delayMs(30);
	HLCD_WriteCommand(lcd_FunctionSet8bit);
	App_delaythreeus(20);
	HLCD_WriteCommand(Display_ON_Control);
	App_delaythreeus(20);
	HLCD_WriteCommand(Clear_display);
	App_delayMs(2);
	HLCD_WriteCommand(Entry_mode_set);
	App_delayMs(2);
}

void HLCD_WriteString(u8 *string){
		u8 iteration=0;
		for (iteration=0; string[iteration]!='\0' ; iteration++)
		{
			HLCD_WriteData(string[iteration]);
			App_delayMs(2);
		}

}
void HLCD_WriteNumber(u32 copy_u32DataValue){
	if(copy_u32DataValue==0)HLCD_WriteData(copy_u32DataValue+48);
else{
	u8 Lastdigait=0;
	u32 TenPowLastdigait=1;
	while(copy_u32DataValue/TenPowLastdigait){
		Lastdigait++;
		TenPowLastdigait*=10;
	}
	for(u8 iteration=0;iteration<Lastdigait;iteration++){
		TenPowLastdigait/=10;
		u8 Number=copy_u32DataValue/TenPowLastdigait;
		HLCD_WriteData(Number+48);
		copy_u32DataValue=copy_u32DataValue-Number*TenPowLastdigait;
	}
}
		App_delayMs(2);
}
void HLCD_SetCursorLocation(u8 copy_u8Row,u8 copy_u8Column){
	if (copy_u8Column>0 && copy_u8Column<=16)
		{
		    switch(copy_u8Row)
		    {
			    case 1:HLCD_WriteCommand((u8)(copy_u8Column+127));break;
			    case 2:HLCD_WriteCommand((u8)(copy_u8Column+191));break;
			    default:break;
		    }
		}
}

void HLCD_ClearDisplay(void){
	HLCD_WriteCommand(Clear_display);
	App_delayMs(2);
}

void App_delayMs(u32 Copy_u32Delay)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < Copy_u32Delay; Local_u32Counter++)
	{
		timmer2_Delay_us(1000);
	}
}
void App_delaythreeus(u32 Copy_u32Delay)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < Copy_u32Delay; Local_u32Counter++)
	{
		timmer2_Delay_us(3);
	}
}
void GPIOLCD_PinInti(u8 Copy_u8PortId,u8 Copy_u8PinId){
        GPIO_voidSetPinMode (Copy_u8PortId, Copy_u8PinId, OUTPUT);
        GPIO_voidSetPinType (Copy_u8PortId, Copy_u8PinId,OUTPUT_PP);
        GPIO_voidSetPinSpeed(Copy_u8PortId,Copy_u8PinId,OUTPUT_LS);
}

void Send_LCDData(u8 copy_RowData){
    
	GPIO_voidSetPinValueDirectAccess(LCD_DATAPORTPIN0,LCD_DATAPIN0,GET_BIT(copy_RowData,0));
    GPIO_voidSetPinValueDirectAccess(LCD_DATAPORTPIN1,LCD_DATAPIN1,GET_BIT(copy_RowData,1));
    GPIO_voidSetPinValueDirectAccess(LCD_DATAPORTPIN2,LCD_DATAPIN2,GET_BIT(copy_RowData,2));
    GPIO_voidSetPinValueDirectAccess(LCD_DATAPORTPIN3,LCD_DATAPIN3,GET_BIT(copy_RowData,3));
    GPIO_voidSetPinValueDirectAccess(LCD_DATAPORTPIN4,LCD_DATAPIN4,GET_BIT(copy_RowData,4));
    GPIO_voidSetPinValueDirectAccess(LCD_DATAPORTPIN5,LCD_DATAPIN5,GET_BIT(copy_RowData,5));
    GPIO_voidSetPinValueDirectAccess(LCD_DATAPORTPIN6,LCD_DATAPIN6,GET_BIT(copy_RowData,6));
    GPIO_voidSetPinValueDirectAccess(LCD_DATAPORTPIN7,LCD_DATAPIN7,GET_BIT(copy_RowData,7));

}
