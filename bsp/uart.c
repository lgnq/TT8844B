#include "main.h"

bit RS_Xbusy = 0;

void uart0_init(void)
{
    SCON0 = 0x10;                       // SCON0: 8-bit variable bit rate
                                        //        level of STOP bit is ignored
                                        //        RX enabled
                                        //        ninth bits are zeros
                                        //        clear RI0 and TI0 bits
    if (SYSCLK/BAUDRATE0/2/256 < 1) 
    {
        TH1 = -(SYSCLK/BAUDRATE0/2);
        CKCON &= ~0x0B;                  // T1M = 1; SCA1:0 = xx
        CKCON |=  0x08;
    } 
    else if (SYSCLK/BAUDRATE0/2/256 < 4) 
    {
        TH1 = -(SYSCLK/BAUDRATE0/2/4);
        CKCON &= ~0x0B;                  // T1M = 0; SCA1:0 = 01
        CKCON |=  0x01;
    } 
    else if (SYSCLK/BAUDRATE0/2/256 < 12) 
    {
        TH1 = -(SYSCLK/BAUDRATE0/2/12);
        CKCON &= ~0x0B;                  // T1M = 0; SCA1:0 = 00
    } 
    else 
    {
        TH1 = -(SYSCLK/BAUDRATE0/2/48);
        CKCON &= ~0x0B;                  // T1M = 0; SCA1:0 = 10
        CKCON |=  0x02;
    }

    TL1 = TH1;                          // init Timer1
    TMOD &= ~0xf0;                      // TMOD: timer 1 in 8-bit autoreload
    TMOD |=  0x20;
    TR1 = 1;                            // START Timer1
    ES0 = 1;                            // Enable UART0 interrupts
}

void uart0_isr(void) interrupt INTERRUPT_UART0
{
    if (RI0)
    {
        RI0 = 0;
    }

    if (TI0)
    {
        TI0 = 0;
        RS_Xbusy = 0;
    }
}

void RS_tx(unsigned char tx_buf)
{
    while (RS_Xbusy)
        ;
    
    SBUF0 = tx_buf;
    RS_Xbusy = 1;
}

void Puts(char *ptr)
{
    while (*ptr!='\0')
        RS_tx(*ptr++);
}

void putc(char c)
{
    SBUF0 = c;    
}