/**
  ******************************************************************************
  * @file    ControlADC.h
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
#ifndef _CONTROLADC_H_
#define _CONTROLADC_H_

#include <stdint.h>
#include "ErrorType.h"
#ifndef OS_UNIX
#include <Windows.h>

#else
#ifndef WINAPI

#define WINAPI
#endif
#endif

//���������Ͷ���
#define VAI_USBADC		(1)		//�豸����

//����ADCͨ��
#define	VAI_ADC_CH0		(1<<0)	//ADC_CH0
#define	VAI_ADC_CH1		(1<<1)	//ADC_CH1
#define	VAI_ADC_CH2		(1<<2)	//ADC_CH2
#define	VAI_ADC_CH3		(1<<3)	//ADC_CH3
#define	VAI_ADC_CH4		(1<<4)	//ADC_CH4
#define	VAI_ADC_CH5		(1<<5)	//ADC_CH5
#define	VAI_ADC_CH6		(1<<6)	//ADC_CH6
#define	VAI_ADC_CH7		(1<<7)	//ADC_CH7
#define	VAI_ADC_ALL		(0xFF)	//ADC_CH_ALL

//1.Ginkgoϵ�нӿڿ���Ϣ���������͡�
typedef  struct  _VAI_BOARD_INFO{
	uint8_t		ProductName[32];	//Ӳ�����ƣ����硰Ginkgo-SPI-Adaptor����ע�⣺�����ַ�����������\0����
	uint8_t		FirmwareVersion[4];	//�̼��汾
	uint8_t		HardwareVersion[4];	//Ӳ���汾
	uint8_t		SerialNumber[12];	//���������к�
} VAI_BOARD_INFO,*PVAI_BOARD_INFO;



#ifdef __cplusplus
extern "C"
{
#endif
int32_t WINAPI VAI_ScanDevice(uint8_t NeedInit=1);
int32_t WINAPI VAI_OpenDevice(int32_t DevType,int32_t DevIndex,int32_t Reserved);
int32_t WINAPI VAI_CloseDevice(int32_t DevType,int32_t DevIndex);
int32_t WINAPI VAI_ReadBoardInfo(int32_t DevType,int32_t DevIndex,PVAI_BOARD_INFO pInfo);
int32_t WINAPI VAI_InitADC(int32_t DevType, int32_t DevIndex, uint8_t Channel, uint16_t Period);
int32_t WINAPI VAI_ReadDatas(int32_t DevType,int32_t DevIndex,uint16_t DataNum,uint16_t *pData);
#ifdef __cplusplus
}
#endif


#endif
