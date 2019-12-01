#ifndef __SCCB_H
#define __SCCB_H
#include "sys.h"

#define SCCB_SDA_IN()  {GPIOB->MODER&=~(3<<(1*2)); GPIOB->MODER|=0<<1*2;}		
#define SCCB_SDA_OUT() {GPIOB->MODER&=~(3<<(1*2)); GPIOB->MODER|=1<<1*2;} 	

#define SCCB_SCL    		PBout(8)	 	//SCL
#define SCCB_SDA    		PBout(9) 		//SDA	 

#define SCCB_READ_SDA   PBin(9)  		
#define SCCB_ID   			0x42  			

///////////////////////////////////////////
void SCCB_Init(void);
void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
u8 SCCB_WR_Byte(u8 dat);
u8 SCCB_RD_Byte(void);
u8 SCCB_WR_Reg(u8 reg, u8 data);
u16 SCCB_RD_Reg(u8 reg);
#endif













