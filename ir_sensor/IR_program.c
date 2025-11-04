/***********************************/
/* SWC: IR Driver                  */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 9 June 2024               */
/***********************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include <EXTI_interface.h>
#include <STK_interface.h>
#include <GPIO_Interface.h>
#include <IR_config.h>
#include <IR_interface.h>
#include <IR_private.h>

void GPIO_IRPinIntiASOut(u8 Copy_u8PortId,u8 Copy_u8PinId){
        GPIO_voidSetPinMode (Copy_u8PortId, Copy_u8PinId, OUTPUT);
        GPIO_voidSetPinType (Copy_u8PortId, Copy_u8PinId,OUTPUT_PP);
        GPIO_voidSetPinSpeed(Copy_u8PortId,Copy_u8PinId,OUTPUT_HS);
}
void GPIO_IRPinIntiASINPUT(u8 Copy_u8PortId,u8 Copy_u8PinId){
	GPIO_voidSetPinMode(Copy_u8PortId, Copy_u8PinId, INPUT);
	GPIO_voidSetPinPUPDOption(Copy_u8PortId, Copy_u8PinId, INPUT_PU);
	GPIO_voidSetPinSpeed(Copy_u8PortId,Copy_u8PinId,OUTPUT_LS);
	EXTI_VoidSetExtiLineEnable(Copy_u8PinId);
	EXTI_VoidSetSenseControl(Copy_u8PinId,Falling_Edge);
	EXTI_voidSetEXTIpinConfig(Copy_u8PinId,Copy_u8PortId);
}
/*void IR_inti(u8 copy_IRStates){
    switch (copy_IRStates)
    {
    case READ:
    
        break;
    case WRITE:
    
    break;
    default:
    //do nothing
    break;
    }
}*/
void IR_voidSend(u8 Copy_IRAdderss,u8 Copy_IRData){
    u8 local_counter;
    GPIO_IRPinIntiASOut(IR_PORTID,IR_PINID);
    /*SEND Start BIT*/
    IR_SendStartBit(IR_PORTID,IR_PINID);
    /*SEND ADDRESS*/
    for (local_counter=0;local_counter<8;local_counter++)
    {
        switch (GET_BIT(Copy_IRAdderss,local_counter))
        {
        case PIN_SET:
            IR_SendOneBit(IR_PORTID,IR_PINID);
            break;
        case PIN_RST:
            IR_SendZeroBit(IR_PORTID,IR_PINID);
            break;
        default:
            break;
        }
    }
    /*SEND IADDRESS*/
    for (local_counter=0;local_counter<8;local_counter++)
    {
        switch (GET_BIT(Copy_IRAdderss,local_counter))
        {
        case PIN_SET:
            IR_SendZeroBit(IR_PORTID,IR_PINID);
            break;
        case PIN_RST:
            IR_SendOneBit(IR_PORTID,IR_PINID);
            break;
        default:
            break;
        }
    }
    
    /*SEND DATA*/
    for (local_counter=0;local_counter<8;local_counter++)
    {
        switch (GET_BIT(Copy_IRData,local_counter))
        {
        case PIN_SET:
            IR_SendOneBit(IR_PORTID,IR_PINID);
            break;
        case PIN_RST:
            IR_SendZeroBit(IR_PORTID,IR_PINID);
            break;
        default:
            break;
        }
    }
    /*SEND IDATA*/
    for (local_counter=0;local_counter<8;local_counter++)
    {
        switch (GET_BIT(Copy_IRData,local_counter))
        {
        case PIN_SET:
            IR_SendZeroBit(IR_PORTID,IR_PINID);
            break;
        case PIN_RST:
            IR_SendOneBit(IR_PORTID,IR_PINID);
            break;
        default:
            break;
        }
    }
}

u8 IR_voidReceive(u8 Copy_IRAdderss,u8 Copy_DataAdderss){
    GPIO_IRPinIntiASINPUT(IR_PORTID,IR_PINID);
    return 0;
}

void IR_SendTrain(u8 Copy_u8PortId,u8 Copy_u8PinId){
    GPIO_voidSetPinValueDirectAccess(Copy_u8PortId,Copy_u8PinId,PIN_SET);
    STK_voidSetBusyWait(13);
    GPIO_voidSetPinValueDirectAccess(Copy_u8PortId,Copy_u8PinId,PIN_RST);
    STK_voidSetBusyWait(13);
}

void IR_SendStartBit(u8 Copy_u8PortId,u8 Copy_u8PinId){
    u32 local_counter;
    /*SEND Train Sequnce*/
    for(local_counter=0;local_counter<346;local_counter++){
        IR_SendTrain(Copy_u8PortId,Copy_u8PinId);
    }
    /*stop for 4.5ms*/
    STK_voidSetBusyWait(4500);
}
void IR_SendOneBit(u8 Copy_u8PortId,u8 Copy_u8PinId){
    u8 local_counter;
    /*SEND Train Sequnce*/
    for(local_counter=0;local_counter<22;local_counter++){
        IR_SendTrain(Copy_u8PortId,Copy_u8PinId);
    }
    /*stop for 1687us*/
    STK_voidSetBusyWait(1687);


}
void IR_SendZeroBit(u8 Copy_u8PortId,u8 Copy_u8PinId){
    u8 local_counter;
    /*SEND Train Sequnce*/
    for(local_counter=0;local_counter<22;local_counter++){
        IR_SendTrain(Copy_u8PortId,Copy_u8PinId);
    }
    /*stop for 560us*/
    STK_voidSetBusyWait(560);

}

