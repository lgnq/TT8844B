#ifndef __I2C_H__
#define __I2C_H__

#include "main.h"

#define SDA 254                         //定义SDA所对应的GPIO接口编号  
#define SCL 255                         //定义SCL所对应的GPIO接口编号  

#define INP  0                          //表示GPIO接口方向为输入  
#define OUTP 1                          //表示GPIO接口方向为输出  

void i2c_start(void);
void i2c_restart(void);
void i2c_stop(void);
void i2c_write_byte(unsigned char b);
unsigned char i2c_read_byte(void);

void i2c_read(unsigned char addr, unsigned char *buf, int len);  
void i2c_write(unsigned char addr, unsigned char *buf, int len);  

#endif

