/**
  ******************************************************************************
  * @file    ControlI2CSPI.h
  * $Author: wdluo $
  * $Revision: 447 $
  * $Date:: 2013-06-29 18:24:57 +0800 #$
  * @brief   Ginkgo USB-I2C�������ײ�������API��������.
  ******************************************************************************
  * @attention
  *
  *<h3><center>&copy; Copyright 2009-2012, ViewTool</center>
  *<center><a href="http:\\www.viewtool.com">http://www.viewtool.com</a></center>
  *<center>All Rights Reserved</center></h3>
  *
  ******************************************************************************
  */
#ifndef _CONTROLI2C_H_
#define _CONTROLI2C_H_

#include <stdint.h>
#include "ErrorType.h"
#ifndef OS_UNIX
#include <Windows.h>

#else
#ifndef WINAPI

#define WINAPI

#include <unistd.h>

#endif // WINAPI
#endif

//���������Ͷ���
#define VII_USBI2C			(1)		//�豸����
//��������ʼ�����ݶ���
#define VII_ADDR_7BIT		(7)		//7bit��ַģʽ
#define VII_ADDR_10BIT		(10)	//10bit��ַģʽ
#define VII_HCTL_MODE		(1)		//Ӳ������
#define VII_SCTL_MODE		(2)		//�������
#define VII_MASTER			(1)		//����
#define VII_SLAVE			(0)		//�ӻ�
#define VII_SUB_ADDR_NONE	(0)		//���ӵ�ַ
#define VII_SUB_ADDR_1BYTE	(1)		//1Byte�ӵ�ַ
#define VII_SUB_ADDR_2BYTE	(2)		//2Byte�ӵ�ַ
#define VII_SUB_ADDR_3BYTE	(3)		//3Byte�ӵ�ַ
#define VII_SUB_ADDR_4BYTE	(4)		//4Byte�ӵ�ַ



//1.Ginkgoϵ����������Ϣ���������͡�
typedef  struct  _VII_BOARD_INFO{
	uint8_t		ProductName[32];	//Ӳ�����ƣ����硰Ginkgo-SPI-Adaptor����ע�⣺�����ַ�����������\0����
	uint8_t		FirmwareVersion[4];	//�̼��汾
	uint8_t		HardwareVersion[4];	//Ӳ���汾
	uint8_t		SerialNumber[12];	//���������к�
} VII_BOARD_INFO,*PVII_BOARD_INFO;


//2.�����ʼ��I2C����������
typedef struct _VII_INIT_CONFIG{
	uint8_t		MasterMode;		//����ѡ�����:0-�ӻ���1-����
	uint8_t		ControlMode;	//���Ʒ�ʽ:1-Ӳ�����ƣ�2-�������
	uint8_t		AddrType;		//7-7bitģʽ��10-10bitģʽ
	uint8_t		SubAddrWidth;	//�ӵ�ַ��ȣ�0��4ȡֵ��0ʱ��ʾ���ӵ�ַģʽ
	uint16_t	Addr;			//�ӻ�ģʽʱ����豸��ַ
	uint32_t	ClockSpeed;		//ʱ��Ƶ��:��λΪHZ
}VII_INIT_CONFIG,*PVII_INIT_CONFIG;

//���I2Cʱ��������壬ʱ�䵥λΪ΢��
typedef struct _VII_TIME_CONFIG
{
    uint16_t tHD_STA;   //��ʼ�źű���ʱ��
    uint16_t tSU_STA;   //��ʼ�źŽ���ʱ��
    uint16_t tLOW;      //ʱ�ӵ͵�ƽʱ��
    uint16_t tHIGH;     //ʱ�Ӹߵ�ƽʱ��
    uint16_t tSU_DAT;   //�������뽨��ʱ��
    uint16_t tSU_STO;   //ֹͣ�źŽ���ʱ��
    uint16_t tDH;       //�����������ʱ��
    uint16_t tDH_DAT;   //�������뱣��ʱ��
    uint16_t tAA;       //SCL�����SDA���������Ӧ���ź�
    uint16_t tR;        //SDA��SCL����ʱ��
    uint16_t tF;        //SDA��SCL�½�ʱ��
    uint16_t tBuf;      //�µķ��Ϳ�ʼǰ���߿���ʱ��
    uint8_t tACK[4];
    uint16_t tStart;
    uint16_t tStop;
}VII_TIME_CONFIG,*PVII_TIME_CONFIG;

#ifdef __cplusplus
extern "C"
{
#endif
int32_t WINAPI VII_ScanDevice(uint8_t NeedInit=1);
int32_t WINAPI VII_OpenDevice(int32_t DevType,int32_t DevIndex,int32_t Reserved);
int32_t WINAPI VII_CloseDevice(int32_t DevType,int32_t DevIndex);
int32_t WINAPI VII_ReadBoardInfo(int32_t DevIndex,PVII_BOARD_INFO pInfo);
int32_t WINAPI VII_TimeConfig(int32_t DevType, int32_t DevIndex, int32_t I2CIndex, PVII_TIME_CONFIG pTimeConfig);
int32_t WINAPI VII_InitI2C(int32_t DevType, int32_t DevIndex, int32_t I2CIndex, PVII_INIT_CONFIG pInitConfig);
int32_t WINAPI VII_WriteBytes(int32_t DevType,int32_t DevIndex,int32_t I2CIndex,uint16_t Addr,uint32_t SubAddr,uint8_t *pWriteData,uint16_t Len);
int32_t WINAPI VII_ReadBytes(int32_t DevType,int32_t DevIndex,int32_t I2CIndex,uint16_t Addr,uint32_t SubAddr,uint8_t *pReadData,uint16_t Len);
#ifdef __cplusplus
}
#endif


#endif

