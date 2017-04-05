#include "i2c.h"

void delay_us(unsigned char i)
{
    unsigned char n;
    
    for (n = 0; n < i; n++)
        ;
}

 /*  ????I2C?start????,??restart??????
*********************************************************************************************************
 * function    : bsp_SimuI2C_start
 * Description : generate a i2c start or restart
 * Argument(s) : point to struct SimuI2cPortType
 * Return(s)   : none
 *********************************************************************************************************
 */
 void bsp_SimuI2C_start(void)
 {       
         //here may be a stop
         SIMUI2C_SCL_SET;
         delay_us(1);//SCL setup time for STOP condition, 0.6uS
         SIMUI2C_SDA_SET;
         delay_us(2);//the bus must be free before a new transmission can start, 1.2uS
         
         //start
         SIMUI2C_SDA_CLR;
         delay_us(1);//SCL hold time for START condition, 0.6uS
         SIMUI2C_SCL_CLR;
         delay_us(1);//SCL low period * 0.5 = 0.65uS
 }

 /*  ????I2C?stop????
*********************************************************************************************************
 * function    : bsp_SimuI2C_stop
 * Description : generate a i2c stop
 * Argument(s) : point to struct SimuI2cPortType
 * Return(s)   : none
 *********************************************************************************************************
 */
 void bsp_SimuI2C_stop(void)
 {
         
         //set SCL and SDA low first
         SIMUI2C_SCL_CLR;
         delay_us(1);//SCL low period * 0.5 = 0.65uS
         SIMUI2C_SDA_CLR;
         delay_us(1);//SCL low period * 0.5 = 0.65uS
         
         //stop
         SIMUI2C_SCL_SET;
         delay_us(1);//SCL setup time for STOP condition
         SIMUI2C_SDA_SET;
         delay_us(2);//Time the bus must be free before a new transmission can start, 1.2uS
 }


 /*  ????????ack????
*********************************************************************************************************
 * function    : bsp_SimuI2C_SandAck
 * Description : generate a i2c ack to slave
 * Argument(s) : point to struct SimuI2cPortType
 * Return(s)   : none
 *********************************************************************************************************
 */
 void bsp_SimuI2C_SandAck(void)
 {
         
         //set sda=0
         //delay_us(1);//SCL low period * 0.5 = 0.65uS
         SIMUI2C_SDA_CLR;//SDA=0
         delay_us(1);//SCL low period * 0.5 = 0.65uS
         
         //scl pulse
         SIMUI2C_SCL_SET;
         delay_us(1);//SCL high period, 0.6uS
         SIMUI2C_SCL_CLR;
         delay_us(1);//SCL low period * 0.5 = 0.65uS
 }


/*   ????????no ack?????
*********************************************************************************************************
* function    : bsp_SimuI2C_SandNack
* Description : generate a i2c noack to slave
* Argument(s) : point to struct SimuI2cPortType
* Return(s)   : none
*********************************************************************************************************
*/
void bsp_SimuI2C_SandNack(void)
{
        
        //set sda=1
        //delay_us(1);//SCL low period * 0.5 = 0.65uS
        SIMUI2C_SDA_SET;//SDA=1
        delay_us(1);//SCL low period * 0.5 = 0.65uS
        
        //scl pulse
        SIMUI2C_SCL_SET;
        delay_us(1);//SCL high period, 0.6uS
        SIMUI2C_SCL_CLR;
        delay_us(1);//SCL low period * 0.5 = 0.65uS
}

/*   ??????ack??????, 0????, 1?????
*********************************************************************************************************
* function    : bsp_SimuI2C_ReadAck
* Description : check i2c ack from slave
* Argument(s) : point to struct SimuI2cPortType
* Return(s)   : 0: ack, 1: nack
*********************************************************************************************************
*/
unsigned char bsp_SimuI2C_ReadAck(void)
{
        unsigned char ack;
        
        delay_us(1);//SCL low period * 0.5 = 0.65uS
        SIMUI2C_SCL_SET;
        delay_us(1);//SCL high period, 0.6uS
        ack = SIMUI2C_SDA_IN;
        SIMUI2C_SCL_CLR;
        delay_us(1);//SCL low period * 0.5 = 0.65uS
        
        return ack;
}

/*   ???????,????8bit??
*********************************************************************************************************
* function    : bsp_SimuI2C_read_byte
* Description : read a byte from i2c slave
* Argument(s) : point to struct SimuI2cPortType
* Return(s)   : the read data
*********************************************************************************************************
*/
unsigned char bsp_SimuI2C_read_byte(void)
{
        unsigned char i;
        unsigned char  dat;
        
        dat = 0;
        for(i=0; i<8; i++) {
                delay_us(1);//SCL low period * 0.5 = 0.65uS
                SIMUI2C_SCL_SET;
                delay_us(1);//SCL high period, 0.6uS
                //read data in
                dat<<=1;
                if (1 == SIMUI2C_SDA_IN)
                    dat |= 0x01;
                SIMUI2C_SCL_CLR;
                delay_us(1);//SCL low period * 0.5 = 0.65uS
        }

        return dat;
}

/*  ???8bit??????
*********************************************************************************************************
* function    : bsp_SimuI2C_write_byte
* Description : write a byte to i2c slave
* Argument(s) : pSimuI2cPort: point to struct SimuI2cPortType, data: data to write
* Return(s)   : none
*********************************************************************************************************
*/
void bsp_SimuI2C_write_byte(unsigned char dat)
{
        unsigned char i;
        
        for(i=0; i<8; i++) {
                delay_us(1);//SCL low period * 0.5 = 0.65uS
                //sda bit output
                if(dat & 0x80)
                        SIMUI2C_SDA_SET;
                else
                        SIMUI2C_SDA_CLR;
                delay_us(1);//SCL low period * 0.5 = 0.65uS
                //scl pulse
                SIMUI2C_SCL_SET;                
                delay_us(1);//SCL high period, 0.6uS
                SIMUI2C_SCL_CLR;
                //next bit
                dat <<= 1;
        }
        delay_us(1);//SCL low period * 0.5 = 0.65uS
}

