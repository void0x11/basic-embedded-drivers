/***********************************/
/* SWC: STK Driver                 */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 15 June 2024              */
/***********************************/

/*File Gaurd*/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_CTRL  *((volatile u32*)0xE000E010)
#define STK_LOAD  *((volatile u32*)0xE000E014)
#define STK_VAL   *((volatile u32*)0xE000E018)
#define STK_CALIB *((volatile u32*)0xE000E01C)


#endif