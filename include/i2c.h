#ifndef __I2C_H__
#define __I2C_H__

#include "main.h"

#define SDA 254                         //����SDA����Ӧ��GPIO�ӿڱ��  
#define SCL 255                         //����SCL����Ӧ��GPIO�ӿڱ��  

#define INP  0                          //��ʾGPIO�ӿڷ���Ϊ����  
#define OUTP 1                          //��ʾGPIO�ӿڷ���Ϊ���  

void i2c_start(void);
void i2c_restart(void);
void i2c_stop(void);
void i2c_write_byte(unsigned char b);
unsigned char i2c_read_byte(void);

void i2c_read(unsigned char addr, unsigned char *buf, int len);  
void i2c_write(unsigned char addr, unsigned char *buf, int len);  

#endif

