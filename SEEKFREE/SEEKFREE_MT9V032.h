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
 
#ifndef _SEEKFREE_MT9V032_H
#define _SEEKFREE_MT9V032_H


#include "headfile.h"

#define COL 200
#define ROW 200

#define MT9V034_IDRegister									0x00
#define MT9V034_ColumnStart									0x01
#define MT9V034_RowStart										0x02
#define MT9V034_WindowHeight								0x03
#define MT9V034_WindowWidth									0x04
#define MT9V034_HorizontalBlanking					0x05
#define MT9V034_VerticalBlanking						0x06
#define MT9V034_CoarseShutterWidth1					0x08
#define MT9V034_CoarseShutterWidth2					0x09
#define MT9V034_CoarseShutterWidthControl		0x0A
#define MT9V034_CoarseShutterWidthTotal			0x0B
#define MT9V034_FineShutterWidth1						0xD3
#define MT9V034_FineShutterWidth2						0xD4
#define MT9V034_FineShutterWidthTotal				0xD5
#define MT9V034_ReadMode										0x0D
#define MT9V034_HighDynamicRangeEnable			0x0F
#define MT9V034_ADCResolutionControl				0x1C
#define MT9V034_V1Control										0x31
#define MT9V034_V2Control										0x32
#define MT9V034_V3Control										0x33
#define MT9V034_V4Control										0x34
#define MT9V034_AnalogGainControl						0x35
#define MT9V034_RowNoiseCorrectionControl1	0x70
#define MT9V034_TiledDigitalGain						0x80
#define MT9V034_AECorAGCEnable							0xAF
#define MT9V034_R0x20												0x20
#define MT9V034_R0x24												0x24
#define MT9V034_R0x2B												0x2B
#define MT9V034_R0x2F												0x2F

#define CONFIG_FINISH												12

extern __align(4) u8 mt9v032_finish_flag;  //一场图像采集完成标志位
extern u8 image[ROW][COL];      //内部使用

void mt9v034_init(void);
void mt9v034_sendimg(void);
u8	 mt9v034_reg_init(void);


#endif
