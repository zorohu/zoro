#ifndef __HC05_H
#define __HC05_H	 
#include "stm32f10x.h" 
#include "string.h"
#include "usart.h"
#include "systick.h"
//////////////////////////////////////////////////////////////////////////////////	 
//							  
//********************************************************************************
								  
//////////////////////////////////////////////////////////////////////////////////   
 
u8 HC05_Init(void);
u8 HC05_Get_Role(void);
u8 HC05_Set_Cmd(u8* atstr);	   
#endif  
















