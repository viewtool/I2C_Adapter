  /*
  ******************************************************************************
  * @file     : USB_GPIO_Test.cpp
  * @Copyright: ViewTool 
  * @Revision : ver 1.0
  * @Date     : 2020/05/25 11:53
  * @brief    : BOARD_FICUS_VC_USB_GPIO_Test_80CH demo
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
   A demo program for 80 channel GPIO control with:
   HW: Ginkgo Ficus (STM32F105VCT on board)
   FW: >= 
               Product name : Ginkgo-I2C&SPI&CAN-Adaptor
               Firmware version : 3.0.7
               Hardware version : 2.1.0
   IDE: VS2010 (or above)

   Ginkgo Ficus:
   http://www.viewtool.com/index.php/en/14-2016-07-26-07-18-35/273-ginkgo3-i2c-spi-can-adapter
   
   Pin layout and definition:
   http://www.viewtool.com/demo/STM32/Ficus_document_html/index.html

   Ginkgo Ficus lead out 100% chip's resource for usage, for GPIO, it's more than 80 pins could be used. The demo shows defined pin number's usage
   It could be used with I2C, SPI, CAN (driver module required) simultaneously.

   PIN definition rule and one example: J15_P1_GPIO
   1. socket definition: 
   J15 definition example (see above link for detail): 
   GND          1  2     P1  GPIOE_5    <--------------------- socket pin name for J15_P1_GPIO
   GND          3  4     P2  GPIOE_6  
   GND          5  6     P3  GPIOC_13  
   GPIOE_2  P4  7  8     P5  GPIOC_0  
   GPIOC_1  P6  9  10    P7  GPIOA_2  
   GPIOC_2  P8  11  12   P9  GPIOA_3  
   GND  13      14  P10      GPIOE_3  
   GND  15      16  P11      GPIOE_4 


   2. GPIO pin macro definitoin used in all of ficus board related programs:
   J15_P1_GPIO:  --------> GPIO pin macro defintion
   |   |   |____ usage: GPIO, fixed 
   |   |________ pinout index (at this socket), P1: index = 1, it's GPIOE_5 @ socket num 2 position
   |____________ FICUS board socket number (see above pin layout for more detail), J15: 2x8 pinout socket

   GPIOE_5: socket pinout name, equal to STM32FXXX standard GPIO pin definition: port = GPIOE, pin = GPIO_PIN_5
       | |____ pin index: 5  = GPIO_PIN_5
	   |______ port index: E = GPIOE

   3. check pin macro defition in func_map.h:
   #define J15_P1_GPIO  (VGI_GPIO_PORTE|VGI_GPIO_PIN5)
                                      |             |_____ GPIO_PIN_5
									  |___________________ GPIOE

*/
#include "stdafx.h"
#include "ControlGPIO.h"
#include "func_map.h"

