/***********************************/
/* SWC: USART Driver               */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 12 June 2024              */
/***********************************/

/*File Gaurd*/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H



/*e.g. Baud Rate= 9600*/
	/*Tx/Rx Baud = 16000000/(16*9600)= 1000000/9600 = 104.1875*/
	/*Convert it to a hex val. to be placed in BRR Reg==> 104=0x68, 0.1875*16= 0x3*/
//#define BAUDRATE     0x341
/*e.g. Baud Rate= 115200*/
#define BAUDRATE     0x8B

#endif
