#ifndef _ERRORTYPE_H_
#define _ERRORTYPE_H_

#include <stdint.h>
#ifndef OS_UNIX
#include <Windows.h>
#endif

//ͨ�ô�����
#define	ERR_SUCCESS					(0)		//û�д���
#define	ERR_PARAMETER_NULL			(-1)	//�����ָ��Ϊ��ָ��
#define	ERR_INPUT_DATA_TOO_MUCH		(-2)	//���������������涨����
#define	ERR_INPUT_DATA_TOO_LESS		(-3)	//���������������涨����
#define	ERR_INPUT_DATA_ILLEGALITY	(-4)	//���������ʽ�͹涨�Ĳ�����
#define	ERR_USB_WRITE_DATA			(-5)	//USBд���ݴ���
#define	ERR_USB_READ_DATA			(-6)	//USB�����ݴ���
#define	ERR_READ_NO_DATA			(-7)	//���������ʱ����û������
#define	ERR_OPEN_DEVICE				(-8)	//���豸ʧ��
#define	ERR_CLOSE_DEVICE			(-9)	//�ر��豸ʧ��
#define	ERR_EXECUTE_CMD				(-10)	//�豸ִ������ʧ��
#define ERR_SELECT_DEVICE			(-11)	//ѡ���豸ʧ��
#define	ERR_DEVICE_OPENED			(-12)	//�豸�Ѿ���
#define	ERR_DEVICE_NOTOPEN			(-13)	//�豸û�д�
#define	ERR_BUFFER_OVERFLOW			(-14)	//���������
#define	ERR_DEVICE_NOTEXIST			(-15)	//���豸������
#define	ERR_LOAD_KERNELDLL			(-16)	//װ�ض�̬��ʧ��
#define ERR_CMD_FAILED				(-17)	//ִ������ʧ�ܴ�����
#define	ERR_BUFFER_CREATE			(-18)	//�ڴ治��

#endif
