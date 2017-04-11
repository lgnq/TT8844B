#include "main.h"

code unsigned char FontOsdWinBase[] = 
{ 
    FONTWIN1_ST, 
    FONTWIN2_ST, 
    FONTWIN3_ST, 
    FONTWIN4_ST 
};

#if 0
/*	
SPI OSD DE delay calculation 
HDE = REG(0x210[7:0])
Mixing = REG(0x400[1:1])

result = HDE - ( Mixing +41 )
*/ 
void fosd_de_set(void)
{
	char tmp;

	tw884x_write(0xff, 2);
	tmp = tw884x_read(0x10);				// HDE
    
	tw884x_write(0xff, 4);
	if (tw884x_read(0x00) & 2) 
    {
        // check Mixing
		tmp--;
	}
	tmp -= 41;
	
	///WaitVBlankVS1(1);				// Wait Vblank()

	tw884x_write(0xff, FONT_OSD_PAGE);

	tw884x_write(0x03, tmp);   				// write FONT OSD DE value
}
#endif

//=============================================================================
//		void FOSDEnable(unsigned char en) // if OSD OFF cannot write any OSD data
//=============================================================================
void fosd_enable(unsigned char en)
{
	tw884x_write(0xff, FONT_OSD_PAGE);

	if (en == 0) 
    {
		tw884x_write(0x00, tw884x_read(0x00) | 0x80);   				// enable Font OSD
	}
	else
    {
		tw884x_write(0x00, tw884x_read(0x00) & ~0x80);   				// disable Font OSD
	}
}

void fosd_win_enable(unsigned char winno, unsigned char en)
{
	xdata unsigned char idx;
	xdata unsigned char dat;

	idx = FontOsdWinBase[winno] + FONTWIN_ENABLE;

	dat = tw884x_read(idx);
	if (en)
        tw884x_write(idx, dat | 0x80);
	else
        tw884x_write(idx, dat & 0x7F);
}

void fosd_win_multicolor(unsigned char winno, unsigned char en)
{
	xdata unsigned char idx;
	xdata unsigned char dat;

	idx = FontOsdWinBase[winno];

	tw884x_write(0xff, FONT_OSD_PAGE);

	dat = tw884x_read(idx);
	if (en)
        tw884x_write(idx, dat | 0x40);
	else
        tw884x_write(idx, dat & ~0x40);
}

void fosd_win_alpha(unsigned char winno, unsigned char color, unsigned char alpha)
{
	unsigned char idx = FontOsdWinBase[winno] + FONT_ALPHA;

	tw884x_write(0xff, FONT_OSD_PAGE);

    tw884x_write(0x13, color);          // first select color
	tw884x_write(idx, alpha);			// second write alpha value
}

unsigned int fosd_get_winx(unsigned char winno)
{
	xdata unsigned char idx;
	xdata unsigned int Pos;

	tw884x_write(0xff, FONT_OSD_PAGE);

	idx = FontOsdWinBase[winno];

	Pos = tw884x_read(idx+2) & 0x70;
	Pos <<= 4;
	Pos += tw884x_read(idx+3);

	return (Pos);
}

void fosd_set_winx(unsigned char winno, unsigned int x)
{
	xdata unsigned char idx;

	tw884x_write(0xff, FONT_OSD_PAGE);

	idx = FontOsdWinBase[winno];

	tw884x_write(idx+2, (tw884x_read(idx+2)&0x8F) | ((x>>4)&0x70));
	tw884x_write(idx+3, x);
}

unsigned int fosd_get_winy(unsigned char winno)
{
	xdata unsigned char idx;
	xdata unsigned int Pos;

	tw884x_write(0xff, FONT_OSD_PAGE);

	idx = FontOsdWinBase[winno];

	Pos = tw884x_read(idx+2) & 0x03;
	Pos <<= 8;
	Pos += tw884x_read(idx+4);

	return (Pos);
}

