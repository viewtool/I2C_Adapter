/**
  ******************************************************************************
  * @file    ControlUART.h
  * $Author: wdluo $
  * $Revision: 447 $
  * $Date:: 2013-06-29 18:24:57 +0800 #$
  * @brief   Ginkgo USB-UART�������ײ�������API��������.
  ******************************************************************************
  * @attention
  *
  *<h3><center>&copy; Copyright 2009-2012, ViewTool</center>
  *<center><a href="http:\\www.viewtool.com">http://www.viewtool.com</a></center>
  *<center>All Rights Reserved</center></h3>
  * 
  ******************************************************************************
  */
#ifndef _CONTROLUART_H_
#define _CONTROLUART_H_

#include <stdint.h>
#include "ErrorType.h"
#ifndef OS_UNIX
#include <Windows.h>
#else
#include <unistd.h>
#ifndef WINAPI
#define WINAPI
#endif
#endif

//1.Ginkgoϵ����������Ϣ���������͡�
typedef  struct  _UART_BOARD_INFO{
	uint8_t		ProductName[32];	//Ӳ�����ƣ����硰Ginkgo-I2C-Adaptor����ע�⣺�����ַ�����������\0����
	uint8_t		FirmwareVersion[4];	//�̼��汾
	uint8_t		HardwareVersion[4];	//Ӳ���汾
	uint8_t		SerialNumber[12];	//���������к�
} UART_BOARD_INFO,*PUART_BOARD_INFO; 


//2.�����ʼ��UART����������
typedef struct _UART_INIT_CONFIG{
	uint8_t		StopBits;		//ֹͣλ��0-1bit,1-0.5bit,2-2bit,3-1.5bit
	uint8_t		WordLength;		//8
	uint8_t		Parity;			//0-No,4-Even,6-Odd
	uint16_t	RS485Mode;		//485-RS485ģʽ��232-RS232ģʽ
	uint32_t	BaudRate;		//������
}UART_INIT_CONFIG,*PUART_INIT_CONFIG;

#ifdef __cplusplus
extern "C"
{
#endif

int32_t WINAPI UART_ScanDevice(uint8_t NeedInit);
int32_t WINAPI UART_OpenDevice(int32_t DevIndex,int32_t Reserved);
int32_t WINAPI UART_CloseDevice(int32_t DevIndex);
int32_t WINAPI UART_ReadBoardInfo(int32_t DevIndex,PUART_BOARD_INFO pInfo);

int32_t WINAPI UART_InitDevice(int32_t DevIndex,int32_t UARTIndex, PUART_INIT_CONFIG pInitConfig);

int32_t WINAPI UART_WriteBytes(int32_t DevIndex,int32_t UARTIndex,uint8_t* pWriteData,uint16_t Len);
int32_t WINAPI UART_ReadBytes(int32_t DevIndex,int32_t UARTIndex,uint8_t *pReadData,uint16_t *pLen);

#ifdef __cplusplus
}
#endif

#endif