/*
   gpio_channel: defined all pins used in this program, each pin definition is 32bits, 16bits for port, 16bits for pin index, 
   for stm32f105vct: port: => GPIOA - GPIOE
                     pin index: => GPIO_PIN0 - GPIO_PIN15
*/
uint32_t gpio_channel[]={
J15_P1_GPIO,J15_P2_GPIO,J15_P3_GPIO,J15_P4_GPIO,
J15_P5_GPIO,J15_P6_GPIO,J15_P7_GPIO,J15_P8_GPIO,
J15_P9_GPIO,J15_P10_GPIO,J15_P11_GPIO,

J2_P1_GPIO,J2_P2_GPIO,J2_P3_GPIO,J2_P4_GPIO,
J2_P5_GPIO,J2_P6_GPIO,J2_P7_GPIO,J2_P8_GPIO,
J2_P9_GPIO,J2_P10_GPIO,J2_P11_GPIO,J2_P12_GPIO,
J2_P13_GPIO,J2_P14_GPIO,J2_P15_GPIO,J2_P16_GPIO,
J2_P17_GPIO,J2_P18_GPIO,J2_P19_GPIO,J2_P20_GPIO,

J6_P1_GPIO,J6_P2_GPIO,J1_P1_GPIO,J1_P2_GPIO,
J4_P1_GPIO,J4_P2_GPIO,

J8_P1_GPIO,J8_P2_GPIO,J8_P3_GPIO,J8_P4_GPIO,
J8_P5_GPIO,J8_P6_GPIO,J8_P7_GPIO,J8_P8_GPIO,

J18_P1_GPIO,J18_P2_GPIO,J18_P3_GPIO,J18_P4_GPIO,
J18_P5_GPIO,J18_P6_GPIO,
J7_P1_GPIO,

J50_P1_GPIO,J50_P3_GPIO,J50_P4_GPIO,J50_P5_GPIO,
J50_P6_GPIO,J50_P7_GPIO,J50_P8_GPIO,J50_P9_GPIO,
J50_P10_GPIO,J50_P11_GPIO,J50_P12_GPIO,J50_P13_GPIO,
J50_P14_GPIO,J50_P15_GPIO,J50_P16_GPIO,

J28_P1_GPIO,J28_P2_GPIO,J28_P3_GPIO,J28_P4_GPIO,
J28_P5_GPIO,J28_P6_GPIO,J33_P1_GPIO,

J5_P1_GPIO,
//J5_P2_GPIO:  could not be used as it's been occupied
J5_P3_GPIO,
J5_P4_GPIO,
J5_P5_GPIO,J5_P6_GPIO,J5_P7_GPIO,
J5_P8_GPIO,

J17_P1_GPIO,J17_P2_GPIO,J17_P3_GPIO,J17_P4_GPIO,
J17_P5_GPIO,J17_P6_GPIO,
//J17_P7_GPIO: :  could not be used as it's been occupied

J45_GPIO,J46_GPIO,J47_GPIO,J48_GPIO,

J19_P1_GPIO,J19_P2_GPIO,J19_P3_GPIO,J19_P4_GPIO,
J19_P5_GPIO,J19_P6_GPIO,J19_P7_GPIO,J19_P8_GPIO,
J19_P9_GPIO,J19_P10_GPIO,J19_P11_GPIO,J19_P12_GPIO,
J19_P13_GPIO,J19_P14_GPIO,J19_P15_GPIO,J19_P16_GPIO,

J20_P1_GPIO,J20_P2_GPIO,J20_P3_GPIO,J20_P4_GPIO,
J20_P5_GPIO,J20_P6_GPIO,J20_P7_GPIO,J20_P8_GPIO,
J20_P9_GPIO,J20_P10_GPIO,J20_P11_GPIO,J20_P12_GPIO,
J20_P13_GPIO,J20_P14_GPIO,J20_P15_GPIO,J20_P16_GPIO,
J20_P17_GPIO,J20_P18_GPIO,J20_P19_GPIO,J20_P20_GPIO,
J20_P21_GPIO,

J21_P1_GPIO ,J21_P2_GPIO ,J21_P3_GPIO ,J21_P4_GPIO,
J21_P5_GPIO ,J21_P6_GPIO ,J21_P7_GPIO ,J21_P8_GPIO,
J21_P9_GPIO ,J21_P10_GPIO,J21_P11_GPIO,J21_P12_GPIO,
//J21_P13_GPIO,
//J21_P14_GPIO,
J21_P15_GPIO,J21_P16_GPIO,J21_P17_GPIO,J21_P18_GPIO,
J21_P19_GPIO,J21_P20_GPIO,
J21_P21_GPIO,J21_P22_GPIO,

J22_P1_GPIO ,J22_P2_GPIO ,J22_P3_GPIO ,J22_P4_GPIO,
J22_P5_GPIO ,J22_P6_GPIO ,J22_P7_GPIO ,J22_P8_GPIO,
J22_P9_GPIO ,J22_P10_GPIO,J22_P11_GPIO,J22_P12_GPIO,
J22_P13_GPIO,J22_P14_GPIO,J22_P15_GPIO,J22_P16_GPIO,
J22_P17_GPIO,J22_P18_GPIO,

//J14_P1_GPIO ,
J14_P2_GPIO ,J14_P3_GPIO ,
J14_P4_GPIO,
J14_P5_GPIO ,J14_P6_GPIO ,J14_P7_GPIO ,J14_P8_GPIO,
J14_P9_GPIO ,J14_P10_GPIO,J14_P11_GPIO,

J11_P1_GPIO ,J11_P2_GPIO ,J11_P3_GPIO ,J11_P4_GPIO,
J11_P5_GPIO ,J11_P6_GPIO ,J11_P7_GPIO ,J11_P8_GPIO,
J11_P9_GPIO ,J11_P10_GPIO,J11_P11_GPIO,J11_P12_GPIO,
J11_P13_GPIO,J11_P14_GPIO,J11_P15_GPIO,J11_P16_GPIO,
J11_P17_GPIO,J11_P18_GPIO,J11_P19_GPIO,J11_P20_GPIO,
J11_P21_GPIO,J11_P22_GPIO,J11_P23_GPIO,J11_P24_GPIO,
J11_P25_GPIO,J11_P26_GPIO,

J42_GPIO,J43_GPIO,J44_GPIO,
};

// test at highest speed (high requency waveform output)
//#define DELAY_MS    0  

// watch LED flashing
//#define DELAY_MS    200

//
#define DELAY_MS    2

void vt_delay(int ms)
{
    Sleep(ms);
}

int _tmain(int argc, _TCHAR* argv[])
{
    int ret = 0,i = 0;
	uint16_t data = 0;
	int pin_num = (sizeof(gpio_channel)/4); 
    // Scan connected device
    ret = VGI_ScanDevice(1);
    if (ret <= 0)
    {
        printf("No device connect!\n");
        return ret;
    }
    // Open device 
    ret = VGI_OpenDevice(VGI_USBGPIO, 0, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Open device error!\n");
        return ret;
    }

	// configue each pin as output 
	for(i=0x00;i<pin_num;i++)
	{
		ret = VGI_SetOutputEx(VGI_USBGPIO, 0,gpio_channel[i]);
		if (ret != ERR_SUCCESS)
		{
			printf("Set pin output error!\n");
			return ret;
		}
	}

	for(i=0x00;i<pin_num;i++)
	{
		// Set pin output high 
		ret = VGI_SetPinsEx(VGI_USBGPIO, 0,gpio_channel[i]);
		if (ret != ERR_SUCCESS)
		{
			printf("Set pin high error!\n");
			return ret;
		}else{
			printf("Set pin high success!\n");
			vt_delay(DELAY_MS); 
		}
		// Set pin output low 
		ret = VGI_ResetPinsEx(VGI_USBGPIO, 0,gpio_channel[i]);
		if (ret != ERR_SUCCESS)
		{
			printf("Set pin low error!\n");
			return ret;
		}else{
			printf("Set pin low success!\n");	
			vt_delay(DELAY_MS); 
		}	
	}
    // close device
    ret = VGI_CloseDevice(VGI_USBGPIO, 0);
    if (ret != ERR_SUCCESS)
    {
        printf("Close device error!\n");
        return ret;
    }
	return 0;

}
