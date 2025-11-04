/***********************************/
/* SWC:     LEDM_STP Driver        */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    26 June 2024           */
/***********************************/

/*File Gaurd*/
#ifndef LEDM_STP_PRIVATE_H
#define LEDM_STP_PRIVATE_H

void GPIO_LEDM_STPPinInti(u8 Copy_u8PortId,u8 Copy_u8PinId);
void LEDM_STP_voidSend(u16 copy_Data);

#endif