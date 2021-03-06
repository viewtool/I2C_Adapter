  /*
  ******************************************************************************
  * @file     : USB_I2C_AT24C02_SCTL_20CH.cpp
  * @Copyright: ViewTool 
  * @Revision : ver 1.0
  * @Date     : 2014/12/19 11:00
  * @brief    : USB_I2C_AT24C02_SCTL demo
  ******************************************************************************
  * @attention
  *
  * Copyright 2009-2014, ViewTool
  * http://www.viewtool.com/
  * All Rights Reserved
  * 
  ******************************************************************************
  */

  /*
  Hardware Connection  (This is for your reference only)
  AT24C02        Ginkgo USB-I2C Adapter
  1.A0      <-->  GND(Pin19/Pin20)
  2.A1	    <-->  GND(Pin19/Pin20)
  3.A2      <-->  GND(Pin19/Pin20)
  4.GND     <-->  GND(Pin19/Pin20)
  5.SDA	    <-->  HI2C_SDA0(Pin8)
  6.SCL	    <-->  HI2C_SCL0 (Pin6)
  7.WP	    <-->  GND(Pin19/Pin20)
  8.VCC	    <-->  VCC(Pin1/Pin2)
  */

#include "stdafx.h"
#include "ControlI2C.h"
#include "func_map.h"


uint8_t i2c_channel[]={
J28_P2_P4_I2C_STL_CH0,J50_P6_P8_I2C_STL_CH1,J50_P10_P12_I2C_STL_CH2,J50_P14_P16_I2C_STL_CH3,
J50_P1_P3_I2C_STL_CH4,J50_P5_P7_I2C_STL_CH5,J50_P9_P10_I2C_STL_CH6,J50_P13_P15_I2C_STL_CH7,
J18_P1_P5_I2C_STL_CH8,J18_P4_P6_I2C_STL_CH9,J8_P1_P3_I2C_STL_CH10,J8_P5_J50_P4_I2C_STL_CH11,
J8_P2_P4_I2C_STL_CH12,J8_P6_P8_I2C_STL_CH13,J1_P1_P2_I2C_STL_CH14,J2_P7_P9_I2C_STL_CH15,
J2_P17_P19_I2C_STL_CH16,J2_P8_P10_I2C_STL_CH17,J2_P12_P14_I2C_STL_CH18,J5_P1_P7_I2C_STL_CH19,
};
int _tmain(int argc, _TCHAR* argv[])
{
	int ret,i,j;
	VII_INIT_CONFIG I2C_Config;
	VII_TIME_CONFIG I2C_TimeConfig;
	uint8_t write_buffer[8]={0};
	uint8_t	read_buffer[8]={0};
	//Scan device
	ret = VII_ScanDevice(1);
	if(ret <= 0)
	{
		printf("No device connect!\n");
		return ret;
	}
    //Open device
    ret = VII_OpenDevice(VII_USBI2C, 0, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Open device error!\n");
        return ret;
    }
	for(j=0;j<20;j++)
	{
		//Initializes the device
		I2C_Config.AddrType = VII_ADDR_7BIT;
		I2C_Config.ClockSpeed = 400000;
		I2C_Config.ControlMode = VII_SCTL_MODE;
		I2C_Config.MasterMode = VII_MASTER;
		I2C_Config.SubAddrWidth = VII_SUB_ADDR_1BYTE;
		ret = VII_InitI2C(VII_USBI2C, 0, i2c_channel[j], &I2C_Config);
		if (ret != ERR_SUCCESS)
		{
			printf("Initialize device error!\n");
			return ret;
		}
		//Config timing,Unit of time for microseconds
		I2C_TimeConfig.tSU_STA = 5;
		I2C_TimeConfig.tHD_STA = 4;
		I2C_TimeConfig.tLOW = 5; 
		I2C_TimeConfig.tHIGH = 5;
		I2C_TimeConfig.tSU_DAT = 1;
		I2C_TimeConfig.tSU_STO = 4;
		I2C_TimeConfig.tBuf = 5;  
		ret = VII_TimeConfig(VII_USBI2C, 0, i2c_channel[j], &I2C_TimeConfig);
		if (ret != ERR_SUCCESS)
		{
			printf("Set time error!\n");
			return ret;
		}
		//Write 8 byte data to 0x00
		for (i = 0; i < 8; i++)
		{
			write_buffer[i] = i;
		}
		ret = VII_WriteBytes(VII_USBI2C, 0, i2c_channel[j], 0xA0, 0x00, write_buffer, 8);
		if (ret != ERR_SUCCESS)
		{
			printf("Write data error!\n");
			return ret;
		}
		//Delay
		Sleep(10);
		//Read 8 byte data from 0x00
		ret = VII_ReadBytes(VII_USBI2C, 0,i2c_channel[j], 0xA0, 0x00, read_buffer, 8);
		if (ret != ERR_SUCCESS)
		{
			printf("Read data error!\n");
			return ret;
		}
		else
		{
			printf("Channel = %d Read Data:\n",j);
			for(i=0;i<8;i++)
			{
				printf("%02X ",read_buffer[i]);
			}
			printf("\n");
		}
		system("pause");	
	}
	return 0;
}

