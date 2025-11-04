/***********************************/
/* SWC: STP Driver                 */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 18 June 2024              */
/***********************************/

/*File Gaurd*/
#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H
/*Interface Macros*/
#define STP_GPIOA           0
#define STP_GPIOB           1
#define STP_GPIOC           2

#define STP_PIN0            0 
#define STP_PIN1            1 
#define STP_PIN2            2 
#define STP_PIN3            3 
#define STP_PIN4            4 
#define STP_PIN5            5 
#define STP_PIN6            6 
#define STP_PIN7            7 
#define STP_PIN8            8 
#define STP_PIN9            9 
#define STP_PIN10           10
#define STP_PIN11           11
#define STP_PIN12           12
#define STP_PIN13           13
#define STP_PIN14           14
#define STP_PIN15           15

void STP_voidSend(u8 copy_u8PortId,u8 copy_DataInputPin,u8 copy_ShiftClockPin,u8 copy_StoreClockPin,u32 copy_Data);


#endif
