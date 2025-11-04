/***********************************/
/* SWC:     LEDM Driver            */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    24 June 2024           */
/***********************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "LEDM_Interface.h"
#include "LEDM_Private.h"
#include "LEDM_Config.h"
#include "GPIO_interface.h"
#include "NVIC_Interface.h"
void LEDM_voidDisplay(u8* Display_frame_data){
    Disable_Cloums();
    Disable_Rows();
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM0,LEDM_PINCLOUM0,PIN_SET);
    Send_ROWData(Display_frame_data[0]);
    STK_voidSetBusyWait(2500);
    Disable_Cloums();
    Disable_Rows();

    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM0,LEDM_PINCLOUM1,PIN_SET);
    Send_ROWData(Display_frame_data[1]);
    STK_voidSetBusyWait(2500);
    Disable_Cloums();
    Disable_Rows();

    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM0,LEDM_PINCLOUM2,PIN_SET);
    Send_ROWData(Display_frame_data[2]);
    STK_voidSetBusyWait(2500);
    Disable_Cloums();
    Disable_Rows();

    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM0,LEDM_PINCLOUM3,PIN_SET);
    Send_ROWData(Display_frame_data[3]);
    STK_voidSetBusyWait(2500);
    Disable_Cloums();
    Disable_Rows();

    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM0,LEDM_PINCLOUM4,PIN_SET);
    Send_ROWData(Display_frame_data[4]);
    STK_voidSetBusyWait(2500);
    Disable_Cloums();
    Disable_Rows();

    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM0,LEDM_PINCLOUM5,PIN_SET);
    Send_ROWData(Display_frame_data[5]);
    STK_voidSetBusyWait(2500);
    Disable_Cloums();
    Disable_Rows();

    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM0,LEDM_PINCLOUM6,PIN_SET);
    Send_ROWData(Display_frame_data[6]);
    STK_voidSetBusyWait(2500);
    Disable_Cloums();
    Disable_Rows();

    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM0,LEDM_PINCLOUM7,PIN_SET);
    Send_ROWData(Display_frame_data[7]);
    STK_voidSetBusyWait(2500);
    Disable_Cloums();
    Disable_Rows();
}
void LEDM_voidinti(){
    GPIO_PinInti(LEDM_PORTCLOUM0,LEDM_PINCLOUM0);
    GPIO_PinInti(LEDM_PORTCLOUM1,LEDM_PINCLOUM1);
    GPIO_PinInti(LEDM_PORTCLOUM2,LEDM_PINCLOUM2);
    GPIO_PinInti(LEDM_PORTCLOUM3,LEDM_PINCLOUM3);
    GPIO_PinInti(LEDM_PORTCLOUM4,LEDM_PINCLOUM4);
    GPIO_PinInti(LEDM_PORTCLOUM5,LEDM_PINCLOUM5);
    GPIO_PinInti(LEDM_PORTCLOUM6,LEDM_PINCLOUM6);
    GPIO_PinInti(LEDM_PORTCLOUM7,LEDM_PINCLOUM7);

    GPIO_PinInti(LEDM_PORTROW0,LEDM_PINROW0);
    GPIO_PinInti(LEDM_PORTROW1,LEDM_PINROW1);
    GPIO_PinInti(LEDM_PORTROW2,LEDM_PINROW2);
    GPIO_PinInti(LEDM_PORTROW3,LEDM_PINROW3);
    GPIO_PinInti(LEDM_PORTROW4,LEDM_PINROW4);
    GPIO_PinInti(LEDM_PORTROW5,LEDM_PINROW5);
    GPIO_PinInti(LEDM_PORTROW6,LEDM_PINROW6);
    GPIO_PinInti(LEDM_PORTROW7,LEDM_PINROW7);

}

void GPIO_PinInti(u8 Copy_u8PortId,u8 Copy_u8PinId){
        GPIO_voidSetPinMode (Copy_u8PortId, Copy_u8PinId, OUTPUT);
        GPIO_voidSetPinType (Copy_u8PortId, Copy_u8PinId,OUTPUT_PP);
        GPIO_voidSetPinSpeed(Copy_u8PortId,Copy_u8PinId,OUTPUT_LS);
}
void Disable_Rows(){
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW0,LEDM_PINROW0,PIN_SET);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW1,LEDM_PINROW1,PIN_SET);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW2,LEDM_PINROW2,PIN_SET);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW3,LEDM_PINROW3,PIN_SET);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW4,LEDM_PINROW4,PIN_SET);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW5,LEDM_PINROW5,PIN_SET);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW6,LEDM_PINROW6,PIN_SET);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW7,LEDM_PINROW7,PIN_SET);
}
void Disable_Cloums(){
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM0,LEDM_PINCLOUM0,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM1,LEDM_PINCLOUM1,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM2,LEDM_PINCLOUM2,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM3,LEDM_PINCLOUM3,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM4,LEDM_PINCLOUM4,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM5,LEDM_PINCLOUM5,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM6,LEDM_PINCLOUM6,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTCLOUM7,LEDM_PINCLOUM7,PIN_RST);
}
void Send_ROWData(u8 copy_RowData){
    
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW0,LEDM_PINROW0,GET_BIT(copy_RowData,0));
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW1,LEDM_PINROW1,GET_BIT(copy_RowData,1));
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW2,LEDM_PINROW2,GET_BIT(copy_RowData,2));
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW3,LEDM_PINROW3,GET_BIT(copy_RowData,3));
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW4,LEDM_PINROW4,GET_BIT(copy_RowData,4));
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW5,LEDM_PINROW5,GET_BIT(copy_RowData,5));
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW6,LEDM_PINROW6,GET_BIT(copy_RowData,6));
    GPIO_voidSetPinValueDirectAccess(LEDM_PORTROW7,LEDM_PINROW7,GET_BIT(copy_RowData,7));

}
void LEDM_voidDisplay_NAME(u8* Display_frame_data,u8 copy_u8size){
static u8 counter_letters=0;
for(counter_letters=0;counter_letters<(copy_u8size-8);){
	static u8 Frame=0;
	LEDM_voidDisplay(Display_frame_data+counter_letters);
	Frame++;
	if(Frame==110){
		counter_letters++;
		Frame=0;
	}
}
}
