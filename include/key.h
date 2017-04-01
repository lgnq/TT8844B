#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"

SBIT(MODE_KEY, SFR_P3, 0);

#define KEY_INPUT   (MODE_KEY)
//#define KEY_INPUT   (~P3 & 0x3F)

#define KEY_MODE	    0x01
#define KEY_ENTERKEY	0x02
#define KEY_UPKEY		0x04
#define KEY_DOWNKEY	    0x08
#define KEY_LEFTKEY	    0x10
#define KEY_RIGHTKEY	0x20

#define N_KEY       0
#define S_KEY       1
#define D_KEY       2
#define L_KEY       3

#define KEY_STATE_0 0 
#define KEY_STATE_1 1 
#define KEY_STATE_2 2 
#define KEY_STATE_3 3 

void key_init(void);
void key_update(void);

#endif

