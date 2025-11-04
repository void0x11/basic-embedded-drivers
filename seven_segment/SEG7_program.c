/***********************************/
/* SWC:     SEG7 Driver            */
/* Author:  Ahmed Amin             */
/* Version: V1                     */
/* Date:    5 June 2024            */
/***********************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "SEG7_Interface.h"
#include "SEG7_Private.h"
#include "SEG7_Config.h"
#include "GPIO_interface.h"
#include "NVIC_Interface.h"


void SEG7_voidinti  (){
	u8 local_u8counter;
	#if(SEG7_NUMBER_OF_DISPLAY>=1)
		SEG1.SEG7_Pins[0]=SEG7_SEG1_PINC0;
		SEG1.SEG7_Pins[1]=SEG7_SEG1_PINC1;
		SEG1.SEG7_Pins[2]=SEG7_SEG1_PINC2;
		SEG1.SEG7_Pins[3]=SEG7_SEG1_PINC3;
		SEG1.SEG7_Pins[4]=SEG7_SEG1_PINC4;
		SEG1.SEG7_Pins[5]=SEG7_SEG1_PINC5;
		SEG1.SEG7_Pins[6]=SEG7_SEG1_PINC6;

		SEG1.SEG7_Ports[0]=SEG7_SEG1_PORT0;
		SEG1.SEG7_Ports[1]=SEG7_SEG1_PORT1;
		SEG1.SEG7_Ports[2]=SEG7_SEG1_PORT2;
		SEG1.SEG7_Ports[3]=SEG7_SEG1_PORT3;
		SEG1.SEG7_Ports[4]=SEG7_SEG1_PORT4;
		SEG1.SEG7_Ports[5]=SEG7_SEG1_PORT5;
		SEG1.SEG7_Ports[6]=SEG7_SEG1_PORT6;
	    for(local_u8counter=0;local_u8counter<7;local_u8counter++){
	        GPIO_Pininti(SEG1.SEG7_Ports[local_u8counter],SEG1.SEG7_Pins[local_u8counter]);
	    }
	    SEG7_PrintOnSeg(SEG1,seg_Space);
	#endif
	#if(SEG7_NUMBER_OF_DISPLAY>=2)
		SEG2.SEG7_Pins[0]=SEG7_SEG2_PINC0;
		SEG2.SEG7_Pins[1]=SEG7_SEG2_PINC1;
		SEG2.SEG7_Pins[2]=SEG7_SEG2_PINC2;
		SEG2.SEG7_Pins[3]=SEG7_SEG2_PINC3;
		SEG2.SEG7_Pins[4]=SEG7_SEG2_PINC4;
		SEG2.SEG7_Pins[5]=SEG7_SEG2_PINC5;
		SEG2.SEG7_Pins[6]=SEG7_SEG2_PINC6;

		SEG2.SEG7_Ports[0]=SEG7_SEG2_PORT0;
		SEG2.SEG7_Ports[1]=SEG7_SEG2_PORT1;
		SEG2.SEG7_Ports[2]=SEG7_SEG2_PORT2;
		SEG2.SEG7_Ports[3]=SEG7_SEG2_PORT3;
		SEG2.SEG7_Ports[4]=SEG7_SEG2_PORT4;
		SEG2.SEG7_Ports[5]=SEG7_SEG2_PORT5;
		SEG2.SEG7_Ports[6]=SEG7_SEG2_PORT6;
	    for(local_u8counter=0;local_u8counter<7;local_u8counter++){
	        GPIO_Pininti(SEG2.SEG7_Ports[local_u8counter],SEG2.SEG7_Pins[local_u8counter]);
	    }
	    SEG7_PrintOnSeg(SEG2,seg_Space);
	#endif
	#if(SEG7_NUMBER_OF_DISPLAY>=3)
			SEG3.SEG7_Pins[0]=SEG7_SEG3_PINC0;
			SEG3.SEG7_Pins[1]=SEG7_SEG3_PINC1;
			SEG3.SEG7_Pins[2]=SEG7_SEG3_PINC2;
			SEG3.SEG7_Pins[3]=SEG7_SEG3_PINC3;
			SEG3.SEG7_Pins[4]=SEG7_SEG3_PINC4;
			SEG3.SEG7_Pins[5]=SEG7_SEG3_PINC5;
			SEG3.SEG7_Pins[6]=SEG7_SEG3_PINC6;

			SEG3.SEG7_Ports[0]=SEG7_SEG3_PORT0;
			SEG3.SEG7_Ports[1]=SEG7_SEG3_PORT1;
			SEG3.SEG7_Ports[2]=SEG7_SEG3_PORT2;
			SEG3.SEG7_Ports[3]=SEG7_SEG3_PORT3;
			SEG3.SEG7_Ports[4]=SEG7_SEG3_PORT4;
			SEG3.SEG7_Ports[5]=SEG7_SEG3_PORT5;
			SEG3.SEG7_Ports[6]=SEG7_SEG3_PORT6;
		    for(local_u8counter=0;local_u8counter<7;local_u8counter++){
		    	 GPIO_Pininti(SEG3.SEG7_Ports[local_u8counter],SEG3.SEG7_Pins[local_u8counter]);
		    }
		    SEG7_PrintOnSeg(SEG3,seg_Space);
	#endif
	#if(SEG7_NUMBER_OF_DISPLAY>=4)
			SEG4.SEG7_Pins[0]=SEG7_SEG4_PINC0;
			SEG4.SEG7_Pins[1]=SEG7_SEG4_PINC1;
			SEG4.SEG7_Pins[2]=SEG7_SEG4_PINC2;
			SEG4.SEG7_Pins[3]=SEG7_SEG4_PINC3;
			SEG4.SEG7_Pins[4]=SEG7_SEG4_PINC4;
			SEG4.SEG7_Pins[5]=SEG7_SEG4_PINC5;
			SEG4.SEG7_Pins[6]=SEG7_SEG4_PINC6;

			SEG4.SEG7_Ports[0]=SEG7_SEG4_PORT0;
			SEG4.SEG7_Ports[1]=SEG7_SEG4_PORT1;
			SEG4.SEG7_Ports[2]=SEG7_SEG4_PORT2;
			SEG4.SEG7_Ports[3]=SEG7_SEG4_PORT3;
			SEG4.SEG7_Ports[4]=SEG7_SEG4_PORT4;
			SEG4.SEG7_Ports[5]=SEG7_SEG4_PORT5;
			SEG4.SEG7_Ports[6]=SEG7_SEG4_PORT6;
		    for(local_u8counter=0;local_u8counter<7;local_u8counter++){
		    	GPIO_Pininti(SEG4.SEG7_Ports[local_u8counter],SEG4.SEG7_Pins[local_u8counter]);
		    }
		    SEG7_PrintOnSeg(SEG4,seg_Space);
	#endif

}
void SEG7_PrintOnSeg(Seg7_Display copy_Seg7Display,u8 copy_u8PrintData){
    u8 local_u8counter;
    for(local_u8counter=0;local_u8counter<7;local_u8counter++){
        GPIO_voidSetPinValueDirectAccess(copy_Seg7Display.SEG7_Ports[local_u8counter],copy_Seg7Display.SEG7_Pins[local_u8counter],GET_BIT(copy_u8PrintData,local_u8counter));
    }
}

void GPIO_Pininti(u8 Copy_u8PortId,u8 Copy_u8PinId){
        GPIO_voidSetPinMode (Copy_u8PortId, Copy_u8PinId,OUTPUT);
        GPIO_voidSetPinType (Copy_u8PortId, Copy_u8PinId,OUTPUT_PP);
        GPIO_voidSetPinSpeed(Copy_u8PortId,Copy_u8PinId ,OUTPUT_LS);
}
