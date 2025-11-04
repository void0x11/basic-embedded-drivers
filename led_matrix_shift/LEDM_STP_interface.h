/***********************************/
/* SWC:     LEDM_STP Driver        */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    26 June 2024           */
/***********************************/

/*File Gaurd*/
#ifndef LEDM_STP_INTERFACE_H
#define LEDM_STP_INTERFACE_H


void LEDM_STP_voidini(void);
void LEDM_STP_voidDisplay(u8* Display_frame_data);
void LEDM_STP_voidDisplay_NAME(u8* Display_frame_data,u8 copy_u8size);


#endif
