/***********************************/
/* SWC:     BIT MATH Lib           */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    5 June 2024            */
/***********************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#define SET_REG(reg) 		((reg) =0xFF)
#define CLR_REG(reg) 		((reg) =0x00)
#define TOG_REG(reg) 		((reg) ^=0xFF)
#define GET_REG(reg)		(reg)
#define ASSIGN_REG(reg,vlue) ((reg)=vlue)

#define NULL (void*)0

#endif /*BIT_MATH_H_ */
