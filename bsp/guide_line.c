#include "main.h"

code unsigned short guide_line_lut[] = 
{ 
    0x0000, 
    0xFFFF, 
    0xFFE0, 
    0xF800, 
    0x0000, 
    0x0000, 
    0x44A1, 
    0x0000, 
    0x0000, 
    0x4E73, 
    0x1FCC, 
    0x1FDF, 
    0x44A4, 
    0x1FCC, 
    0x0000, 
    0x4E2D 
};

/* <GRID INFORMATION> */
code int Guide_linePos0[] = { 92, 15, 27, 2 };    // x, y, w, h
code char Guide_lineColor0[2][27] = {
{ 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
{ 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
};    // LUT no.s

code int Guide_linePos1[] = { 130, 128, 21, 3 };    // x, y, w, h
code char Guide_lineColor1[3][21] = {
{ 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00},
{ 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
{ 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01},
};    // LUT no.s

code int Guide_linePos2[] = { 34, 166, 12, 7 };    // x, y, w, h
code char Guide_lineColor2[7][12] = {
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01},
{ 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01, 0x02, 0x02},
{ 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02},
{ 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03},
{ 0x04, 0x04, 0x03, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04},
{ 0x05, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x05, 0x05, 0x05},
{ 0x03, 0x03, 0x03, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06},
};    // LUT no.s

code int Guide_linePos3[] = { 335, 168, 12, 7 };    // x, y, w, h
code char Guide_lineColor3[7][12] = {
{ 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{ 0x02, 0x02, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
{ 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02},
{ 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03},
{ 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x03, 0x04, 0x04},
{ 0x05, 0x05, 0x05, 0x03, 0x03, 0x03, 0x05, 0x05, 0x03, 0x03, 0x03, 0x05},
{ 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x03},
};    // LUT no.s

/* <CHAR POSITION DATA> */
code unsigned int Guide_lineChar[] = 
{
 0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F,
 0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017, 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F,
 0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
 0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x0043, 0x0044, 0x0045, 0x0046, 0x004D,
 0x004E, 0x004F, 0x005B, 0x005C, 0x005D, 0x0060, 0x0061, 0x0062, 0x0063, 0x0071, 0x0072, 0x0073, 0x0074, 0x007D, 0x007E, 0x007F,
 0x0080, 0x0087, 0x0088, 0x008B, 0x008C, 0x0092, 0x0093, 0x0094, 0x0095, 0x009C, 0x009D, 0x009E, 0x009F, 0x00A7, 0x00AB, 0x00AC,
 0x00AD, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7, 0x00B8, 0x00B9, 0x00BD, 0x00BE, 0x00BF, 0x00CA, 0x00CB, 0x00CC, 0x00D5,
 0x00D6, 0x00D9, 0x00DA, 0x00E5, 0x00E6, 0x00E7, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00FC, 0x00FD, 0x00FE, 0x0102, 0x0108, 0x0109,
 0x010A, 0x010D, 0x010E, 0x010F, 0x011A, 0x011B, 0x011C,
 0x0089, 0x008A, 0x00A8, 0x00A9, 0x00AA, 0x00D7, 0x00D8, 0x00FF, 0x0100, 0x0101
};

/* <FONT DATA> */
code unsigned char guide_line[][27] = 
{
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xF7,0x00,0x73,0x8F,0x00,0xE7,0x00,0x00,0xEE,0x00,0x00,0xEE,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x80,0xEC,0x33,0x88,0x2E,0x33,0x88,0x00,0x33,0xB9,0x00,0x33,0xCF,0x00,0x33,0x88},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0x00,0xF7,0xFF,0x31,0x8C,0x77,0x33,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0xF7,0x37,0xB9,0xCF,0xFF,0xBB,0x88},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x77,0x00,0x00,0x77,0x00,0xC8,0x77,0x11,0x4C,0x77,0x73,0x00,0x77,0xEE},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x11,0xCE,0x00,0x11,0x08,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0xFE,0x00,0xCF,0x1F,0x00,0xEC,0x00,0x11,0x7F,0xFC,0x11,0x00,0x3F,0x91},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0x33,0x88,0xCC,0x33,0x88,0xCC,0x33,0x88},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x77,0x77,0x77,0x8F,0x77,0x77,0x00,0x77},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x71,0xFF,0x8F,0xF7,0x1F,0x00,0xEE,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x77,0x00,0xEC,0x77,0x00,0xEE,0x77,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x11,0xDC,0xEE,0x11,0xEF,0xEE,0x11,0xCC},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0xF3,0x7F,0x98,0xEF,0x33,0x99,0xCC},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xC0,0xE0,0x11,0xCC,0xEE,0x11,0xCC,0x00,0xFD,0xCC,0xEE,0x3F,0xCC,0xEE,0x11,0xCC,0xEE},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x11,0xDC,0xFE,0x11,0xEF,0x7F,0x11,0xCC,0x33},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0xDD,0x98,0xEF,0x3F,0x99,0xCC,0x11},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0x73,0xEC,0xCC,0xEE,0x02,0xCC,0x7F,0xC0},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0x00,0x33,0x00,0x00,0xFF,0x00,0x00,0x3F,0x00,0x00,0x33},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0xFF,0x00,0x00,0x88,0x00,0x00,0xFF,0x30,0xFF,0x8F,0x73,0x8F,0x88,0x77,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE8,0x11,0xDD,0xFE,0x11,0xEF,0x77,0x11,0xCC},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x77,0xCC,0x00,0x77,0x0C,0x00,0x13,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xC8,0x00,0x0F,0x4C,0x00,0x80,0x00,0x31,0xFF,0xC0,0x23,0x03,0xEC,0x10},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x73,0x00,0x00,0x77,0xFF,0x91,0xFF,0x1F,0xCD,0x7F,0xF1,0xCC,0x77},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0xEE,0x00,0x00,0x00,0x00,0x00,0xEE,0x31,0xFF,0x0E,0xE7,0x01,0x00,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x77,0x00,0xD1,0xFF,0xFF,0xEF,0x7F,0x0E,0xEE,0x77,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0x11,0xCC,0xEE,0x33,0x88,0x77,0x73,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x00,0x00,0xEE,0x00,0x00,0xEE,0x00,0x00,0xEE,0x00,0x00,0xEE,0x00,0x00},
 {0x00,0x7F,0x80,0x00,0x37,0xFF,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x20,0x33,0x88,0xEE,0x33,0x88,0x0C,0x03,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x77,0x33,0xC8,0x77,0x11,0xFF,0x07,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x10,0x33,0xC8,0xFF,0x11,0xFF,0x0E,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x40,0x77,0x77,0xCC,0x77,0x13,0x08,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x80,0x00,0x10,0xEC,0x00,0x11,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x73,0x99,0xFF,0xFF,0x09,0x0F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xEC,0x73,0x88,0xFF,0xBF,0x88,0x07,0x03,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x77,0x00,0x77,0x77,0x00,0x77,0x07,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0xFE,0x10,0x00,0x77,0xFF,0x00,0x01,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xEE,0x77,0x90,0x8C,0x37,0xEF,0x00,0x01,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xEE,0x11,0xCC,0xEE,0x11,0xCC,0x0E,0x01,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x33,0x99,0xEC,0x33,0x88,0xFF,0x03,0x08,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x31,0xCC,0xEE,0xDF,0xCC,0xEE,0x09,0x0C,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x11,0xCC,0x33,0x11,0xCC,0x33,0x01,0x0C,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x99,0xEC,0x31,0x88,0xFF,0xDF,0x08,0x07,0x39,0x00,0xF8,0xF7,0x00,0x37,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xCC,0x03,0xFF,0xCC,0xF8,0xE7,0xCC,0x0F,0x0C,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x33,0x00,0x00,0x33,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x88,0x77,0x80,0x88,0x33,0xFF,0x08,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xF7,0x11,0xCC,0xCE,0x11,0xCC,0x08,0x01,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x40,0x00,0x00,0x77,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x10,0xEE,0x77,0xFF,0xCE,0x77,0x0F,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x1F,0xCC,0x77,0xF1,0xCC,0x77,0x0D,0x0C,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0xFE,0x00,0x00,0x77,0xFF,0x00,0x01,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x40,0x77,0x00,0xCC,0x77,0xEE,0x08,0x03,0x0E,0x00,0x00,0x10,0x00,0x00,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x33,0x67,0x00,0x13,0xEE,0x00,0x11,0xCC,0x00,0xF3,0x88,0x00,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0xEE,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0x00,0xF7,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x30,0xFF,0x10,0xF7,0xFF,0x73,0xFF,0xCE,0x00,0x0F,0x08,0xFF,0x08,0x00,0x8C,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xC0,0xEF,0x0F,0x0F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0x0F,0x0F,0x3F,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0xFF,0xE8,0x00,0xFF,0xFE,0x80,0x13,0xFF,0xFC,0x00,0x0F,0x08,0x00,0x00,0x7F,0x00,0x00,0x03},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xC8,0x00,0xFF,0xFE,0x80},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0x10,0xFF,0x00,0x73,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0xF3,0x00,0x01,0x0F,0x00,0x00,0x00,0xF3,0xFF,0xE8,0xFF,0xFF,0x8C,0xFF,0xEF,0x00,0xFF,0x8C,0x00},
 {0x31,0xFF,0xEF,0xFF,0xFF,0x8C,0xFF,0xCE,0x00,0x3F,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x37,0xFF,0xEE,0x00,0xFF,0xFF,0x00,0x13,0xFF,0x00,0x00,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0xC8,0x00,0x00,0xFE,0x80,0x00,0x0F,0x0C,0x00,0x00,0x00,0x00,0x30,0xFF,0xFE,0x01,0xFF,0xFF,0x00,0x37,0xFF,0x00,0x01,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xEC,0x00,0x00,0xFF,0x88,0x00,0xFF,0xFE,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0xF7},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x30,0xF0,0x10,0xFF,0xFF,0x73,0xFF,0xFF,0xFF,0xFF,0xEF,0xFF,0xFF,0x8C},
 {0x10,0xFF,0xFF,0xF7,0xFF,0xFF,0x0F,0x1F,0xCE,0x00,0x00,0x00,0xF0,0x00,0x00,0xEF,0x00,0x00,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xCE,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xFF,0xC8,0x7F,0xFF,0xFF,0x13,0xCF,0x0F,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x37,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x80,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0xF0,0xE0,0x00,0xFF,0xFF,0xC8,0xFF,0xFF,0xFE,0x37,0xFF,0xFF,0x01,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0x00,0x00,0xFF,0x80,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0xF7,0x00,0x31,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x30,0xF0,0x10,0xFF,0xFF,0x73,0xFF,0xFF,0xFF,0xFF,0xEF,0xFF,0xFF,0x8C,0xFF,0xEF,0x00},
 {0xF7,0xFF,0xFF,0x0F,0x1F,0xCE,0x00,0x00,0x00,0xF0,0x00,0x00,0xEF,0x00,0x00,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x31},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0x00,0xF7,0xFF,0x31,0xFF,0xFF,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xFF,0xFF,0xFF,0x0F,0x0F,0x0F,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xE8,0x00,0x7F,0x8E,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x71,0x00,0x00,0x01,0x00,0x00,0x00,0x10,0xF0,0xE0},
 {0x00,0x00,0xF7,0x00,0x31,0xFF,0x00,0xF7,0xFF,0x31,0xFF,0xFF,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xFF,0xFF,0xFF,0xFF,0xCF,0xFF,0xFF,0x88,0xFF,0xEF,0x00,0xFF,0x8C,0x00,0xEF,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x73},
 {0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x73,0x00,0x10,0xFF,0x00,0x73,0xFF,0x10,0xFF,0xFF,0x73,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x73,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEF,0xFF,0xFF,0xCC,0xFF,0xFF,0x08,0xFF,0xCE,0x00,0xFF,0x08,0x00},
 {0xFF,0xC8,0x00,0xFF,0x8C,0x00,0xEF,0x00,0x00,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x73,0x00,0x00,0xFF,0x00,0x31,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFC,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xE0,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x33,0x00,0x00,0xF7,0x00,0x31,0xFF,0x00,0xF7,0xFF,0x31,0xFF,0xFF},
 {0x00,0xF7,0xFF,0x31,0xFF,0xFF,0x77,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEF},
 {0xFF,0xFF,0xFF,0xFF,0xFF,0xEF,0xFF,0xFF,0x8C,0xFF,0xFF,0x08,0xFF,0xCE,0x00,0xFF,0x08,0x00,0xCE,0x00,0x00,0x8C,0x00,0x00,0x00,0x00,0x00},
 {0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x0F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xFF,0xFF,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xFF,0xFF,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xCE,0x00,0xFF,0x8C,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x73,0x00,0x10,0xFF,0x00,0x31,0xFF,0x00,0x03,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x73,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x0F,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xFF,0x8C,0xFF,0xEF,0x00,0xFF,0xCE,0x00,0xFF,0x88,0x00,0xEF,0x00,0x00,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x37,0x8F,0x0F,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x7F,0x00,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x08,0x00,0x00,0x00,0x00,0x00,0xF0,0xC0,0x00,0xFF,0xFF,0x80,0xFF,0xFF,0xEC,0x7F,0xFF,0xFF,0x13,0xFF,0xFF,0x00,0x7F,0xFF,0x00,0x13,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xFE,0x00,0x00,0xFF,0xC8,0x00,0xFF,0xFE,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x71,0xFF,0x00,0x13,0xEF,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFF,0xFF,0xFF,0x0F,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x80,0x00,0xFF,0xEE,0x00,0xFF,0xFF,0xC8,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0x00,0x00,0xFE,0x00,0x00},
 {0x7F,0xFF,0xFF,0x13,0xFF,0xFF,0x00,0x7F,0xFF,0x00,0x13,0xFF,0x00,0x00,0x37,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xC8,0x00,0xFF,0xFE,0x00,0xFF,0xFF,0xC8,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xEF,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x71,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE8,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x70,0xF0,0x80,0xFF,0xFF,0xEC},
 {0x00,0x13,0xFF,0x00,0x00,0x7F,0x00,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0x33,0xFF,0xFF,0x01,0xFF,0xFF,0x00,0x37,0xFF,0x00,0x01,0xFF,0x00,0x00,0x77},
 {0x80,0x00,0x00,0xEC,0x00,0x00,0xFF,0x80,0x00,0xFF,0xEC,0x00,0xFF,0xFF,0x80,0xFF,0xFF,0xEC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xEC,0x00,0x00,0xFF,0x80,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF3,0x00,0x33,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0xFC,0x00,0x00,0xFF,0x88,0x00,0xFF,0xEC,0x00,0xFF,0xFF,0x80},
 {0x00,0x00,0xFF,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xFF,0x8F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x7F,0xFF,0xFF,0x13,0xFF,0xFF,0x01,0xFF,0xFF,0x00,0x37,0xFF,0x00,0x01,0xFF,0x00,0x00,0x37,0x00,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xFF,0xCC,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0x33,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0x00,0x00,0xFE,0x00,0x00,0xFF,0xC8,0x00,0xFF,0xEE,0x00,0xFF,0xFF,0x80,0xFF,0xFF,0xEC,0xFF,0xFF,0xFE},
 {0x00,0x7F,0xFF,0x00,0x37,0xFF,0x00,0x11,0xFF,0x00,0x00,0x7F,0x00,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0xE8,0x00,0x00,0xFE,0x00,0x00,0xFF,0xC8,0x00,0xFF,0xEC,0x00,0xFF,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x80,0x00,0xFF,0xFF,0xFF,0xFF,0xCF,0x0F,0xFF,0x8C,0x00,0xEF,0x00,0x00},
 {0x00,0xF7,0xFF,0x31,0xFF,0xFF,0x0F,0x0F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0xF0,0x3F,0xFF,0xFF,0x00,0x00,0x03,0x00,0x00,0x00},
 {0xFF,0x8C,0x00,0xEF,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0xF7,0x00,0x31,0xFF,0x00,0x00,0x0F,0x00,0x00,0x00,0x70,0x80,0x00,0xFF,0xFF,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x80,0x00,0xFF,0xFF,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEF,0x00,0x01,0x08,0x00,0x00,0x00,0xF0,0xC0,0x00,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xCF,0x7F,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xC0,0x00,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xCF,0x7F,0xFF},
 {0xCE,0x00,0x00,0x88,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF3,0xFF,0xFF,0xFF,0xCF,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x7F,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xF0,0xFF,0xFF,0xFF,0x0F,0x3F,0xFF,0x00,0x13,0xFF,0x00,0x00,0x7F,0x00,0x00,0x13},
 {0xFF,0xFF,0xC8,0xFF,0xFF,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x00,0x00,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xCF,0x0F,0x00},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xCF,0x0F,0x00},
 {0xFF,0xFF,0xFF,0x77,0xFF,0xFF,0x01,0x08,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEF,0x3F,0x00,0x00,0x01},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEF,0x3F,0x00,0x00,0x01},
 {0xFF,0xEC,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xF0,0xF3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
 {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xF0,0xF3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
};

/* <DISPLAY DATA> */
code unsigned char Guide_lineDisplay[] = 
{
 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10,
 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30,
 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x00, 0x00, 0x00, 0x00, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x00,
 0x00, 0x00, 0x00, 0x3C, 0x3D, 0x3E, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x41, 0x42,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x44, 0x45, 0x00, 0x00,
 0x46, 0x47, 0x48, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x4A, 0x4B, 0x4C, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4E, 0x4F, 0x50,
 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x53, 0x88, 0x8A, 0x54, 0x55, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x56, 0x57, 0x58, 0x59, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5A, 0x5B, 0x5C, 0x5D,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5E, 0x8C, 0x8E, 0x90, 0x5F, 0x60, 0x61, 0x00, 0x00,
 0x00, 0x00, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x00, 0x00, 0x00, 0x6A, 0x6B, 0x6C,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6D, 0x6E, 0x6F, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x71, 0x92, 0x94, 0x72, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x75, 0x76, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x77, 0x78, 0x79, 0x7A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7B, 0x7C, 0x7D, 0x96,
 0x98, 0x9A, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x80, 0x81, 0x00, 0x00, 0x82, 0x83, 0x84,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x85, 0x86, 0x87
};

void guide_display(void)
{
    U16 i, RamStart0, RamStart1, RamStart2, RamStart3;
	U8 j;

	fosd_download_font_direct(0, &guide_line[0][0], NO_OF_FONTS, FONT_WIDTH, FONT_HEIGHT);

	tw884x_write(0xff, FONT_OSD_PAGE);
	
#ifdef START2BIT
	if (START2BIT >= 256) 
		tw884x_write(0x0D, tw884x_read(0x0D) | 1);		// set bit0
	else
		tw884x_write(0x0D, tw884x_read(0x0D) & ~1);		// clear bit0
    
	tw884x_write(0x10, START2BIT);						// 2bit multi color start
#else
	tw884x_write(0x0D, tw884x_read(0x0D) | 2);			// set bit1
	tw884x_write(0x10, 0xFF);							// 2bit multi color start = 1FF
#endif

#ifdef Start3bit
	if (Start3bit >= 256) 
		tw884x_write(0x0D, tw884x_read(0x0D) | 2);		// set bit2
	else
		tw884x_write(0x0D, tw884x_read(0x0D) & ~2);		// clear bit2
    
	tw884x_write( 0x0F, Start3bit );						// 3bit multi color start
#else
	tw884x_write(0x0D, tw884x_read(0x0D) | 2);			// set bit2
	tw884x_write(0x0F, 0xFF);							// 3bit multi color start = 1FF
#endif

#ifdef Start4bit
	if (START2BIT >= 256) 
		tw884x_write(0x0D, tw884x_read(0x0D) | 4);		// set bit3
	else
		tw884x_write(0x0D, tw884x_read(0x0D) & ~4);		// clear bit3
    
	tw884x_write(0x0E, Start4bit);						// 4bit multi color start
#else
	tw884x_write(0x0D, tw884x_read(0x0D) | 4);			// set bit1
	tw884x_write(0x0E, 0xFF);							// 4bit multi color start = 1FF
#endif

	fosd_lut((U16 *)guide_line_lut, 0, 16);		// LUT download

	if (Guide_linePos0 != 0L) 
    {
		fosd_win_screen(0, Guide_linePos0[0]*ZOOM_H, Guide_linePos0[1]*ZOOM_V,Guide_linePos0[2], Guide_linePos0[3], 0, 0);
		fosd_win_alpha(0, 0, 15);
		fosd_win_zoom(0, ZOOM_H-1, ZOOM_V-1);
		RamStart0 = 0;
		fosd_win_ram_start(0,RamStart0);
		RamStart1 = RamStart0 + (U16)Guide_linePos0[2]* (U16)Guide_linePos0[3];
		fosd_win_multicolor(0, 1);
	}

    if (Guide_linePos1 != 0L)
    {
		fosd_win_screen(1, Guide_linePos1[0]*ZOOM_H, Guide_linePos1[1]*ZOOM_V,Guide_linePos1[2], Guide_linePos1[3], 0, 0);
		fosd_win_alpha(1, 0, 15);
		fosd_win_zoom(1, ZOOM_H-1, ZOOM_V-1);
		fosd_win_ram_start(1,RamStart1);
		RamStart2 = RamStart1 + (U16)Guide_linePos1[2]* (U16)Guide_linePos1[3];
		fosd_win_multicolor(1, 1);
	}
    
	if (Guide_linePos2 != 0L)
    {
		fosd_win_screen(2, Guide_linePos2[0]*ZOOM_H, Guide_linePos2[1]*ZOOM_V,Guide_linePos2[2], Guide_linePos2[3], 0, 0);
		fosd_win_alpha(2, 0, 15);
		fosd_win_zoom(2, ZOOM_H-1, ZOOM_V-1);
		fosd_win_ram_start(2,RamStart2);
		RamStart3 = RamStart2 + (U16)Guide_linePos2[2] * (U16)Guide_linePos2[3];
		fosd_win_multicolor(2, 1);
	}

	if (Guide_linePos3 != 0L)
    {
		fosd_win_screen(3, Guide_linePos3[0]*ZOOM_H, Guide_linePos3[1]*ZOOM_V,Guide_linePos3[2], Guide_linePos3[3], 0, 0);
		fosd_win_alpha(3, 0, 15);
		fosd_win_zoom(3, ZOOM_H-1, ZOOM_V-1);
		fosd_win_ram_start(3,RamStart3);
		fosd_win_multicolor(3, 1);
	}

	tw884x_write(0x01, tw884x_read(0x01)&~4); 			// OSD RAM Auto Access Enable

	tw884x_write(0x01, (tw884x_read(0x01)&0xCF)); 		// Normal
	tw884x_write(0x02, tw884x_read(0x02)&0xFE);					// Font address bit8 clear

	// FILL blank font, 00, 00
	for (i = 0; i < NO_OF_CHARS; i++)
    {
		if (i < 256)
        {
			tw884x_write(0x02, tw884x_read(0x02)&0xFE);		// clear
		}
		else 
        {
			tw884x_write(0x02, tw884x_read(0x02)|1);			// Set
		}

        tw884x_write(0x03, (U8)i);					// Font OSD RAM address

		if (Guide_lineDisplay[i] < 256) 
			tw884x_write(0x04, tw884x_read(0x04)&~1);			// clear
		else
			tw884x_write(0x04, tw884x_read(0x04)|1);			// Set
			
		tw884x_write(0x05, Guide_lineDisplay[i]&0xFF);			// Font Data

		if (Guide_lineDisplay[i] < START2BIT) 
        {
			if (i < RamStart1)
            {
				tw884x_write(0x06, Guide_lineColor0[i]);			        // Font Attribute
			}
			else if (i < RamStart2)
            {
				tw884x_write(0x06, Guide_lineColor1[i-RamStart1]);			// Font Attribute
			}
			else if (i < RamStart3)
            {
				tw884x_write(0x06, Guide_lineColor2[i-RamStart2]);			// Font Attribute
			}
			else
            {
				tw884x_write(0x06, Guide_lineColor3[i-RamStart3]);			// Font Attribute
			}
		}
		else
        {
			tw884x_write(0x06, 0);			// Font Attribute for Multi Color
		}
	}

	for (j = 0; j < 4; j++) 
    {
		fosd_win_enable(j, TRUE);
	}
}

