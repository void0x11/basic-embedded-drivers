/***********************************/
/* SWC: IR Driver                  */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 9 June 2024               */
/***********************************/

/*File Gaurd*/
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

void IR_voidSend(u8 Copy_IRAdderss,u8 Copy_IRData);
u8 IR_voidReceive(u8 Copy_IRAdderss,u8 Copy_DataAdderss);
//void IR_inti(u8 copy_IRStates);


#endif
