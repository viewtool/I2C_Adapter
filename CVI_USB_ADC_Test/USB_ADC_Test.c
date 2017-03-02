//==============================================================================
//
// Title:		USB_ADC_Test.c
// Purpose:		A short description of the implementation.
//
// Created on:	2014/3/7 at 17:19:31 by Win7.
// Copyright:	Win7. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "ControlADC.h"
#include <ansi_c.h>
#include <stdio.h>

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?
int main (void)
{
    int ret;
    //ɨ���Ѿ����ӵ��豸
    ret = VAI_ScanDevice(1);
    if (ret <= 0)
    {
		printf("No device connect!\n");
		system("cmd /C pause");
        return ret;
    }
    //���豸
    ret = VAI_OpenDevice(VAI_USBADC, 0, 0);
    if (ret != ERR_SUCCESS)
    {
		printf("Open device error!\n");
		system("cmd /C pause");
        return ret;
    }
    //��ʼ��ADC��ADC_CH0ͨ��
    ret = VAI_InitADC(VAI_USBADC, 0, VAI_ADC_CH0,0);//���ÿ��ÿ��ͨ��ֻ��һ�����ݣ������ڿ�����Ϊ0
    if (ret != ERR_SUCCESS)
    {
		printf("Initialize ADC error!\n");
		system("cmd /C pause");
        return ret;
    }
    //��ȡADC_CH0ͨ���ĵ�ѹֵ
	uint16_t adc_datas[4096] = {0};
    ret = VAI_ReadDatas(VAI_USBADC, 0, 1, adc_datas);
    if (ret != ERR_SUCCESS)
    {
		printf("Read ADC data error!\n");
		system("cmd /C pause");
        return ret;
    }
    else
    {
		printf("ADC_CH0 = %.3f\n" ,((adc_datas[0]*3.3)/4095));
        printf("\n");
    }
    //��ʼ��ADC��ADC_CH0,ADC_CH1ͨ��
    ret = VAI_InitADC(VAI_USBADC, 0, VAI_ADC_CH0 | VAI_ADC_CH1, 0);//���ÿ��ÿ��ͨ��ֻ��һ�����ݣ������ڿ�����Ϊ0
    if (ret != ERR_SUCCESS)
    {
		printf("Initialize ADC error!\n");
		system("cmd /C pause");
        return ret;
    }
    //��ȡADC_CH0,ADC_CH1ͨ���ĵ�ѹֵ��ÿ��ͨ����ȡһ��ֵ��
    ret = VAI_ReadDatas(VAI_USBADC, 0, 1, adc_datas);
    if (ret != ERR_SUCCESS)
    {
		printf("Read ADC data error!\n");
		system("cmd /C pause");
        return ret;
    }
    else
    {
        printf("ADC_CH0 = %.3f\n" , ((adc_datas[0] * 3.3) / 4095));
        printf("ADC_CH1 = %.3f\n" , ((adc_datas[1] * 3.3) / 4095));
		printf("\n");
    }
    //��ʼ��ADC��ADC_CH0,ADC_CH1ͨ��,ÿ��ͨ������ʱ��������Ϊ1000΢��
    ret = VAI_InitADC(VAI_USBADC, 0, VAI_ADC_CH0 | VAI_ADC_CH1, 1000);//���ÿ��ÿ��ͨ��ֻ��һ�����ݣ������ڿ�����Ϊ0
    if (ret != ERR_SUCCESS)
    {
		printf("Initialize ADC error!\n");
		system("cmd /C pause");
        return ret;
    }
    //��ȡADC_CH0,ADC_CH1ͨ���ĵ�ѹֵ
    ret = VAI_ReadDatas(VAI_USBADC, 0, 10, adc_datas);//ÿ��ͨ����ȡ10��ֵ���ܹ�����20��ֵ����ʱ1000us*10 = 10ms
    if (ret != ERR_SUCCESS)
    {
		printf("Read ADC data error!\n");
		system("cmd /C pause");
        return ret;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            printf("ADC_CH0[%d] = %.3f\n" ,i, ((adc_datas[i*2] * 3.3) / 4095));
        }
        printf("\n");
        for (int i = 0; i < 10; i++)
        {
            printf("ADC_CH1[%d] = %.3f\n" ,i, ((adc_datas[i*2+1] * 3.3) / 4095));
        }
    }
    //�ر��豸
    ret = VAI_CloseDevice(VAI_USBADC, 0);
    if (ret != ERR_SUCCESS)
    {
		printf("Close device error!\n");
		system("cmd /C pause");
        return ret;
	}
	system("cmd /C pause");
	return 0;
}
