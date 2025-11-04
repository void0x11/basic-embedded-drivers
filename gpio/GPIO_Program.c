/***********************************/
/* SWC: GPIO Driver                */
/* Author: Ahmed Amin              */
/* Version: V1                     */
/* Date: 30 May 2024               */
/***********************************/

#include "../include/00-LIB/STD_TYPES.h"
#include "../include/00-LIB/BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"


/****************************************************************/
/* Func. Name: GPIO_voidSetPinMode                              */
/* I/P Arg. Options: Copy_u8PortId: GPIOA, GPIOB,      GPIOC    */
/* I/P Arg. Options: Copy_u8PinId: PIN0 --> PIN15, PIN13-->PIN15*/
/* I/P Arg. Options: Copy_u8Mode: INPUT, OUTPUT, AF, ANALOG     */
/* Return: Nothing                                              */
/* Func. Desc.: This Func. sets the mode of a specific pin      */
/****************************************************************/
void GPIO_voidConfigureAlterFun(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8AlterFunNumber){
	/*i/p validation*/
		if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15) || (Copy_u8AlterFunNumber > AF15))
		{
			/*Do Nothing*/
		}
		else
		{
			if(Copy_u8PinId <= PIN7)
			{
				switch(Copy_u8PortId)
				{
					case GPIOA:	GPIOA_AFRL |= (Copy_u8AlterFunNumber << (Copy_u8PinId*4));
								break;
					case GPIOB:	GPIOB_AFRL |= (Copy_u8AlterFunNumber << (Copy_u8PinId*4));
								break;
					case GPIOC:	GPIOC_AFRL |= (Copy_u8AlterFunNumber << (Copy_u8PinId*4));
								break;
					default:
								break;
				}
			}
			else
			{
				switch(Copy_u8PortId)
				{
					case GPIOA:	GPIOA_AFRH |= (Copy_u8AlterFunNumber << ((Copy_u8PinId % 8)*4));
								break;
					case GPIOB:	GPIOB_AFRH |= (Copy_u8AlterFunNumber << ((Copy_u8PinId % 8)*4));
								break;
					case GPIOC:	GPIOC_AFRH |= (Copy_u8AlterFunNumber << ((Copy_u8PinId % 8)*4));
								break;
					default:
								break;
				}
			}
		}
}
void GPIO_voidSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Mode)
{
    /*I/P Validation*/
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15) || (Copy_u8Mode > ANALOG))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8Mode)
        {
            case INPUT: switch(Copy_u8PortId)
                        {
                            case GPIOA: CLR_BIT(GPIOA_MODER, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOA_MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case GPIOB: CLR_BIT(GPIOB_MODER, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOB_MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case GPIOC: CLR_BIT(GPIOC_MODER, (Copy_u8PinId*2));
                                        CLR_BIT(GPIOC_MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            default:
                                        break;
                        }
                        break;
            case OUTPUT: switch(Copy_u8PortId)
                         {
                             case GPIOA: SET_BIT(GPIOA_MODER, (Copy_u8PinId*2));
                                         CLR_BIT(GPIOA_MODER, ((Copy_u8PinId*2)+1));
                                         break;
                             case GPIOB: SET_BIT(GPIOB_MODER, (Copy_u8PinId*2));
                                         CLR_BIT(GPIOB_MODER, ((Copy_u8PinId*2)+1));
                                         break;
                             case GPIOC: SET_BIT(GPIOC_MODER, (Copy_u8PinId*2));
                                         CLR_BIT(GPIOC_MODER, ((Copy_u8PinId*2)+1));
                                         break;
                             default:
                                         break;
                         }
                         break;
            case AF:    switch(Copy_u8PortId)
                        {
                            case GPIOA: CLR_BIT(GPIOA_MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOA_MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case GPIOB: CLR_BIT(GPIOB_MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOB_MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case GPIOC: CLR_BIT(GPIOC_MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOC_MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            default:
                                        break;
                        }
                        break;
            case ANALOG:switch(Copy_u8PortId)
                        {
                            case GPIOA: SET_BIT(GPIOA_MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOA_MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case GPIOB: SET_BIT(GPIOB_MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOB_MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            case GPIOC: SET_BIT(GPIOC_MODER, (Copy_u8PinId*2));
                                        SET_BIT(GPIOC_MODER, ((Copy_u8PinId*2)+1));
                                        break;
                            default:
                                        break;
                        }
                        break;
            default:    
                        break;
        }
    }
}

/*Copy_u8Type: OUTPUT_PP, OUTPUT_OD*/
void GPIO_voidSetPinType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Type)
{
    /*I/P Validation*/
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15) || (Copy_u8Type > OUTPUT_OD))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8Type)
        {
            case OUTPUT_PP: switch(Copy_u8PortId)
                            {
                                case GPIOA: CLR_BIT(GPIOA_TYPER, Copy_u8PinId);
                                            break;
                                case GPIOB: CLR_BIT(GPIOB_TYPER, Copy_u8PinId);
                                            break;
                                case GPIOC: CLR_BIT(GPIOB_TYPER, Copy_u8PinId);
                                            break;
                                default:
                                            break;
                            }
                            break;
            case OUTPUT_OD: switch(Copy_u8PortId)
                            {
                                case GPIOA: SET_BIT(GPIOA_TYPER, Copy_u8PinId);
                                            break;
                                case GPIOB: SET_BIT(GPIOB_TYPER, Copy_u8PinId);
                                            break;
                                case GPIOC: SET_BIT(GPIOB_TYPER, Copy_u8PinId);
                                            break;
                                default:
                                            break;
                            }
                            break;
            default:        break;
        }
    }
}

/*Copy_u8Speed: OUTPUT_LS, OUTPUT_MS, OUTPUT_HS*/
void GPIO_voidSetPinSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Speed)
{
    /*I/P Validation*/
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15) || (Copy_u8Speed > OUTPUT_HS))
    {
        /*Do Nothing*/
    }
    else
    {
        switch(Copy_u8Speed)
        {
            case OUTPUT_LS: switch(Copy_u8PortId)
							{
									case GPIOA: CLR_BIT(GPIOA_SPEEDR, (Copy_u8PinId*2));
												CLR_BIT(GPIOA_SPEEDR, ((Copy_u8PinId*2)+1));
												break;
									case GPIOB: CLR_BIT(GPIOB_SPEEDR, (Copy_u8PinId*2));
												CLR_BIT(GPIOB_SPEEDR, ((Copy_u8PinId*2)+1));
												break;
									case GPIOC: CLR_BIT(GPIOC_SPEEDR, (Copy_u8PinId*2));
												CLR_BIT(GPIOC_SPEEDR, ((Copy_u8PinId*2)+1));
												break;
									default:    break;
							}
							break;
            case OUTPUT_MS: switch(Copy_u8PortId)
							 {
								 case GPIOA:    SET_BIT(GPIOA_SPEEDR, (Copy_u8PinId*2));
												CLR_BIT(GPIOA_SPEEDR, ((Copy_u8PinId*2)+1));
												break;
									case GPIOB: SET_BIT(GPIOB_SPEEDR, (Copy_u8PinId*2));
												CLR_BIT(GPIOB_SPEEDR, ((Copy_u8PinId*2)+1));
												break;
									case GPIOC: SET_BIT(GPIOC_SPEEDR, (Copy_u8PinId*2));
												CLR_BIT(GPIOC_SPEEDR, ((Copy_u8PinId*2)+1));
												break;
									default:    break;
							 }
							 break;
            case OUTPUT_HS:     switch(Copy_u8PortId)
								{
										case GPIOA: CLR_BIT(GPIOA_SPEEDR, (Copy_u8PinId*2));
													SET_BIT(GPIOA_SPEEDR, ((Copy_u8PinId*2)+1));
													break;
										case GPIOB: CLR_BIT(GPIOB_SPEEDR, (Copy_u8PinId*2));
													SET_BIT(GPIOB_SPEEDR, ((Copy_u8PinId*2)+1));
													break;
										case GPIOC: CLR_BIT(GPIOC_SPEEDR, (Copy_u8PinId*2));
													SET_BIT(GPIOC_SPEEDR, ((Copy_u8PinId*2)+1));
													break;
										default:    break;
								}
								break;
            default:    
                        break;
        }
    }
}

