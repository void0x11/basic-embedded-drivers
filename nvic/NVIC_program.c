/***********************************/
/* SWC: NVIC Driver                */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 30 May 2024               */
/***********************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"
/*Functions Prototypes*/
static u8 StaticGlobal_u8PriorityConfig;

void NVIC_voidEnablePerInt      (u8 copy_u8IntId){
NVIC->ISER[copy_u8IntId/32]=(1<<(copy_u8IntId%32));
}
void NVIC_voidDisEnablePerInt   (u8 copy_u8IntId){
NVIC->ICER[copy_u8IntId/32]=(1<<(copy_u8IntId%32));
}
void NVIC_voidSetPendingFlag    (u8 copy_u8IntId){
NVIC->ISPR[copy_u8IntId/32]=(1<<(copy_u8IntId%32));
}
void NVIC_voidClearPendingFlag  (u8 copy_u8IntId){
NVIC->ICPR[copy_u8IntId/32]=(1<<(copy_u8IntId%32));
}
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriprityOption)
{
    SCB -> AIRCR =  VECT_KEY | (Copy_u8PriprityOption << 8);
    StaticGlobal_u8PriorityConfig = Copy_u8PriprityOption;
}
void NVIC_voidSetIntPriority(u8 Copy_IntId, u8 Copy_u8GroupId, u8 Copy_u8SubGroupId)
{
    u8 Local_u8Priority = Copy_u8SubGroupId | (Copy_u8GroupId << (StaticGlobal_u8PriorityConfig - 3));
    NVIC->IPR[Copy_IntId] = (Local_u8Priority<<4);
}
