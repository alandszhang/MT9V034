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

extern __align(4) u8 mt9v032_finish_flag;  //һ��ͼ��ɼ���ɱ�־λ
extern u8 image[ROW][COL];      //�ڲ�ʹ��

void mt9v034_init(void);
void mt9v034_sendimg(void);
u8	 mt9v034_reg_init(void);


#endif
