/***********************************/
/* SWC:     DAC Driver             */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    7 June 2024            */
/***********************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include <DAC_config.h>
#include <DAC_interface.h>
#include <DAC_private.h>
#include <GPIO_Interface.h>

void DAC_voidinti(){
    GPIO_DACPinInti(DAC_PINPORT0,DAC_PIN0);
    GPIO_DACPinInti(DAC_PINPORT1,DAC_PIN1);
    GPIO_DACPinInti(DAC_PINPORT2,DAC_PIN2);
    GPIO_DACPinInti(DAC_PINPORT3,DAC_PIN3);
    GPIO_DACPinInti(DAC_PINPORT4,DAC_PIN4);
    GPIO_DACPinInti(DAC_PINPORT5,DAC_PIN5);
    GPIO_DACPinInti(DAC_PINPORT6,DAC_PIN6);
    GPIO_DACPinInti(DAC_PINPORT7,DAC_PIN7);
}
void DAC_voidSand(u8 DAC_copyData){
        
    GPIO_voidSetPinValueDirectAccess(DAC_PINPORT0,DAC_PIN0,GET_BIT(DAC_copyData,0));
    GPIO_voidSetPinValueDirectAccess(DAC_PINPORT1,DAC_PIN1,GET_BIT(DAC_copyData,1));
    GPIO_voidSetPinValueDirectAccess(DAC_PINPORT2,DAC_PIN2,GET_BIT(DAC_copyData,2));
    GPIO_voidSetPinValueDirectAccess(DAC_PINPORT3,DAC_PIN3,GET_BIT(DAC_copyData,3));
    GPIO_voidSetPinValueDirectAccess(DAC_PINPORT4,DAC_PIN4,GET_BIT(DAC_copyData,4));
    GPIO_voidSetPinValueDirectAccess(DAC_PINPORT5,DAC_PIN5,GET_BIT(DAC_copyData,5));
    GPIO_voidSetPinValueDirectAccess(DAC_PINPORT6,DAC_PIN6,GET_BIT(DAC_copyData,6));
    GPIO_voidSetPinValueDirectAccess(DAC_PINPORT7,DAC_PIN7,GET_BIT(DAC_copyData,7));
}
void GPIO_DACPinInti(u8 Copy_u8PortId,u8 Copy_u8PinId){
        GPIO_voidSetPinMode (Copy_u8PortId, Copy_u8PinId, OUTPUT);
        GPIO_voidSetPinType (Copy_u8PortId, Copy_u8PinId,OUTPUT_PP);
        GPIO_voidSetPinSpeed(Copy_u8PortId,Copy_u8PinId,OUTPUT_LS);
}
