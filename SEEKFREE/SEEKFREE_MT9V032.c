/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @brief      		�����(�Ҷ�����ͷ)����
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		Go For It(1325536866)
 * @version    		v1.0
 * @Software 		MDK 5.17
 * @Target core		STM32F407ZGT6
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2017-10-11
 * @note
					OV7725���߶��壺
					------------------------------------ 
					ģ��ܽ�            ��Ƭ���ܽ�
					SDA                A2
					SCL                A3
					���ж�              B7
					���ж�              A4   
					�����ж�            A6       
					
					D0                 C6
					D1                 C7
					D2                 C8
					D3                 C9
					D4                 C11
					D5                 B6
					D6                 E5
					D7                 E6
					
					------------------------------------ 
                    USBתTTL���߶���         
					USBתTTL����        ��Ƭ������
					TX                  A10
					RX                  A9
                        
					Ĭ�Ϸֱ���              �鿴SEEKFREE_MT9V032.h �ļ��ڵĺ궨�� COL ROW
					Ĭ��FPS                 50֡
 ********************************************************************************************************************/
#include "SEEKFREE_MT9V032.h"

u8 image[ROW][COL];

__align(4) u8 image[ROW][COL];

s16 MT9V034_CFG[CONFIG_FINISH][2]=
{
	{MT9V034_WindowHeight,				200},
	{MT9V034_WindowWidth,         200},
	{MT9V034_HorizontalBlanking,  846 - 200},
	{MT9V034_VerticalBlanking,    525 - 200},
	{MT9V034_ColumnStart,         (752 - 200) / 2 + 1},
	{MT9V034_RowStart,         		(480 - 200) / 2 + 1},
	{0x07,         								(1 << 3) | (1 << 7) | (1 << 8)},
	{MT9V034_ReadMode,            0x0300},
	{MT9V034_AECorAGCEnable,			(1 << 0) | (1 << 1)},
	{MT9V034_R0x20,								0x03C7},
	{MT9V034_R0x2B,								0x0003},
	{MT9V034_R0x2F,								0x0003}
};

void get_config(void)
{

}

u16 set_exposure_time(u16 light)
{
	return 0;
}

void mt9v034_init(void)
{    
	SCCB_Init();
	while(mt9v034_reg_init()){}
	dcmi_init();
	dcmi_dma_init((u32)image, COL*ROW/2/4, DMA_MemoryDataSize_Word, DMA_MemoryInc_Enable);
}

u8 mt9v034_reg_init(void)
{
	u16 i;
	
	if(SCCB_RD_Reg(MT9V034_IDRegister) != 0x1313)
	{
		return 0;
	}
	else
	{
		for (i = 0; i < CONFIG_FINISH; i++)
		{
			SCCB_WR_Reg(MT9V034_CFG[i][0], MT9V034_CFG[i][1]);
		}
		return 1;
	}
}

void mt9v034_sendimg(void)
{
	put_char(USART1, 0x00);
	put_char(USART1, 0xff);
	put_char(USART1, 0x01);
	put_char(USART1, 0x01);
	uart_putbuff(USART1, (uint8_t *)image, ROW*COL);
}