void fosd_set_winy(unsigned char winno, unsigned int y)
{
	xdata unsigned char idx;

	tw884x_write(0xff, FONT_OSD_PAGE);

	idx = FontOsdWinBase[winno];

	tw884x_write(idx+2, (tw884x_read(idx+2)&0xFC)|(y>>8));
	tw884x_write(idx+4, y);
}

void fosd_win_screen(unsigned char winno, unsigned int x, unsigned int y, unsigned char w, unsigned char h, unsigned char zoomH, unsigned char zoomV)
{
	unsigned char idx;
	unsigned char tmp;

	idx = FontOsdWinBase[winno];

	tw884x_write(0xff, FONT_OSD_PAGE);
    
	tmp = zoomH * 4 + zoomV;
	tmp += (tw884x_read(idx) & 0xf0);
	tw884x_write(idx, tmp);				// write Zoom value

	tmp = x >> 8;
	tmp <<= 4;
	tmp += (y >> 8);
	tw884x_write(idx+2, tmp);			// upper bit for position x, y
	tw884x_write(idx+3, x);				// position x
	tw884x_write(idx+4, y);				// position y
	tw884x_write(idx+5, h);
	tw884x_write(idx+6, w);
}

void fosd_win_style(unsigned char winno, unsigned char bdOn, unsigned char bdColor, unsigned char bdWidth, unsigned char bdSpaceH, unsigned char bdSpaceV, unsigned char chSpaceH, unsigned char chSpaceV)
{
	xdata unsigned char idx, tmp;

	idx = FontOsdWinBase[winno];

	tw884x_write(0xff, FONT_OSD_PAGE);
    
	if (bdOn)
		tw884x_write(idx+9, tw884x_read(idx+9)|0x80);		// enable boarder
	else
		tw884x_write(idx+9, tw884x_read(idx+9)&~0x80);	// disable boarder

	tw884x_write(idx+7, (tw884x_read(idx+7)&0x0F)|(bdColor<<4));		// set boarder color
	tw884x_write(idx+9, (tw884x_read(idx+9)&0xE0)|(bdWidth));		// set boarder width
	tw884x_write(idx+0xE, (tw884x_read(idx+0xE)|(bdSpaceH)));				// set boarder space H
	tw884x_write(idx+0xF, (tw884x_read(idx+0xF)|(bdSpaceV)));				// set boarder space V

	tmp = chSpaceH<<4;
	tmp += (chSpaceV&0x0f);
	tw884x_write(idx+0xC, tmp);										// set ch space
}

void fosd_win_zoom(unsigned char winno, unsigned char zoomh, unsigned char zoomv)
{
	xdata unsigned char idx;
	xdata unsigned char zoom;

	tw884x_write(0xff, FONT_OSD_PAGE);

    idx = FontOsdWinBase[winno];

	zoom = zoomh * 4 + zoomv;
	tw884x_write(idx, tw884x_read(idx) & 0xF0 | zoom);			// second write alpha value
}

void fosd_win_ram_start(unsigned char winno, unsigned int start)
{
	unsigned char idx = FontOsdWinBase[winno];

	tw884x_write(0xff, FONT_OSD_PAGE);

	tw884x_write(idx+0x07, (tw884x_read(idx+0x07)&~0x03)+(start>>8));   	// bit9:bit8
	tw884x_write(idx+0x08, start);			// second write alpha value
}

void fosd_lut(unsigned int *PalettePtr, unsigned char StartAddr, unsigned char Count)
{
    unsigned char i, j;

	///WaitVBlankVS1(1);	

	tw884x_write(0xff, FONT_OSD_PAGE);

	j = tw884x_read(0x0A) & 0xC0;
	for (i = StartAddr; i < (StartAddr+Count); i++) 
    {
		tw884x_write(0x0A, j | i);			// select address
		tw884x_write(0x0B, *PalettePtr>>8);
		tw884x_write(0x0C, *PalettePtr);
		PalettePtr++;
	}
}

