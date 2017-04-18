#include "main.h"

void spi_flash_detect(void)
{
    U8 manufacture_id;
    U8 device_id_1;
    U8 device_id_2;
    
    tw884x_write(0xFF, 0x04);

    tw884x_write(0xF3, (DMA_DEST_CHIPREG << 6) | DMA_CMD_COUNT_1);

    //read id command
    tw884x_write(0xFA, SPICMD_RDID);

    tw884x_write(0xF6, 0x04);
    tw884x_write(0xF7, 0xD0);

    //read data length
    tw884x_write(0xF5, 0x00);
    tw884x_write(0xF8, 0x00);
    tw884x_write(0xF9, 0x03);

    //start DMA write (no BUSY check)
    tw884x_write(0xF4, (DMA_NO_BUSY_CHECK<<2) | (DMA_READ<<1) | DMA_START);
    
    //wait while I2C DMA Start command execution bit is cleared
    while (tw884x_read(0xF4) & 0x01)
        ;
        
    manufacture_id = tw884x_read(0xD0);
    device_id_1    = tw884x_read(0xD1);
    device_id_2    = tw884x_read(0xD2);

    if (manufacture_id == 0xC8)
        LED_G = 1;
}

