/***********************************/
/* SWC: STP Driver                 */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 18 June 2024              */
/***********************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include <STP_interface.h>
#include <STP_config.h>
#include <STP_private.h>
#include <GPIO_Interface.h>
//#include <STK_Interface.h>
void STP_voidSend(u8 copy_u8PortId,u8 copy_DataInputPin,u8 copy_ShiftClockPin,u8 copy_StoreClockPin,u32 copy_Data){
    u8 local_counter;
    GPIO_STPPinInti(copy_u8PortId,copy_DataInputPin);
    GPIO_STPPinInti(copy_u8PortId,copy_ShiftClockPin);
    GPIO_STPPinInti(copy_u8PortId,copy_StoreClockPin);
    GPIO_voidSetPinValueDirectAccess(copy_u8PortId,copy_DataInputPin,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(copy_u8PortId,copy_ShiftClockPin,PIN_RST);
    GPIO_voidSetPinValueDirectAccess(copy_u8PortId,copy_StoreClockPin,PIN_RST);
    //STK_voidSetBusyWait(3);
    for (local_counter = 0; local_counter < NUMBEROFPINS; local_counter++)
    {
        GPIO_voidSetPinValueDirectAccess(copy_u8PortId,copy_DataInputPin,GET_BIT(copy_Data,NUMBEROFPINS-(local_counter+1)));
        //STK_voidSetBusyWait(20);
        GPIO_voidSetPinValueDirectAccess(copy_u8PortId,copy_ShiftClockPin,PIN_SET);
        //STK_voidSetBusyWait(20);
        GPIO_voidSetPinValueDirectAccess(copy_u8PortId,copy_ShiftClockPin,PIN_RST);
        //STK_voidSetBusyWait(20);
    }
    GPIO_voidSetPinValueDirectAccess(copy_u8PortId,copy_StoreClockPin,PIN_SET);
    //STK_voidSetBusyWait(20);
    GPIO_voidSetPinValueDirectAccess(copy_u8PortId,copy_StoreClockPin,PIN_RST);
    //STK_voidSetBusyWait(20);
}
void GPIO_STPPinInti(u8 Copy_u8PortId,u8 Copy_u8PinId){
    GPIO_voidSetPinMode (Copy_u8PortId, Copy_u8PinId, OUTPUT);
    GPIO_voidSetPinType (Copy_u8PortId, Copy_u8PinId,OUTPUT_PP);
    GPIO_voidSetPinSpeed(Copy_u8PortId,Copy_u8PinId,OUTPUT_LS);
}

