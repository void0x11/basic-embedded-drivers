/***********************************/
/* SWC: STK Driver                 */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 15 June 2024              */
/***********************************/

/*File Gaurd*/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H
//functio prototype
void STK_voidInit();
void STK_voidSetBusyWait(u32 copy_u32NoOfCounts);
void STK_voidSetIntervalSingle(u32 copy_u32NoOfCounts,void(*LocalPointerTofunction)(void));
void STK_voidSetIntervalPeriodic(u32 copy_u32NoOfCounts,void(*LocalPointerTofunction)(void));
void STK_voidGetElapsedTime(u32 * U32ElapsedTime);
void STK_voidGetRemainingTime(u32 U32RemainingTime);
void STK_voidDisableTimer();

#endif