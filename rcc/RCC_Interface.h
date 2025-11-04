/***********************************/
/* SWC:     RCC Driver             */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    11 June 2024           */
/***********************************/

/*File Gaurd*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*Functions Prototypes*/
void RCC_voidInitSysClk(void);  //Select System Clk
/*AHB1, AHB2, APB1, APB2*/
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
void RCC_voidDisablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);


#define AHB1             0
#define AHB2             1
#define APB1             2
#define APB2             3

#define HSE_CRYSTAL      0
#define HSE_RC           1
#define HSI              2
#define PLL              3


#endif