void auto_increment_control(unsigned char onoff)
{
    unsigned char val;
    
    tw884x_write(0xFF, 0x0);

    val = tw884x_read(0x06);
    
    if (onoff == ON)
    {
        val &= ~0x20;
    }
    else
    {
        val |= 0x20;
    }
}

void fosd_download_font_direct(unsigned char dest_font_idx, unsigned char *src_loc, unsigned int fSize, unsigned char width, unsigned char height)
{
	unsigned char val;
	unsigned int i, FontSize, FontIndex, j;

	//save clock mode & select PCLK
	WaitVBlankVS1(1);	

    auto_increment_control(ON);

	tw884x_write(0xFF, FONT_OSD_PAGE);

	val = tw884x_read(0x00);	
	if (width == 16)
		val |= 0x10;	   				//width 16
	else
		val &= 0xEF;					//   or 12
	tw884x_write(0x00, val);  

	tw884x_write(0x01, (tw884x_read(0x01) | 0x04)); 						//FontRAM access
    
	tw884x_write(0x07, 0); 		            //Test only under 256
	tw884x_write(0x08, dest_font_idx); 		//Font Addr
	tw884x_write(0x11, height >> 1); 		//Font height(2~32)

	i = 0;
	FontSize = (unsigned int) width * height / 8;
	tw884x_write(0x12, FontSize);	//sub-font total count.

	FontIndex = dest_font_idx;
	FontIndex *= FontSize;
	for (i = 0; i < fSize; i++) 
	{
#if 1	
		tw884x_write(0x08, i); 		//Font Addr low 8bit
#else
        tw884x_write( 0x07, (FontIndex>>8) );      //Font Addr high 8bit
        tw884x_write( 0x08, FontIndex );       //Font Addr low 8bit
#endif

#if 0
		tw884x_writen(0x09, &src_loc[i*FontSize], FontSize);
#else        
        for (j = 0; j < FontSize; j++)
        {
            tw884x_write(0x09, src_loc[i*FontSize + j]);
            //tw884x_write(0x09, 0xFF);
        }
#endif

		FontIndex += FontSize; 
	}
	
	tw884x_write(0x01, (tw884x_read(0x01) & ~0x04));		// FONT RAM access mode OFF

    auto_increment_control(OFF);
}

#if 1
//=============================================================================
//				   void FOSDDefaultLUT( unsigned char n ) // dump every Color LUTs
//=============================================================================
void fosd_ramp_lut(unsigned char n)
{
    unsigned char i;

	WaitVBlankVS1(1);	

	tw884x_write(0xff, FONT_OSD_PAGE);

	if (n == 0) 
    {
        // gray pattern
		for (i = 0; i < 64; i++) 
        {
			tw884x_write(0x0A, i);			// select address
			tw884x_write(0x0B, (i>>3)|((i>>1)<<3));
			tw884x_write(0x0C, (i>>1)|(i<<5));
		}
	}
	else if (n == 1) 
    {       
        // Red pattern
		for (i = 0; i < 64; i++) 
        {
			tw884x_write(0x0A, i);			// select address
			tw884x_write(0x0B, 0x00);
			tw884x_write(0x0C, (i>>1));
		}
	}
	else if (n == 2) 
    {
        // Green pattern
		for (i = 0; i < 64; i++)
        {
			tw884x_write(0x0A, i);			// select address
			tw884x_write(0x0B, (i>>3));
			tw884x_write(0x0C, (i<<5));
		}
	}
	else if (n == 3) 
    {
        // Blue pattern
		for (i = 0; i < 64; i++)
        {
			tw884x_write(0x0A, i);			// select address
			tw884x_write(0x0B, ((i>>1)<<3));
			tw884x_write(0x0C, 0x0);
		}
	}
}

