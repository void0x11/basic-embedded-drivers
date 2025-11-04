/***********************************/
/* SWC:     LEDM_STP Driver        */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    26 June 2024           */
/***********************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include <LEDM_STP_config.h>
#include <LEDM_STP_interface.h>
#include <LEDM_STP_private.h>
#include <GPIO_Interface.h>
#include <STK_Interface.h>
void LEDM_STP_voidini(void){
    GPIO_LEDM_STPPinInti(STPPORTID,STPDATAIPUTPIN);
    GPIO_LEDM_STPPinInti(STPPORTID,SHIFTCLOCKPIN);
    GPIO_LEDM_STPPinInti(STPPORTID,STORECLOCKPIN);
    GPIO_voidSetPinValueDirectAccess(STPPORTID,STPDATAIPUTPIN,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(STPPORTID,SHIFTCLOCKPIN,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(STPPORTID,STORECLOCKPIN,PIN_RST);
    STK_voidSetBusyWait(1);
}
void LEDM_STP_voidSend(u16 copy_Data){
    u8 local_counter;
    for (local_counter = 0; local_counter < NUMBEROFPINS; local_counter++)
    {
        GPIO_voidSetPinValueDirectAccess(STPPORTID,STPDATAIPUTPIN,GET_BIT(copy_Data,NUMBEROFPINS-(local_counter+1)));
        STK_voidSetBusyWait(1);
        GPIO_voidSetPinValueDirectAccess(STPPORTID,SHIFTCLOCKPIN,PIN_SET);
        STK_voidSetBusyWait(1);
        GPIO_voidSetPinValueDirectAccess(STPPORTID,SHIFTCLOCKPIN,PIN_RST);
        STK_voidSetBusyWait(1);
    }
    GPIO_voidSetPinValueDirectAccess(STPPORTID,STORECLOCKPIN,PIN_SET);
    STK_voidSetBusyWait(1);
    GPIO_voidSetPinValueDirectAccess(STPPORTID,STORECLOCKPIN,PIN_RST);
    STK_voidSetBusyWait(1);
}
void GPIO_LEDM_STPPinInti(u8 Copy_u8PortId,u8 Copy_u8PinId){
    GPIO_voidSetPinMode (Copy_u8PortId, Copy_u8PinId, OUTPUT);
    GPIO_voidSetPinType (Copy_u8PortId, Copy_u8PinId,OUTPUT_PP);
    GPIO_voidSetPinSpeed(Copy_u8PortId,Copy_u8PinId,OUTPUT_LS);
}

void LEDM_STP_voidDisplay(u8* Display_frame_data){
    u8 local_counter;
    for(local_counter=0;local_counter<8;local_counter++){
    LEDM_STP_voidSend(Display_frame_data[local_counter]<<8|1<<local_counter);
    STK_voidSetBusyWait(2500);
    }
}

void LEDM_STP_voidDisplay_NAME(u8* Display_frame_data,u8 copy_u8size){
static u8 counter_letters=0;
for(counter_letters=0;counter_letters<(copy_u8size-8);){
	static u8 Frame=0;
	LEDM_STP_voidDisplay(Display_frame_data+counter_letters);
	Frame++;
	if(Frame==10){
		counter_letters++;
		Frame=0;
	}
}
}