/*Copy_u8PuPdOption: INPUT_FLOATING, INPUT_PU, INPUT_PD*/
void GPIO_voidSetPinPUPDOption(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PuPdOption)
{
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15) || (Copy_u8PuPdOption > INPUT_PD))
    {

    }
    else
    {
    	switch(Copy_u8PuPdOption)
    	{
    	case INPUT_FLOATING:switch(Copy_u8PortId)
							{
								case GPIOA:	CLR_BIT(GPIOA_PUPDR, (Copy_u8PinId*2));
											CLR_BIT(GPIOA_PUPDR, ((Copy_u8PinId*2)+1));
											break;
								case GPIOB:	CLR_BIT(GPIOB_PUPDR, (Copy_u8PinId*2));
											CLR_BIT(GPIOB_PUPDR, ((Copy_u8PinId*2)+1));
											break;
								case GPIOC:	CLR_BIT(GPIOC_PUPDR, (Copy_u8PinId*2));
											CLR_BIT(GPIOC_PUPDR, ((Copy_u8PinId*2)+1));
											break;
								default:
											break;
							}
    						break;
    	case INPUT_PU:		switch(Copy_u8PortId)
							{
								case GPIOA:	SET_BIT(GPIOA_PUPDR, (Copy_u8PinId*2));
											CLR_BIT(GPIOA_PUPDR, ((Copy_u8PinId*2)+1));
											break;
								case GPIOB:	SET_BIT(GPIOB_PUPDR, (Copy_u8PinId*2));
											CLR_BIT(GPIOB_PUPDR, ((Copy_u8PinId*2)+1));
											break;
								case GPIOC:	SET_BIT(GPIOC_PUPDR, (Copy_u8PinId*2));
											CLR_BIT(GPIOC_PUPDR, ((Copy_u8PinId*2)+1));
											break;
								default:
											break;
							}
    						break;
    	case INPUT_PD:switch(Copy_u8PortId)
						{
							case GPIOA:	CLR_BIT(GPIOA_PUPDR, (Copy_u8PinId*2));
										SET_BIT(GPIOA_PUPDR, ((Copy_u8PinId*2)+1));
										break;
							case GPIOB:	CLR_BIT(GPIOB_PUPDR, (Copy_u8PinId*2));
										SET_BIT(GPIOB_PUPDR, ((Copy_u8PinId*2)+1));
										break;
							case GPIOC:	CLR_BIT(GPIOC_PUPDR, (Copy_u8PinId*2));
										SET_BIT(GPIOC_PUPDR, ((Copy_u8PinId*2)+1));
										break;
							default:
										break;
						}
    						break;
    	default:            break;
    	}
    }
}

