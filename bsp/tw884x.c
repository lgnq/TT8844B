#include "main.h"

void tw884x_reset(void)
{
    unsigned short i;
    
    LED_R = 1;
    LED_G = 1;
    TW_HWRESET = 1;					//Reset for Devices
    
    for (i = 0; i < 0xFFFF; i++)
    {
        ;
    }
    
    LED_R = 0;
    LED_R = 0;
    TW_HWRESET = 0;					//Reset for Devices    
}

void tw884x_init(void)
{
    tw884x_reset();
    
}