#ifndef __USART2_H
#define __USART2_H 
#include "sys.h"
#include "stdio.h"	  
//////////////////////////////////////////////////////////////////////////////////	   
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//����2��ʼ�� 
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/5/14
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved
//********************************************************************************
//�޸�˵��
//��
////////////////////////////////////////////////////////////////////////////////// 	
 
 #include "headfile.h"
 
 
void usart2_init(u32 pclk1,u32 bound); 
void put_char(USART_TypeDef* USARTx, u8 Data);

void uart_putbuff(USART_TypeDef* USARTx, u8 *p, u16 len);
void USART2_IRQHandler(void);                	//����1�жϷ������

#endif	   
















