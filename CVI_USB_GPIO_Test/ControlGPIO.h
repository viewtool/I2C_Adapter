/**
  ******************************************************************************
  * @file    ControlGPIO.h
  * $Author: wdluo $
  * $Revision: 447 $
  * $Date:: 2013-06-29 18:24:57 +0800 #$
  * @brief   Ginkgo USB-GPIO�������ײ�������API��������.
  ******************************************************************************
  * @attention
  *
  *<h3><center>&copy; Copyright 2009-2012, ViewTool</center>
  *<center><a href="http:\\www.viewtool.com">http://www.viewtool.com</a></center>
  *<center>All Rights Reserved</center></h3>
  * 
  ******************************************************************************
  */
#ifndef _CONTROLGPIO_H_
#define _CONTROLGPIO_H_

#include <stdint.h>
#include "ErrorType.h"
#ifndef OS_LINUX
#include <Windows.h>
#endif

//���������Ͷ���
#define VGI_USBGPIO			(1)		//�豸����

//����GPIO������
#define	VGI_GPIO_PIN0		(1<<0)	//GPIO_0
#define	VGI_GPIO_PIN1		(1<<1)	//GPIO_1
#define	VGI_GPIO_PIN2		(1<<2)	//GPIO_2
#define	VGI_GPIO_PIN3		(1<<3)	//GPIO_3
#define	VGI_GPIO_PIN4		(1<<4)	//GPIO_4
#define	VGI_GPIO_PIN5		(1<<5)	//GPIO_5
#define	VGI_GPIO_PIN6		(1<<6)	//GPIO_6
#define	VGI_GPIO_PIN7		(1<<7)	//GPIO_7
#define	VGI_GPIO_PIN8		(1<<8)	//GPIO_8
#define	VGI_GPIO_PIN9		(1<<9)	//GPIO_9
#define	VGI_GPIO_PIN10		(1<<10)	//GPIO_10
#define	VGI_GPIO_PIN11		(1<<11)	//GPIO_11
#define	VGI_GPIO_PIN12		(1<<12)	//GPIO_12
#define	VGI_GPIO_PIN13		(1<<13)	//GPIO_13
#define	VGI_GPIO_PIN14		(1<<14)	//GPIO_14
#define	VGI_GPIO_PIN15		(1<<15)	//GPIO_15
#define	VGI_GPIO_PIN_ALL	(0xFFFF)//ALL PIN

//1.Ginkgoϵ�нӿڿ���Ϣ���������͡�
typedef  struct  _VGI_BOARD_INFO{
	uint16_t	dr_Version;			//��������汾�ţ���16 ���Ʊ�ʾ��
	uint16_t	in_Version;			//�ӿڿ�汾�ţ���16 ���Ʊ�ʾ��
	uint8_t		gpio_num;			//��ʾ�м�·SPI ͨ����
	char		str_hw_Name[100];	//Ӳ�����ƣ����硰Ginkgo-SPI-Adaptor����ע�⣺�����ַ�����������\0����
	char		str_fw_Version[100];//�̼��汾�ַ��������硰2.0.0����ע�⣺�����ַ�����������\0����
	char		str_hw_Version[100];//Ӳ���汾�ַ��������硰2.1.0����ע�⣺�����ַ�����������\0����
	char		str_Serial_Num[100];//���������к��ַ���
	uint16_t	Reserved[4];		//ϵͳ������
} VGI_BOARD_INFO,*PVGI_BOARD_INFO; 



#ifdef __cplusplus
extern "C"
{
#endif
int32_t WINAPI VGI_ScanDevice(uint8_t NeedInit);
int32_t WINAPI VGI_OpenDevice(int32_t DevType,int32_t DevIndex,int32_t Reserved);
int32_t WINAPI VGI_CloseDevice(int32_t DevType,int32_t DevIndex);
int32_t WINAPI VGI_ReadBoardInfo(int32_t DevType,int32_t DevIndex,PVGI_BOARD_INFO pInfo);
int32_t WINAPI VGI_InitGPIO(int32_t DevType, int32_t DevIndex, uint16_t PinMask, uint32_t PinMode);
int32_t WINAPI VGI_WriteDatas(int32_t DevType,int32_t DevIndex, uint16_t PinMask,uint16_t Data);
int32_t WINAPI VGI_ReadDatas(int32_t DevType,int32_t DevIndex,uint16_t PinMask,uint16_t *pData);

int32_t	WINAPI VGI_SetPins(int32_t DevType,int32_t DevIndex,uint16_t Pins);
int32_t	WINAPI VGI_ResetPins(int32_t DevType,int32_t DevIndex,uint16_t Pins);

int32_t	WINAPI VGI_SetInput(int32_t DevType,int32_t DevIndex,uint16_t Pins);
int32_t	WINAPI VGI_SetOutput(int32_t DevType,int32_t DevIndex,uint16_t Pins);
int32_t	WINAPI VGI_SetOpenDrain(int32_t DevType,int32_t DevIndex,uint16_t Pins);

#ifdef __cplusplus
}
#endif


#endif
