// UARTTest.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ControlUART.h"

int main(int argc, const char* argv[])
{
	int ret;
	ret = UART_ScanDevice(1);
	UART_OpenDevice(0,0);
	UART_INIT_CONFIG InitConfig;
	InitConfig.BaudRate = 115200;
	InitConfig.Parity = 0;
	InitConfig.RS485Mode = 485;
	InitConfig.StopBits = 0;
	InitConfig.WordLength = 8;
	ret = UART_InitDevice(0,0,&InitConfig);
	if(ret != ERR_SUCCESS){
		printf("Initialize device error!\n");
		return 0;
	}
	uint8_t WriteBuffer[64]={0};
	for(int i=0;i<sizeof(WriteBuffer);i++){
		WriteBuffer[i] = i;
	}
	ret = UART_WriteBytes(0,0,WriteBuffer,64);
	if(ret != ERR_SUCCESS){
		printf("Write data error!\n");
		return 0;
	}
	uint16_t Len = 0;
	uint8_t ReadBuffer[64]={0};
	uint32_t AllDataNum = 0;
	while(1){
		ret = UART_ReadBytes(0,0,ReadBuffer,&Len);
		if(ret == ERR_READ_NO_DATA){
			usleep(50*1000);
			continue;
		}else if(ret == ERR_SUCCESS){
			if(Len > 0){
				AllDataNum += Len;
				for(int i=0;i<Len;i++){
					printf("%02X ",ReadBuffer[i]);
					if(((i+1)%16)==0){
						printf("\n");
					}
				}
				printf("\n");
				printf("AllDataNum = %d\n",AllDataNum);
				Len = 0;
			}
			usleep(50*1000);
		}else{
			printf("Read data error!\n");
			return 0;
		}
	}
	return 0;
}

