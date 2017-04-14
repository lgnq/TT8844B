#include "key.h"

void key_init(void)
{
}

unsigned char key_read(void) 
{ 
    static unsigned char key_state = KEY_STATE_0, key_time = 0, key_temp = N_KEY; 
    unsigned char key_value, key_press, key_return = N_KEY; 

    key_value = KEY_INPUT; 

    if (key_value == 0)
    {
        //LED_G = 0;
        key_press = 0;
    }
    else
    {
        //LED_G = 1;
        key_press = 1;
    }
    
    switch (key_state) 
    { 
        case KEY_STATE_0: 
            if (key_press)
            {
                key_temp = key_value;
                key_state = KEY_STATE_1;
            }
        break; 
        
        case KEY_STATE_1:               
            if ((key_press) && (key_temp == key_value)) 
            { 
                key_time = 0;           
                key_state = KEY_STATE_2;
            } 
            else 
                key_state = KEY_STATE_0;
        break; 
        
        case KEY_STATE_2: 
            if (!key_press) 
            { 
                key_return = key_temp;     
                key_state = KEY_STATE_0;
            } 
            else
            {
                if (key_temp == key_value)
                    key_time++;
                else
                    key_state = KEY_STATE_0;
                
                if (key_time >= 100) 
                { 
                    key_return = key_temp | 0x80;     
                    key_state = KEY_STATE_3;
                }
            }
        break; 

        case KEY_STATE_3:               
            if (!key_press) 
                key_state = KEY_STATE_0;
        break; 

        default:
            key_state = KEY_STATE_0;
        break;
    } 

    return key_return; 
}

void key_update(void)
{
    unsigned char key;
    
    key = key_read(); 

    if (key != N_KEY)
    {
        switch (key)
        {
            case KEY_MODE:
                putc('m');
                guide_display();  //WDT!?
                break;
            case KEY_ENTER:
                putc('e');
                break;
            case KEY_UP:
                putc('u');
                break;
            case KEY_DOWN:
                putc('d');
                break;
            case KEY_RIGHT:
                putc('r');
                break;
            case KEY_LEFT:
                putc('l');
                break;
                
            case KEY_L_MODE:
                putc('M');
                break;
            case KEY_L_ENTER:
                putc('E');
                break;
            case KEY_L_UP:
                putc('U');
                break;
            case KEY_L_DOWN:
                putc('D');
                break;
            case KEY_L_RIGHT:
                putc('R');
                break;
            case KEY_L_LEFT:
                putc('L');
                break;
            
            default:
                putc('x');
                break;                    
        }
    }
}

