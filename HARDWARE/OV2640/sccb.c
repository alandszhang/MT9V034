#include "sys.h"
#include "sccb.h"
#include "delay.h"

void SCCB_Init(void)
{				
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	GPIO_SetBits(GPIOB, GPIO_Pin_8 | GPIO_Pin_9);
	SCCB_SDA_OUT();	   
	SCCB_Stop();
}

void delay_c(void)
{
    u32 t = 100;
    delay_us(t);
}

void SCCB_Start(void)
{
    SCCB_SDA = 1;     
    SCCB_SCL = 1;	   
    delay_c();  
    SCCB_SDA = 0;
    delay_c();	 
    SCCB_SCL = 0;	 
}

void SCCB_Stop(void)
{
    SCCB_SDA = 0;
    delay_c();	 
    SCCB_SCL = 1;	
    delay_c(); 
    SCCB_SDA = 1;	
    delay_c();
}  

void SCCB_No_Ack(void)
{
	delay_c();
	SCCB_SDA = 1;	
	SCCB_SCL = 1;	
	delay_c();
	SCCB_SCL = 0;	
	delay_c();
	SCCB_SDA = 0;	
	delay_c();
}

u8 SCCB_WR_Byte(u8 dat)
{
	u8 j,res;	 
	for(j = 0; j < 8; j++)
	{
		if(dat & 0x80)
			SCCB_SDA = 1;	
		else 
			SCCB_SDA = 0;
		dat<<=1;
		delay_c();
		SCCB_SCL = 1;	
		delay_c();
		SCCB_SCL = 0;		   
	}			 
	SCCB_SDA_IN();
	delay_c();
	SCCB_SCL = 1;
	delay_c();
	if(SCCB_READ_SDA)
		res = 1;
	else 
		res = 0;
	SCCB_SCL = 0;		 
	SCCB_SDA_OUT();
	return res;  
}	 

u8 SCCB_RD_Byte(void)
{
	u8 temp = 0, j;    
	SCCB_SDA_IN();	
	for(j = 8; j > 0; j--) 	
	{		     	  
		delay_c();
		SCCB_SCL = 1;
		temp = temp<<1;
		if(SCCB_READ_SDA)
			temp++;   
		delay_c();
		SCCB_SCL = 0;
	}	
	SCCB_SDA_OUT();	 
	return temp;
} 							    

u8 SCCB_WR_Reg(u8 reg, u8 data)
{
	u8 res = 0;
	SCCB_Start(); 					
	if(SCCB_WR_Byte(SCCB_ID))
		res = 1;	
	delay_us(100);
	if(SCCB_WR_Byte(reg))
		res = 1;			  
	delay_us(100);
	if(SCCB_WR_Byte(data))
		res = 1;
	SCCB_Stop();	  
	return res;
}		  					    

u16 SCCB_RD_Reg(u8 reg)
{
	u8 val = 0;
	SCCB_Start(); 			
	SCCB_WR_Byte(SCCB_ID);		
	delay_us(100);	 
	SCCB_WR_Byte(reg);		
	delay_us(100);	  
	SCCB_Stop();   
	delay_us(100);	   

	SCCB_Start();
	SCCB_WR_Byte(SCCB_ID | 0X01);	
	delay_us(100);
	val = SCCB_RD_Byte();		 
	SCCB_No_Ack();
	SCCB_Stop();
	return val;
}















