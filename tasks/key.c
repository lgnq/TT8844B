#include "key.h"
 
unsigned char key_read(void) 
{ 
    static unsigned char key_state = KEY_STATE_0, key_time = 0; 
    unsigned char key_press, key_return = N_KEY; 

    key_press = KEY_INPUT; 

    switch (key_state) 
    { 
        case KEY_STATE_0: 
            if (!key_press) 
                key_state = KEY_STATE_1;
        break; 
        
        case KEY_STATE_1:               
            if (!key_press) 
            { 
                key_time = 0;           
                key_state = KEY_STATE_2;
            } 
            else 
                key_state = KEY_STATE_0;
        break; 
        
        case KEY_STATE_2: 
            if (key_press) 
            { 
                key_return = S_KEY;     
                key_state = KEY_STATE_0;
            } 
            else if (++key_time >= 100) 
            { 
                key_return = L_KEY;     
                key_state = KEY_STATE_3;
            } 
        break; 

        case KEY_STATE_3:               
            if (key_press) 
                key_state = KEY_STATE_0;
        break; 
    } 

    return key_return; 
}

void key_init(void)
{
}

void key_update(void)
{
    unsigned char key;
    
    key = key_read(); 
    
    if (key == L_KEY)  
        putc('L');
    else if (key == S_KEY)  
        putc('S');
}

