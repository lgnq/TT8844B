#include "main.h"

void tw884x_write(unsigned char idx, unsigned char val)
{
    i2c_start();                        //起始条件，开始数据通信  

    //发送地址和数据读写方向  
    //低位为0，表示写数据  
    i2c_write_byte((TW884X_ADDR << 1) | 0);  
    
    //写入索引  
    i2c_write_byte(idx);  

    //写入数据  
    i2c_write_byte(val);
    
    i2c_stop();                     //终止条件，结束数据通信      
}

unsigned char tw884x_read(unsigned char idx)
{
    unsigned char val;
    
    i2c_start();                        //起始条件，开始数据通信  

    //发送地址和数据读写方向  
    //低位为0，表示写数据  
    i2c_write_byte((TW884X_ADDR << 1) | 0);  
    
    //写入索引  
    i2c_write_byte(idx);  

    i2c_start();                        //起始条件，开始数据通信  

    //发送地址和数据读写方向  
    //低位为1，表示读数据  
    i2c_write_byte((TW884X_ADDR << 1) | 1);  
    
    //读入数据  
    val = i2c_read_byte();
    
    i2c_stop();                     //终止条件，结束数据通信  

    return val;
}

void tw884x_reset(void)
{
    unsigned int i;
    
    LED_R = 1;
    LED_G = 1;
    TW_HWRESET = 1;					//Reset for Devices
    
    for (i = 0; i < 0xFFFF; i++)
    {
        ;
    }
    for (i = 0; i < 0xFFFF; i++)
    {
        ;
    }
    for (i = 0; i < 0xFFFF; i++)
    {
        ;
    }
    for (i = 0; i < 0xFFFF; i++)
    {
        ;
    }
    for (i = 0; i < 0xFFFF; i++)
    {
        ;
    }
    
    LED_R = 0;
    LED_G = 0;
    TW_HWRESET = 0;					//Reset for Devices    
}

void tw884x_init(void)
{
    unsigned char id;
    
    tw884x_reset();   
        
    tw884x_write(0xFF, 0x0);
    for (id = 0; id < 0xFF; id++)
    {
        ;
    }    
    id = tw884x_read(0x1);
}
