#ifndef __I2C_H__
#define __I2C_H__

#include "main.h"

//??I2C?SCL?SDA???????
//SCL output hardware operate
 #define SIMUI2C_SCL_SET                P1_5 = 1
 #define SIMUI2C_SCL_CLR                P1_5 = 0
 //SDA output hardware operate
 #define SIMUI2C_SDA_SET                P1_4 = 1
 #define SIMUI2C_SDA_CLR                P1_4 = 0
 //SDA input hardware operate
 #define SIMUI2C_SDA_IN                 P1_4                   


//simulate i2c APIs
void bsp_SimuI2C_start(void);
void bsp_SimuI2C_stop(void);
void bsp_SimuI2C_SandAck(void);
void bsp_SimuI2C_SandNack(void);
unsigned char bsp_SimuI2C_ReadAck(void);
unsigned char bsp_SimuI2C_read_byte(void);
void bsp_SimuI2C_write_byte(unsigned char dat);

#endif