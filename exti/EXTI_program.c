/***********************************/
/* SWC:     EXTI Driver            */
/* Author:  Ahmed Amin             */
/* File:    EXTI_program.c         */
/* Version: V1                     */
/* Date:    4 June 2024            */
/***********************************/

#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "../include/NVIC_interface.h"


void EXTI_VoidSetExtiLineEnable(u8 Copy_u8lineId){
    switch (Copy_u8lineId)
    {
    case 0:
        NVIC_voidEnablePerInt(EXTI0_Position);
        break;
    case 1:
        NVIC_voidEnablePerInt(EXTI1_Position);
        break;
    case 2:
        NVIC_voidEnablePerInt(EXTI2_Position);
        break;
    case 3:
        NVIC_voidEnablePerInt(EXTI3_Position);
        break;
    case 4:
        NVIC_voidEnablePerInt(EXTI4_Position);
        break;
    case 5:
        NVIC_voidEnablePerInt(EXTI5_Position);
        break;
    case 6:
        NVIC_voidEnablePerInt(EXTI6_Position);
        break;
    case 7:
        NVIC_voidEnablePerInt(EXTI7_Position);
        break;
    case 8:
        NVIC_voidEnablePerInt(EXTI8_Position);
        break;
    case 9:
        NVIC_voidEnablePerInt(EXTI9_Position);
        break;
    case 10:
        NVIC_voidEnablePerInt(EXTI10_Position);
        break;
    case 11:
        NVIC_voidEnablePerInt(EXTI11_Position);
        break;
    case 12:
        NVIC_voidEnablePerInt(EXTI12_Position);
        break;
    case 13:
        NVIC_voidEnablePerInt(EXTI13_Position);
        break;
    case 14:
        NVIC_voidEnablePerInt(EXTI14_Position);
        break;
    case 15:
        NVIC_voidEnablePerInt(EXTI15_Position);
        break;
    default:
        break;
    }
    SET_BIT(EXTI->EXTI_IMR,Copy_u8lineId);
}

void EXTI_VoidSetExtiLineDisable(u8 Copy_u8lineId){
switch (Copy_u8lineId)
    {
    case 0:
        NVIC_voidDisEnablePerInt(EXTI0_Position);
        break;
    case 1:
        NVIC_voidDisEnablePerInt(EXTI1_Position);
        break;
    case 2:
        NVIC_voidDisEnablePerInt(EXTI2_Position);
        break;
    case 3:
        NVIC_voidDisEnablePerInt(EXTI3_Position);
        break;
    case 4:
        NVIC_voidDisEnablePerInt(EXTI4_Position);
        break;
    case 5:
        NVIC_voidDisEnablePerInt(EXTI5_Position);
        break;
    case 6:
        NVIC_voidDisEnablePerInt(EXTI6_Position);
        break;
    case 7:
        NVIC_voidDisEnablePerInt(EXTI7_Position);
        break;
    case 8:
        NVIC_voidDisEnablePerInt(EXTI8_Position);
        break;
    case 9:
        NVIC_voidDisEnablePerInt(EXTI9_Position);
        break;
    case 10:
        NVIC_voidDisEnablePerInt(EXTI10_Position);
        break;
    case 11:
        NVIC_voidDisEnablePerInt(EXTI11_Position);
        break;
    case 12:
        NVIC_voidDisEnablePerInt(EXTI12_Position);
        break;
    case 13:
        NVIC_voidDisEnablePerInt(EXTI13_Position);
        break;
    case 14:
        NVIC_voidDisEnablePerInt(EXTI14_Position);
        break;
    case 15:
        NVIC_voidDisEnablePerInt(EXTI15_Position);
        break;
    default:
        break;
    }
	CLR_BIT(EXTI->EXTI_IMR,Copy_u8lineId);
}

void EXTI_voidSetEXTIpinConfig(u8 Copy_u8PortId, u8 Copy_u8LineId)
{
	if(Copy_u8LineId <= EXTI_LINE_3)
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR1 = ((0b0000) << (Copy_u8LineId*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR1 = ((0b0001) << (Copy_u8LineId*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR1 = ((0b0010) << (Copy_u8LineId*4));
							break;
			default:		break;
		}
	}
	else if (Copy_u8LineId <= EXTI_LINE_7)
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR2 = ((0b0000) << ((Copy_u8LineId-4)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR2 = ((0b0001) << ((Copy_u8LineId-4)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR2 = ((0b0010) << ((Copy_u8LineId-4)*4));
							break;
			default:		break;
		}
	}
	else if (Copy_u8LineId <= EXTI_LINE_11)
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR3 = ((0b0000) << ((Copy_u8LineId-8)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR3 = ((0b0001) << ((Copy_u8LineId-8)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR3 = ((0b0010) << ((Copy_u8LineId-8)*4));
							break;
			default:		break;
		}
	}
	else
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR4 = ((0b0000) << ((Copy_u8LineId-12)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR4 = ((0b0001) << ((Copy_u8LineId-12)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR4 = ((0b0010) << ((Copy_u8LineId-12)*4));
							break;
			default:		break;
		}
	}
}

void EXTI_VoidSetSenseControl   (u8 Copy_u8lineId,u8 Copy_u8SenseControlId){
switch (Copy_u8SenseControlId)
{
case Rising_Edge:
    CLR_BIT(EXTI->EXTI_FTSR,Copy_u8lineId);
    SET_BIT(EXTI->EXTI_RTSR,Copy_u8lineId);
    break;
case Falling_Edge:
    SET_BIT(EXTI->EXTI_FTSR,Copy_u8lineId);
    CLR_BIT(EXTI->EXTI_RTSR,Copy_u8lineId);
    break;
case OnChage:
    SET_BIT(EXTI->EXTI_FTSR,Copy_u8lineId);
    SET_BIT(EXTI->EXTI_RTSR,Copy_u8lineId);
    break;
default:
    break;
}
}
