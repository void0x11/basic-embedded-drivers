/*File Gaurd*/
#ifndef EXTI_PRIVATE_H

/***********************************/
/* SWC:     EXTI Driver            */
/* Author:  Ahmed Amin             */
/* File:    EXTI_private.h         */
/* Version: V1                     */
/* Date:    4 June 2024            */
/***********************************/

#define EXTI_PRIVATE_H
//EXTI Base address-> 0x40013C00
typedef struct 
{
volatile u32 EXTI_IMR;
volatile u32 EXTI_EMR;
volatile u32 EXTI_RTSR;
volatile u32 EXTI_FTSR;
volatile u32 EXTI_SWIER;
volatile u32 EXTI_PR;
}
EXTI_t;

//SYSCFG Base address-> 0x40013808
typedef struct 
{
    volatile u32 MEMRMP;
    volatile u32 PMC;
    volatile u32 EXTICR1;
    volatile u32 EXTICR2;
    volatile u32 EXTICR3;
    volatile u32 EXTICR4;
    volatile u32 CMPCR;
}SYSCFG_t;

#define SYSCFG  ((volatile SYSCFG_t*)0x40013800)


#define EXTI	((volatile EXTI_t*)0x40013C00)

#define EXTI0_Position      6
#define EXTI1_Position      7
#define EXTI2_Position      8
#define EXTI3_Position      9
#define EXTI4_Position      10
#define EXTI5_Position      23
#define EXTI6_Position      23
#define EXTI7_Position      23
#define EXTI8_Position      23
#define EXTI9_Position      23
#define EXTI10_Position     40
#define EXTI11_Position     40
#define EXTI12_Position     40
#define EXTI13_Position     40
#define EXTI14_Position     40
#define EXTI15_Position     40

#define EXTI_LINE_0             0
#define EXTI_LINE_1             1
#define EXTI_LINE_2             2
#define EXTI_LINE_3             3
#define EXTI_LINE_4             4
#define EXTI_LINE_5             5
#define EXTI_LINE_6             6
#define EXTI_LINE_7             7
#define EXTI_LINE_8             8
#define EXTI_LINE_9             9
#define EXTI_LINE_10            10
#define EXTI_LINE_11            11
#define EXTI_LINE_12            12
#define EXTI_LINE_13            13
#define EXTI_LINE_14            14
#define EXTI_LINE_15            15

/*Source Input for EXTIx*/
#define EXTI_PA                 0
#define EXTI_PB                 1
#define EXTI_PC                 2

#endif
