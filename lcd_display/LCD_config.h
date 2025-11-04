/***********************************/
/* SWC: LCD Driver                 */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 20 June 2024              */
/***********************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*Interface Macros*/
#define GPIOA           0
#define GPIOB           1
#define GPIOC           2

#define PIN0            0 
#define PIN1            1 
#define PIN2            2 
#define PIN3            3 
#define PIN4            4 
#define PIN5            5 
#define PIN6            6 
#define PIN7            7 
#define PIN8            8 
#define PIN9            9 
#define PIN10           10
#define PIN11           11
#define PIN12           12
#define PIN13           13
#define PIN14           14
#define PIN15           15

#define LCD_DATAPIN0  PIN0
#define LCD_DATAPIN1  PIN1
#define LCD_DATAPIN2  PIN2
#define LCD_DATAPIN3  PIN3
#define LCD_DATAPIN4  PIN4
#define LCD_DATAPIN5  PIN5
#define LCD_DATAPIN6  PIN6
#define LCD_DATAPIN7  PIN7

#define LCD_DATAPORTPIN0 GPIOA
#define LCD_DATAPORTPIN1 GPIOA
#define LCD_DATAPORTPIN2 GPIOA
#define LCD_DATAPORTPIN3 GPIOA
#define LCD_DATAPORTPIN4 GPIOA
#define LCD_DATAPORTPIN5 GPIOA
#define LCD_DATAPORTPIN6 GPIOA
#define LCD_DATAPORTPIN7 GPIOA

#define LCD_RSPORTPIN GPIOA
#define LCD_RWPORTPIN GPIOA
#define LCD_ENPORTPIN GPIOA

#define LCD_RSPIN  PIN15
#define LCD_RWPIN  PIN11
#define LCD_ENPIN  PIN12


#endif /* LCD_CONFIG_H_ */
