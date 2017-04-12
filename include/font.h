#ifndef __FONT_H__
#define __FONT_H__

#define	FONTWIN1_ST		0x20
#define	FONTWIN2_ST		0x30
#define	FONTWIN3_ST		0x40
#define	FONTWIN4_ST		0x50

#define	FONTWIN_ENABLE	0X00
#define	FONT_ALPHA		0x01

#define BG_BLACK       (0x00<<4)        //0x0000
#define BG_DBLUE       (0x01<<4)        //0x0010
#define BG_DGREEN      (0x02<<4)        //0x0400
#define BG_DCYAN       (0x03<<4)        //0x0410
#define BG_DRED        (0x04<<4)        //0x8000
#define BG_DMAGENTA    (0x05<<4)        //0x8010
#define BG_DYELLO      (0x06<<4)        //0x8400
#define BG_GRAY        (0x07<<4)        //0x8410
#define BG_SILVER      (0x08<<4)        //0xC618
#define BG_BLUE        (0x09<<4)        //0x001F
#define BG_LIME        (0x0A<<4)        //0x07E0
#define BG_CYAN        (0x0B<<4)        //0x07FF
#define BG_RED         (0x0C<<4)        //0xF800
#define BG_MAGENTA     (0x0D<<4)        //0xF81F
#define BG_YELLO       (0x0E<<4)        //0xFFE0
#define BG_WHITE       (0x0F<<4)        //0xFFFF

#define FG_BLACK       0x00        //0x0000
#define FG_DBLUE       0x01        //0x0010
#define FG_DGREEN      0x02        //0x0400
#define FG_DCYAN       0x03        //0x0410
#define FG_DRED        0x04        //0x8000
#define FG_DMAGENTA    0x05        //0x8010
#define FG_DYELLO      0x06        //0x8400
#define FG_GRAY        0x07        //0x8410
#define FG_SILVER      0x08        //0xC618
#define FG_BLUE        0x09        //0x001F
#define FG_LIME        0x0A        //0x07E0
#define FG_CYAN        0x0B        //0x07FF
#define FG_RED         0x0C        //0xF800
#define FG_MAGENTA     0x0D        //0xF81F
#define FG_YELLO       0x0E        //0xFFE0
#define FG_WHITE       0x0F        //0xFFFF

#define BLACK       0x00        //0x0000
#define DBLUE       0x01        //0x0010
#define DGREEN      0x02        //0x0400
#define DCYAN       0x03        //0x0410
#define DRED        0x04        //0x8000
#define DMAGENTA    0x05        //0x8010
#define DYELLO      0x06        //0x8400
#define GRAY        0x07        //0x8410
#define SILVER      0x08        //0xC618
#define BLUE        0x09        //0x001F
#define LIME        0x0A        //0x07E0
#define CYAN        0x0B        //0x07FF
#define RED         0x0C        //0xF800
#define MAGENTA     0x0D        //0xF81F
#define YELLO       0x0E        //0xFFE0
#define WHITE       0x0F        //0xFFFF

extern code unsigned short default_lut[];

void fosd_enable(unsigned char en);
void fosd_win_enable(unsigned char winno, unsigned char en);
void fosd_win_alpha(unsigned char winno, unsigned char color, unsigned char alpha);
void fosd_win_screen(unsigned char winno, unsigned int x, unsigned int y, unsigned char w, unsigned char h, unsigned char zoomH, unsigned char zoomV);
void fosd_win_style(unsigned char winno, unsigned char bdOn, unsigned char bdColor, unsigned char bdWidth, unsigned char bdSpaceH, unsigned char bdSpaceV, unsigned char chSpaceH, unsigned char chSpaceV);
void fosd_win_ram_start(unsigned char winno, unsigned int start);
void fosd_download_font_direct(unsigned char dest_font_idx, unsigned char *src_loc, unsigned int fSize, unsigned char width, unsigned char height);
void fosd_clear_display(unsigned int pos, unsigned char attr, unsigned int cnt);
void fosd_display_string(unsigned int pos, unsigned char *str, unsigned char attr);
void fosd_lut(unsigned int *PalettePtr, unsigned char StartAddr, unsigned char Count);
void fosd_win_zoom(unsigned char winno, unsigned char zoomh, unsigned char zoomv);
void fosd_win_multicolor(unsigned char winno, unsigned char en);
void fosd_set_de(void);

#endif

