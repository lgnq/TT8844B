#ifndef __TW884X_H__
#define __TW884X_H__

#define	DECODER_PAGE			0x01
#define	SCALER_PAGE				0x02
#define	IMAGE_PAGE				0x02
#define	FONT_OSD_PAGE			0x03
#define	SPI_OSD_PAGE			0x04

#define TW884X_ADDR     (0x88 >> 1)

unsigned char tw884x_read(unsigned char idx);
void tw884x_write(unsigned char idx, unsigned char val);

void tw884x_reset(void);
void tw884x_init(void);
void WaitVBlankVS1(unsigned char cnt);

#endif

