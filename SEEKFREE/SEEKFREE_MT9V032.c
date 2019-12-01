/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @brief      		总钻风(灰度摄像头)历程
 * @company	   		成都逐飞科技有限公司
 * @author     		Go For It(1325536866)
 * @version    		v1.0
 * @Software 		MDK 5.17
 * @Target core		STM32F407ZGT6
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2017-10-11
 * @note
					OV7725接线定义：
					------------------------------------ 
					模块管脚            单片机管脚
					SDA                A2
					SCL                A3
					场中断              B7
					行中断              A4   
					像素中断            A6       
					
					D0                 C6
					D1                 C7
					D2                 C8
					D3                 C9
					D4                 C11
					D5                 B6
					D6                 E5
					D7                 E6
					
					------------------------------------ 
                    USB转TTL接线定义         
					USB转TTL引脚        单片机引脚
					TX                  A10
					RX                  A9
                        
					默认分辨率              查看SEEKFREE_MT9V032.h 文件内的宏定义 COL ROW
					默认FPS                 50帧
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


