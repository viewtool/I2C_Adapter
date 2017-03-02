#include <iostream>
#include <stdio.h>
#include "ControlADC.h"

using namespace std;

int main()
{
    int ret;
    //ɨ���Ѿ����ӵ��豸
    ret = VAI_ScanDevice(1);
    if (ret <= 0) {
        printf("No device connect!\n");
        getchar();
        return ret;
    }
    //���豸
    ret = VAI_OpenDevice(VAI_USBADC, 0, 0);
    if (ret != ERR_SUCCESS) {
        printf("Open device error!\n");
        getchar();
        return ret;
    }
    //��ʼ��ADC��ADC_CH0ͨ��
    ret = VAI_InitADC(VAI_USBADC, 0, VAI_ADC_CH0,0);//���ÿ��ÿ��ͨ��ֻ��һ�����ݣ������ڿ�����Ϊ0
    if (ret != ERR_SUCCESS) {
        printf("Initialize ADC error!\n");
        getchar();
        return ret;
    }
    //��ȡADC_CH0ͨ���ĵ�ѹֵ
    uint16_t adc_datas[4096] = {0};
    ret = VAI_ReadDatas(VAI_USBADC, 0, 1, adc_datas);
    if (ret != ERR_SUCCESS) {
        printf("Read ADC data error!\n");
        getchar();
        return ret;
    } else {
        printf("ADC_CH0 = %.3f\n" ,((adc_datas[0]*3.3)/4095));
        printf("\n");
    }
    //��ʼ��ADC��ADC_CH0,ADC_CH1ͨ��
    ret = VAI_InitADC(VAI_USBADC, 0, VAI_ADC_CH0 | VAI_ADC_CH1, 0);//���ÿ��ÿ��ͨ��ֻ��һ�����ݣ������ڿ�����Ϊ0
    if (ret != ERR_SUCCESS) {
        printf("Initialize ADC error!\n");
        getchar();
        return ret;
    }
    //��ȡADC_CH0,ADC_CH1ͨ���ĵ�ѹֵ��ÿ��ͨ����ȡһ��ֵ��
    ret = VAI_ReadDatas(VAI_USBADC, 0, 1, adc_datas);
    if (ret != ERR_SUCCESS) {
        printf("Read ADC data error!\n");
        getchar();
        return ret;
    } else {
        printf("ADC_CH0 = %.3f\n" , ((adc_datas[0] * 3.3) / 4095));
        printf("ADC_CH1 = %.3f\n" , ((adc_datas[1] * 3.3) / 4095));
        printf("\n");
    }
    //��ʼ��ADC��ADC_CH0,ADC_CH1ͨ��,ÿ��ͨ������ʱ��������Ϊ1000΢��
    ret = VAI_InitADC(VAI_USBADC, 0, VAI_ADC_CH0 | VAI_ADC_CH1, 1000);//���ÿ��ÿ��ͨ��ֻ��һ�����ݣ������ڿ�����Ϊ0
    if (ret != ERR_SUCCESS) {
        printf("Initialize ADC error!\n");
        getchar();
        return ret;
    }
    //��ȡADC_CH0,ADC_CH1ͨ���ĵ�ѹֵ
    ret = VAI_ReadDatas(VAI_USBADC, 0, 10, adc_datas);//ÿ��ͨ����ȡ10��ֵ���ܹ�����20��ֵ����ʱ1000us*10 = 10ms
    if (ret != ERR_SUCCESS) {
        printf("Read ADC data error!\n");
        getchar();
        return ret;
    } else {
        for (int i = 0; i < 10; i++) {
            printf("ADC_CH0[%d] = %.3f\n" ,i, ((adc_datas[i*2] * 3.3) / 4095));
        }
        printf("\n");
        for (int i = 0; i < 10; i++) {
            printf("ADC_CH1[%d] = %.3f\n" ,i, ((adc_datas[i*2+1] * 3.3) / 4095));
        }
    }
    //�ر��豸
    ret = VAI_CloseDevice(VAI_USBADC, 0);
    if (ret != ERR_SUCCESS) {
        printf("Close device error!\n");
        getchar();
        return ret;
    }
    getchar();
    return 0;
}