void fosd_display_lut(void)
{
	unsigned char val, i, width, height;

	width = 16; 
    height = 16;		// makes 16x16 FONT

	//save clock mode & select PCLK
	WaitVBlankVS1(1);	

    tw884x_write(0xFF, FONT_OSD_PAGE);

	val = tw884x_read(0x00);	
	if (width == 16)
        val |= 0x10;                  //width 16
	else
        val &= 0xEF;                  //   or 12

	tw884x_write(0x00, val);  

	tw884x_write(0x01, 0x04); 						//FontRAM access
	tw884x_write(0x11, height >> 1); 				//Font height(2~32)
	tw884x_write(0x12, (width >> 2) * (height >> 1));	//sub-font total count.

	tw884x_write(0x08, 0); 		//Font Addr	 0
	for ( i=0; i<8; i++) 
    {
		tw884x_write(0x09, 0x00 );
		tw884x_write(0x09, 0x00 );
		tw884x_write(0x09, 0xFF );
		tw884x_write(0x09, 0xFF );
	}

    tw884x_write(0x08, 1); 		//Font Addr	 1
	for (i=0; i<8; i++ )
    {
		tw884x_write(0x09, 0x00 );
		tw884x_write(0x09, 0xFF );
		tw884x_write(0x09, 0x00 );
		tw884x_write(0x09, 0xFF );
	}

	tw884x_write(0x01, 0);		// OSD RAM access mode OFF	 and all effect off

	tw884x_write(0x02, tw884x_read(0x02)&0xFC);
	for (i=0; i<64; i++ )
    {
		tw884x_write(0x03, i );					// Font address
		tw884x_write(0x05, 0 );					// Font Data
		tw884x_write(0x06, i );		   			// attribute - Select LUT position
	}

	tw884x_write(0x0D, 0x00 );
	tw884x_write(0x10, 0 );				// 2bit multi color start = 0
	tw884x_write(0x0f, 0xFF );				// 3bit multi color start = 0
	tw884x_write(0x0e, 0xFF );			// 4bit multi color start = 0

	fosd_win_screen(3, 50, 100, 16, 4, 1, 1);
	fosd_win_multicolor(3, 1);
	fosd_win_ram_start(3, 0);
	fosd_win_enable(3, 1);
}

void fosd_display_string(unsigned int pos, unsigned char *str, unsigned char attr)
{
    tw884x_write(0xFF, FONT_OSD_PAGE);
	
	tw884x_write(0x00, tw884x_read(0x00)&(~0x03));		// clear BYPASS OSD FIFO
	tw884x_write(0x01, tw884x_read(0x01)&(~0x34));		// OSD RAM Access with Normal

	while (*str)
    {
		i2c_write(0x88, 0x02, pos);		// write upper 2 bits
		tw884x_write(0x04, 0x00);			// clear 9th bit
		tw884x_write(0x05, *str);
		tw884x_write(0x06, attr);

        pos++;
		str++;
	};						// until met NULL char
}

void fosd_clear_display(unsigned int pos, unsigned char attr, unsigned int cnt)
{
    tw884x_write(0xFF, FONT_OSD_PAGE);
	
	tw884x_write(0x00, tw884x_read(0x00)&(~0x03));		// clear BYPASS OSD FIFO
	tw884x_write(0x01, tw884x_read(0x01)&(~0x34));		// OSD RAM Access with Normal

	while (cnt--) 
    {
		tw884x_write(0x02, pos>>8);		// write upper 2 bits
		tw884x_write(0x03, pos);			// write low 8 bits
		tw884x_write(0x04, 0x00);			// clear 9th bit
		tw884x_write(0x05, ' ');				// font number
		tw884x_write(0x06, attr);			// attribute

        pos++;
	}
}

void fosd_set_de(void)
{
	unsigned char tmp;

	tw884x_write(0xff, 0x02);
	tmp = tw884x_read(0x15);	// read 0x215
	tmp -= 37;
    
	tw884x_write(0xff, 0x03);
	tw884x_write(0x14, tmp);
}
#endif

