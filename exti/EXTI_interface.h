/***********************************/
/* SWC:     EXTI Driver            */
/* Author:  Ahmed Amin             */
/* File:    EXTI_interface.h       */
/* Version: V1                     */
/* Date:    4 June 2024            */
/***********************************/

/*File Gaurd*/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
void EXTI_VoidSetExtiLineEnable(u8 Copy_u8lineId);
void EXTI_VoidSetExtiLineDisable(u8 Copy_u8lineId);
void EXTI_voidSetEXTIpinConfig(u8 Copy_u8PortId, u8 Copy_u8LineId);
void EXTI_VoidSetSenseControl   (u8 Copy_u8lineId,u8 Copy_u8SenseControlId);

//PORTS IDs:
#define PORTA 0
#define PORTB 1
#define PORTC 2

//Sense Control Mode:
#define Rising_Edge     0
#define Falling_Edge    1
#define OnChage         2

#endif
