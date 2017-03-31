#include "main.h"
#include "key.h"

#define key_input    KEY_MODE

#define N_key    0
#define S_key    1
#define D_key    2
#define L_key    3

#define key_state_0 0 
#define key_state_1 1 
#define key_state_2 2 
#define key_state_3 3 
 
unsigned char key_driver(void) 
{ 
    static unsigned char key_state = key_state_0, key_time = 0; 
    unsigned char key_press, key_return = N_key; 

    key_press = key_input; 

    switch (key_state) 
    { 
        case key_state_0: 
            if (!key_press) 
                key_state = key_state_1;
        break; 
        
        case key_state_1:               
            if (!key_press) 
            { 
                key_time = 0;           
                key_state = key_state_2;
            } 
            else 
                key_state = key_state_0;
        break; 
        
        case key_state_2: 
            if (key_press) 
            { 
                key_return = S_key;     
                key_state = key_state_0;
            } 
            else if (++key_time >= 100) 
            { 
                key_return = L_key;     
                key_state = key_state_3;
            } 
        break; 

        case key_state_3:               
            if (key_press) 
                key_state = key_state_0;
        break; 
    } 

    return key_return; 
} 

unsigned char key_read(void) 
{ 
    static unsigned char key_m = key_state_0, key_time_1 = 0; 
    unsigned char key_return = N_key, key_temp; 
      
    key_temp = key_driver(); 
      
    switch (key_m) 
    { 
        case key_state_0: 
            if (key_temp == S_key) 
            { 
                key_time_1 = 0;         
                key_m = key_state_1; 
            } 
            else 
                key_return = key_temp;  
        break; 

        case key_state_1: 
            if (key_temp == S_key)      
            { 
                key_return = D_key;     
                key_m = key_state_0; 
            } 
            else                                
            {                            
                if (++key_time_1 >= 50) 
                { 
                    key_return = S_key; 
                    key_m = key_state_0; 
                } 
            } 
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
    
    if (key == L_key)  
        putc('L');
    else if (key == D_key)  
        putc('D');
    else if (key == S_key)  
        putc('S');
}
