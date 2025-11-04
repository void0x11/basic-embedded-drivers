/***********************************/
/* SWC:     SEG7 Driver            */
/* Author:  Ahmed Amin 	           */
/* Version: V1                     */
/* Date:    5 June 2024            */
/***********************************/

/*File Gaurd*/
#ifndef SEG7_INTERFACE_H
#define SEG7_INTERFACE_H
/*display a number*/
#define seg_0 0b00111111
#define seg_1 0b00000110
#define seg_2 0b01011011
#define seg_3 0b01001111
#define seg_4 0b01100110
#define seg_5 0b01101101
#define seg_6 0b01111101
#define seg_7 0b00000111
#define seg_8 0b01111111
#define seg_9 0b01101111
#define seg_Space 0b00000000


#define SEG7_NUMBER_OF_DISPLAY	2

typedef struct Seg7_Display
{
    u8 SEG7_Pins [7];
    u8 SEG7_Ports[7];
}Seg7_Display;

#if(SEG7_NUMBER_OF_DISPLAY>=1)
	Seg7_Display SEG1;
#endif
#if(SEG7_NUMBER_OF_DISPLAY>=2)
	Seg7_Display SEG2;
#endif
#if(SEG7_NUMBER_OF_DISPLAY>=3)
	Seg7_Display SEG3;
#endif
#if(SEG7_NUMBER_OF_DISPLAY>=4)
	Seg7_Display SEG4;
#endif

/*Functions*/
void SEG7_voidinti ();
void SEG7_PrintOnSeg(Seg7_Display copy_Seg7Display,u8 copy_u8PrintData);


#endif
