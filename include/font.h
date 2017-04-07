#ifndef __FONT_H__
#define __FONT_H__

#define	FONTWIN1_ST		0x20
#define	FONTWIN2_ST		0x30
#define	FONTWIN3_ST		0x40
#define	FONTWIN4_ST		0x50

#define	FONTWIN_ENABLE	0X00
#define	FONT_ALPHA		0x01

void fosd_enable(unsigned char en);
void fosd_win_enable(unsigned char winno, unsigned char en);
void fosd_win_alpha(unsigned char winno, unsigned char color, unsigned char alpha);
void fosd_win_screen(unsigned char winno, unsigned int x, unsigned int y, unsigned char w, unsigned char h, unsigned char zoomH, unsigned char zoomV);
void fosd_win_style(unsigned char winno, unsigned char bdOn, unsigned char bdColor, unsigned char bdWidth, unsigned char bdSpaceH, unsigned char bdSpaceV, unsigned char chSpaceH, unsigned char chSpaceV);
void fosd_win_ram_start(unsigned char winno, unsigned int start);
void fosd_download_font_direct(unsigned char dest_font_idx, unsigned char *src_loc, unsigned int fSize, unsigned char width, unsigned char height);

#endif

