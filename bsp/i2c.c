#include "i2c.h"

void delay_us(void)
{
    unsigned char n;
    
    for (n = 0; n < 100; n++)
        ;
}

void set_gpio_direction(unsigned char pin, unsigned char dir)
{
#if 0    
    if (pin == SDA)
    {
        if (dir == OUTP)
            P1MDOUT |= 0x10;
        else if (dir == INP)
            P1MDOUT &= ~0x10;
    }
    else if (pin == SCL)
    {
        if (dir == OUTP)
            P1MDOUT |= 0x20;
        else if (dir == INP)
            P1MDOUT &= ~0x20;
    }
#endif    
}

void set_gpio_value(unsigned char pin, unsigned char val)
{
    if (pin == SDA)
        P1_4 = val;
    else if (pin == SCL)
        P1_5 = val;
}

unsigned char get_gpio_value(unsigned char pin)
{
    unsigned char val;

    if (pin == SDA)
        val = P1_4;

    return val;
}

/* I2C起始条件 */  
void i2c_start(void)  
{  
    //初始化GPIO口  
    set_gpio_direction(SDA, OUTP);          //设置SDA方向为输出  
    set_gpio_direction(SCL, OUTP);         //设置SCL方向为输出  
    set_gpio_value(SDA, 1);                //设置SDA为高电平  
    set_gpio_value(SCL, 1);                 //设置SCL为高电平  
    delay_us();                            //延时  
    
    //起始条件  
    set_gpio_value(SDA, 0);                 //SCL为高电平时，SDA由高变低  
    delay_us();  
}  

/* I2C终止条件 */  
void i2c_stop(void)  
{  
    set_gpio_value(SCL, 0);  
    delay_us();    
    
    set_gpio_value(SCL, 1);  
    set_gpio_direction(SDA, OUTP);  
    set_gpio_value(SDA, 0);  
    delay_us();  
    set_gpio_value(SDA, 1);             //SCL高电平时，SDA由低变高  
}  

/*   
I2C读取ACK信号(写数据时使用)  
返回值 ：0表示ACK信号有效；非0表示ACK信号无效  
*/  
unsigned char i2c_read_ack(void)  
{  
    unsigned char r;  
    
    set_gpio_direction(SDA, INP);           //设置SDA方向为输入  
    
    set_gpio_value(SCL, 0);              // SCL变低  
    r = get_gpio_value(SDA);                //读取ACK信号  
    delay_us();  
    set_gpio_value(SCL, 1);              // SCL变高  
    delay_us();  
    
    return r;  
}  

/* I2C发出ACK信号(读数据时使用) */  
void i2c_send_ack(void)  
{  
    set_gpio_direction(SDA, OUTP);          //设置SDA方向为输出  
    set_gpio_value(SCL, 0);              // SCL变低  
    set_gpio_value(SDA, 0);             //发出ACK信号  
    delay_us();  
    set_gpio_value(SCL, 1);              // SCL变高  
    delay_us();  
}  

/* I2C字节写 */  
void i2c_write_byte(unsigned char b)  
{  
    int i;  

    set_gpio_direction(SDA, OUTP);          //设置SDA方向为输出  
    for (i=7; i>=0; i--) 
    {  
        set_gpio_value(SCL, 0);             // SCL变低  
        delay_us();  
        set_gpio_value(SDA, b & (1<<i));        //从高位到低位依次准备数据进行发送  
        set_gpio_value(SCL, 1);             // SCL变高  
        delay_us();  
    }  

    i2c_read_ack();                 //检查目标设备的ACK信号  
}
  
/* I2C字节读 */  
unsigned char i2c_read_byte(void)  
{  
    int i;  
    unsigned char r = 0;  

    set_gpio_direction(SDA, INP);           //设置SDA方向为输入  
    for (i=7; i>=0; i--) 
    {  
        set_gpio_value(SCL, 0);         // SCL变低  
        delay_us();  
        r = (r <<1) | get_gpio_value(SDA);      //从高位到低位依次准备数据进行读取  
        set_gpio_value(SCL, 1);         // SCL变高  
        delay_us();  
    }  
    
    i2c_send_ack();                 //向目标设备发送ACK信号  

    return r;  
}  

#if 0
/*  
I2C读操作  
addr：目标设备地址  
buf：读缓冲区  
len：读入字节的长度  
*/  
void i2c_read(unsigned char addr, unsigned char* buf, int len)  
{  
    int i;  
    unsigned char t;  

    i2c_start();                        //起始条件，开始数据通信  

    //发送地址和数据读写方向  
    t = (addr << 1) | 1;                    //低位为1，表示读数据  
    i2c_write_byte(t);  
    
    //读入数据  
    for (i=0; i<len; i++)  
        buf[i] = i2c_read_byte();  
    
    i2c_stop();                     //终止条件，结束数据通信  
}
  
/*  
I2C写操作  
addr：目标设备地址  
buf：写缓冲区  
len：写入字节的长度  
*/  
void i2c_write(unsigned char addr, unsigned char* buf, int len)  
{  
    int i;  
    unsigned char t;  

    i2c_start();                        //起始条件，开始数据通信  

    //发送地址和数据读写方向  
    t = (addr << 1) | 0;                    //低位为0，表示写数据  
    i2c_write_byte(t);  
    
    //写入数据  
    for (i=0; i<len; i++)  
        i2c_write_byte(buf[i]);  

    i2c_stop();                     //终止条件，结束数据通信  
}  
#endif

