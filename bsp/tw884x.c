#include "main.h"

code unsigned char tw884x_settings[] = 
{
    // init with NTSC

	// DTV field detection setting
	0xFF, 0x00, // Page 0
	0x50, 0x80,		// field detection by window
	0x54, 0x01,		// start 64
	0x58, 0x80,		// field detection by window
	0x5C, 0x01,		// start 64
	0xB0, 0x80,		// field detection by window
	0xB4, 0x01,		// start 64
	0xB8, 0x80,		// field detection by window
	0xBC, 0x01,		// start 64
    
	//===== TW8844 PLL
	0xFF, 0x00, // Page 0
	0xD8, 0x06,		//0x00, itune=6
	0xDA, 0x06,		//0x00, itune=6
	0xDB, 0x00,
	0xDC, 0x06,		//0x00, itune=6
	0xE1, 0x04,			//0x08,
	0xE2, 0x01,			//new
	0xE3, 0x2C,			//0x0E,
	0xE9, 0x04,			//0x08,
	0xEA, 0x01,			//new
	0xEB, 0x2C,			//0x0E,

	0xF0, 0x40, // *(43)
	0xF1, 0x18, // *(18)
	0xF2, 0x00,
	0xF3, 0x07, // *(0B)
	0xF4, 0x40,
	0xF5, 0x43,
	0xF6, 0x28,
	0xFE, 0x04,

	//===== TW8844 AFE-Differential
	0xFF, 0x01,	// Page 1 AFE-Differential
	0x09, 0xF1,			// Decoder V crop must odd number
	0x1C, 0x08,			// select std as NTSC
	0x1D, 0x01,			// enable format only NTSC
	0x2F, 0xE6,			// make blue screen, auto
	0x33, 0x85,			// Decoder Freerun 60Hz
	0x36, 0xB1,			// CM Clamp - Balnking Period
	0x37, 0x47,
	0x39, 0x10,

	//===== TW8844 Output timing
	0xFF, 0x02, // Page 2
	0x16, 0x07,
	0x17, 0x80,			// width 1920
	0x1E, 0x02,
	0x1F, 0xD0,			// height 720

	0x28, 0x08,
	0x29, 0xFC,			// HTotal - 2300
	0x2a, 0x02,			// Free Run AUTO
	0x2b, 0x22,			// Mute Auto
	
	0x5A, 0x07,			// Output DE length control for line split mode
	0x5B, 0x80,			// new to TW8844B

	//===== TW8844 VP1 Scaler
	0xFF, 0x00, // Page 0
	0x07, 0x83,				// swap R<->B for LG panel
	0x08, 0x30,				// all output 0, change it 0x20 after initialize


	//===== TW8844 LVDS-TX/RX
	0xFF, 0x06, // Page 6
	0x40, 0x0C,
	0x41, 0x42,
	0x42, 0x41,
	0x43, 0x03,
	0x45, 0x0F,
	0x46, 0xE1,
	0x47, 0x80,
	0x50, 0x0C,
	0x52, 0x41,
	0x53, 0x00,
	0x54, 0x1F,
	0x55, 0xFF,
	0x57, 0x80,
	
//	0xff, 0x05,
//	0x88, 0x04,			// measure 2 even field

	0xff, 0xff	
};

code unsigned char tw884x_dtva24bit[] = 
{
	0xFF, 0x00, // Page 0
	//===== DTVA settings - 24bit RGB
	0x0A, 0x88,			// DTVA1 24bit RGB
	0x50, 0x87,			//0x07,
	0x51, 0x08,			// 0x28, NOT DE from HS
	0x52, 0x02,
	0x53, 0x05,

	0xff, 0xff	
};

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

    i2c_restart();                        //起始条件，开始数据通信  

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

void device_initialize(unsigned char *settings)
{
	unsigned char index, val;

	while ((settings[0] != 0xFF) || (settings[1] != 0xFF)) // 0xff, 0xff is end of data
    {           
		index = *settings;
		val   = *(settings+1);
        
		tw884x_write(index, val);
        
		settings += 2;
	}
}

void tw884x_init(void)
{
    unsigned char id;
    
    tw884x_reset();
         
    tw884x_write(0xFF, 0x0);
    id = tw884x_read(0x0);
    
    if (id == 0x44)
    {
        LED_G = 1;
        device_initialize(tw884x_settings);
        device_initialize(tw884x_dtva24bit);
        LED_G = 0;
    }
    else
    {
        LED_G = 0;
    }
}

