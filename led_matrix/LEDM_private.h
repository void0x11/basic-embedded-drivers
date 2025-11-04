/***********************************/
/* SWC:     LEDM Driver            */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    24 June 2024           */
/***********************************/

/*File Gaurd*/
#ifndef LEDM_PRIVATE_H
#define LEDM_PRIVATE_H

void GPIO_PinInti(u8 Copy_u8PortId,u8 Copy_u8PinId);
void Disable_Rows();
void Disable_Cloums();
void Send_ROWData(u8 copy_RowData);

#endif