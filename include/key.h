#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"

SBIT(MODE_KEY, SFR_P3, 0);

//#define KEY_INPUT   (MODE_KEY)
#define KEY_INPUT   (~P3 & 0x3F)

#define KEY_MODE	    0x01
#define KEY_ENTER	    0x02
#define KEY_UP		    0x04
#define KEY_DOWN	    0x08
#define KEY_LEFT	    0x10
#define KEY_RIGHT	    0x20

#define KEY_L_MODE	    (KEY_MODE  | 0x80)
#define KEY_L_ENTER	    (KEY_ENTER | 0x80)
#define KEY_L_UP		(KEY_UP    | 0x80)
#define KEY_L_DOWN	    (KEY_DOWN  | 0x80)
#define KEY_L_LEFT	    (KEY_LEFT  | 0x80)
#define KEY_L_RIGHT	    (KEY_RIGHT | 0x80)

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

