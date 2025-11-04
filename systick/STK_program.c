/***********************************/
/* SWC: STK Driver                 */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 15 June 2024              */
/***********************************/

#include "../include/00-LIB/STD_TYPES.h"
#include "../include/00-LIB/BIT_MATH.h"
#include "STK_Interface.h"
#include "STK_Private.h"
#include "STK_Config.h"

//#define STK_CTRL  *((volatile u32*)0xE000E010)
//#define STK_LOAD  *((volatile u32*)0xE000E014)
//#define STK_VAL   *((volatile u32*)0xE000E018)
//#define STK_CALIB *((volatile u32*)0xE000E01C)

void(* Globle_voidPointerTofunction)(void)= NULL;
u8 Globle_single_Flag=0;
void STK_voidInit(){
    /*Disable timer*/
    CLR_BIT(STK_CTRL,0);
    /*Disable Int*/
    CLR_BIT(STK_CTRL,1);
    /*Select prescaler*/
    #if(CLKSOURCE==AHB_Div_8)
    CLR_BIT(STK_CTRL,2);
    #elif(CLKSOURCE==AHB)
    SET_BIT(STK_CTRL,2);
    #endif
}
void STK_voidSetBusyWait(u32 copy_u32NoOfCounts){
    /*Disable Int*/
    CLR_BIT(STK_CTRL,1);
    /*LOAD couter vlue*/
    STK_LOAD=0x00FFFFFF&copy_u32NoOfCounts;
    /*Einable timer*/
    SET_BIT(STK_CTRL,0);
    /*wait on flag*/
    while (!GET_BIT(STK_CTRL,16));
    STK_voidDisableTimer();
}

void STK_voidSetIntervalSingle(u32 copy_u32NoOfCounts,void(*LocalPointerTofunction)(void)){
    Globle_voidPointerTofunction=LocalPointerTofunction;
    /*Einable Int*/
    SET_BIT(STK_CTRL,1);
    /*LOAD couter vlue*/
    STK_LOAD=0x00FFFFFF&copy_u32NoOfCounts;
    /*Einable timer*/
    SET_BIT(STK_CTRL,0);
    //set Flag:
    Globle_single_Flag=1;
}
void STK_voidSetIntervalPeriodic(u32 copy_u32NoOfCounts,void(*LocalPointerTofunction)(void)){
    Globle_voidPointerTofunction=LocalPointerTofunction;
    /*Einable Int*/
    SET_BIT(STK_CTRL,1);
    /*LOAD couter vlue*/
    STK_LOAD=0x00FFFFFF&copy_u32NoOfCounts;
    /*Einable timer*/
    SET_BIT(STK_CTRL,0);
    //clear flag:
    Globle_single_Flag=0;
}
void STK_voidGetElapsedTime(u32 * U32ElapsedTime){
    U32ElapsedTime=STK_LOAD-STK_VAL;
}
void STK_voidGetRemainingTime(u32 U32RemainingTime){
    U32RemainingTime=STK_VAL;
}
void STK_voidDisableTimer(){
    /*Disable timer*/
    CLR_BIT(STK_CTRL,0);
    /*Disable Int*/
    CLR_BIT(STK_CTRL,1);
    /*Clr load*/
    STK_LOAD=0x00000000;
    /*Clr vlue*/
    STK_VAL=0x00000000;   
}
SysTick_Handler(){
    if(Globle_voidPointerTofunction!=NULL){
        Globle_voidPointerTofunction();
    }
    //CLear Interp Flag
    u8 Local_u8temp=GET_BIT(STK_CTRL,16);

    if(Globle_single_Flag==1){
    STK_voidDisableTimer();
    Globle_single_Flag=0;
    }
}