void GPIO_voidSetPortValue(u8 Copy_u8PortId, u32 Copy_u32Value)
{
	/*I/P Validation*/
	if((Copy_u8PortId > GPIOC))
	{

	}
	else
	{
		switch(Copy_u8PortId)
		{
			case GPIOA:	GPIOA_ODR = Copy_u32Value;
						break;
			case GPIOB:	GPIOB_ODR = Copy_u32Value;
						break;
			case GPIOC:	GPIOC_ODR = Copy_u32Value;
						break;
			default:
						break;
		}
	}
}

/*Copy_u8Signal: PIN_SET, PIN_RST*/
void GPIO_voidSetPinValueDirectAccess(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Signal)
{
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15) || (Copy_u8Signal > PIN_SET))
    {

    }
    else
    {
    	switch(Copy_u8Signal)
    	{
    		case PIN_SET:	switch(Copy_u8PortId)
							{
    							case GPIOA:	GPIOA_BSRR = (1 << Copy_u8PinId);
    										break;
    							case GPIOB: GPIOB_BSRR = (1 << Copy_u8PinId);
    							    		break;
    							case GPIOC:	GPIOC_BSRR = (1 << Copy_u8PinId);
    							    		break;
							}
    						break;
    		case PIN_RST:	switch(Copy_u8PortId)
							{
								case GPIOA:	GPIOA_BSRR = (1 << (Copy_u8PinId+16));
											break;
								case GPIOB: GPIOB_BSRR = (1 << (Copy_u8PinId+16));
											break;
								case GPIOC:	GPIOC_BSRR = (1 << (Copy_u8PinId+16));
											break;
							}
    						break;
    	}
    }
}

u8   GPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 Local_u8PinValue = 0;
	if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15))
	{

	}
	else
	{
		switch(Copy_u8PortId)
		{
			case GPIOA:	Local_u8PinValue = GET_BIT(GPIOA_IDR,Copy_u8PinId);
						break;
			case GPIOB: Local_u8PinValue = GET_BIT(GPIOB_IDR,Copy_u8PinId);
						break;
			case GPIOC:	Local_u8PinValue = GET_BIT(GPIOC_IDR,Copy_u8PinId);
						break;
		}
	}
	return Local_u8PinValue;
}
