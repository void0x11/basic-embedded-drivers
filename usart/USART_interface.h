/***********************************/
/* SWC: USART Driver               */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 12 June 2024              */
/***********************************/

/*File Gaurd*/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void USART_voidinti(void);
void USART_voidTransmit(u8* u8_TransmitedData);
void USART_voidReceive (u8* u8_ReceivedData);

#endif
