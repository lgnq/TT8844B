#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"

SBIT(KEY_MODE, SFR_P3, 0);

#define KEY_INPUT   KEY_MODE

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

