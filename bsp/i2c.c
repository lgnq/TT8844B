#include "i2c.h"

void delay(unsigned char i)
{
    unsigned char n;
    
    for (n = 0; n < i; n++)
        ;
}

void set_gpio_direction(unsigned char pin, unsigned char dir)
{
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

/* I2C��ʼ���� */  
int i2c_start()  
{  
    //��ʼ��GPIO��  
    set_gpio_direction(SDA, OUTP);          //����SDA����Ϊ���  
    set_gpio_direction(SCL, OUTP);         //����SCL����Ϊ���  
    set_gpio_value(SDA, 1);                //����SDAΪ�ߵ�ƽ  
    set_gpio_value(SCL, 1);                 //����SCLΪ�ߵ�ƽ  
    delay();                            //��ʱ  
    
    //��ʼ����  
    set_gpio_value(SDA, 0);                 //SCLΪ�ߵ�ƽʱ��SDA�ɸ߱��  
    delay();  
}  

/* I2C��ֹ���� */  
void i2c_stop()  
{  
    set_gpio_value(SCL, 1);  
    set_gpio_direction(SDA, OUTP);  
    set_gpio_value(SDA, 0);  
    delay();  
    set_gpio_value(SDA, 1);             //SCL�ߵ�ƽʱ��SDA�ɵͱ��  
}  

/*   
I2C��ȡACK�ź�(д����ʱʹ��)  
����ֵ ��0��ʾACK�ź���Ч����0��ʾACK�ź���Ч  
*/  
unsigned char i2c_read_ack()  
{  
    unsigned char r;  
    set_gpio_direction(SDA, INP);           //����SDA����Ϊ����  
    set_gpio_value(SCL,0);              // SCL���  
    r = get_gpio_value(SDA);                //��ȡACK�ź�  
    delay();  
    set_gpio_value(SCL,1);              // SCL���  
    delay();  
    
    return r;  
}  

/* I2C����ACK�ź�(������ʱʹ��) */  
int i2c_send_ack()  
{  
    set_gpio_direction(SDA, OUTP);          //����SDA����Ϊ���  
    set_gpio_value(SCL,0);              // SCL���  
    set_gpio_value(SDA, 0);             //����ACK�ź�  
    delay();  
    set_gpio_value(SCL,1);              // SCL���  
    delay();  
}  

/* I2C�ֽ�д */  
void i2c_write_byte(unsigned char b)  
{  
    int i;  

    set_gpio_direction(SDA, OUTP);          //����SDA����Ϊ���  
    for (i=7; i>=0; i--) 
    {  
        set_gpio_value(SCL, 0);             // SCL���  
        delay();  
        set_gpio_value(SDA, b & (1<<i));        //�Ӹ�λ����λ����׼�����ݽ��з���  
        set_gpio_value(SCL, 1);             // SCL���  
        delay();  
    }  

    i2c_read_ack();                 //���Ŀ���豸��ACK�ź�  
}
  
/* I2C�ֽڶ� */  
unsigned char i2c_read_byte()  
{  
    int i;  
    unsigned char r = 0;  

    set_gpio_direction(SDA, INP);           //����SDA����Ϊ����  
    for (i=7; i>=0; i--) 
    {  
        set_gpio_value(SCL, 0);         // SCL���  
        delay();  
        r = (r <<1) | get_gpio_value(SDA);      //�Ӹ�λ����λ����׼�����ݽ��ж�ȡ  
        set_gpio_value(SCL, 1);         // SCL���  
        delay();  
    }  
    
    i2c_send_ack();                 //��Ŀ���豸����ACK�ź�  

    return r;  
}  

/*  
I2C������  
addr��Ŀ���豸��ַ  
buf����������  
len�������ֽڵĳ���  
*/  
void i2c_read(unsigned char addr, unsigned char* buf, int len)  
{  
    int i;  
    unsigned char t;  

    i2c_start();                        //��ʼ��������ʼ����ͨ��  

    //���͵�ַ�����ݶ�д����  
    t = (addr << 1) | 1;                    //��λΪ1����ʾ������  
    i2c_write_byte(t);  
    
    //��������  
    for (i=0; i<len; i++)  
        buf[i] = i2c_read_byte();  
    
    i2c_stop();                     //��ֹ��������������ͨ��  
}
  
/*  
I2Cд����  
addr��Ŀ���豸��ַ  
buf��д������  
len��д���ֽڵĳ���  
*/  
void i2c_write(unsigned char addr, unsigned char* buf, int len)  
{  
    int i;  
    unsigned char t;  

    i2c_start();                        //��ʼ��������ʼ����ͨ��  

    //���͵�ַ�����ݶ�д����  
    t = (addr << 1) | 0;                    //��λΪ0����ʾд����  
    i2c_write_byte(t);  
    
    //д������  
    for (i=0; i<len; i++)  
        i2c_write_byte(buf[i]);  

    i2c_stop();                     //��ֹ��������������ͨ��  
}  


