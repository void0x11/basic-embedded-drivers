/***********************************/
/* SWC: NVIC Driver                */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 30 May 2024               */
/***********************************/

/*File Gaurd*/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
//functio prototype
void NVIC_voidEnablePerInt      (u8 copy_u8IntId);
void NVIC_voidDisEnablePerInt   (u8 copy_u8IntId);
void NVIC_voidSetPendingFlag    (u8 copy_u8IntId);
void NVIC_voidClearPendingFlag  (u8 copy_u8IntId);
void NVIC_voidSetIntPriority(u8 Copy_IntId, u8 Copy_u8GroupId, u8 Copy_u8SubGroupId);
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriprityOption);
#define GROUP4BITS_SUBGROUP0BITS    011
#define GROUP3BITS_SUBGR1UP1BITS    100
#define GROUP2BITS_SUBGROUP2BITS    101
#define GROUP1BITS_SUBGROUP3BITS    110
#define GROUP0BITS_SUBGROUP4BITS    111
#endif
