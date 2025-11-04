/***********************************/
/* SWC: IR Driver                  */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 9 June 2024               */
/***********************************/

/*File Gaurd*/
#ifndef IR_PRIVATE_H
#define IR_PRIVATE_H

void GPIO_IRPinIntiASOut(u8 Copy_u8PortId,u8 Copy_u8PinId);
void GPIO_IRPinIntiASINPUT(u8 Copy_u8PortId,u8 Copy_u8PinId);
void IR_SendTrain(u8 Copy_u8PortId,u8 Copy_u8PinId);
void IR_SendStartBit(u8 Copy_u8PortId,u8 Copy_u8PinId);
void IR_SendOneBit(u8 Copy_u8PortId,u8 Copy_u8PinId);
void IR_SendZeroBit(u8 Copy_u8PortId,u8 Copy_u8PinId);

#endif
