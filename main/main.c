/*--------------------------------------------------------------------*-

   main.c (Released 2015-03)

  --------------------------------------------------------------------

   main file for TT project.

   See _readme.txt for project information.

-*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*-

  This code is copyright (c) 2014-2015 SafeTTy Systems Ltd.

  This code is adapted from a Time-Triggered Reference Design (TTRD)
  that is documented in the following book: 

  Pont, M.J. (2014) 
  "The Engineering of Reliable Embedded Systems: LPC1769 Edition", 
  Published by SafeTTy Systems Ltd. ISBN: 978-0-9930355-0-0.

  Both the TTRDs and the above book ("the ERES book") describe 
  patented* technology and are subject to copyright and other 
  restrictions.

  This code may be used without charge: [i] by universities and 
  colleges in courses for which a degree up to and including MSc 
  level (or equivalent) is awarded; [ii] for non-commercial projects 
  carried out by individuals and hobbyists.

  Where this code has been provided to you as part of a training 
  course delivered by SafeTTy Systems Ltd, you may use it for 
  evaluation purposes for a period of up to 12 months from the 
  end date of this course, subject to the condition that no 
  products (of any kind) based either on this code, or on the 
  patented technology described in the ERES book, are released.

  Any and all other use of this code and / or the patented 
  technology described in the ERES book requires purchase of a 
  ReliabiliTTy Technology Licence:
  http://www.safetty.net/products/reliabilitty

  Please contact SafeTTy Systems Ltd if you require clarification
  of these licensing arrangements:
  http://www.safetty.net/contact

  MoniTTor is a registered trademark of SafeTTy Systems Ltd.
  PredicTTor is a registered trademark of SafeTTy Systems Ltd.
  ReliabiliTTy is a registered trademark of SafeTTy Systems Ltd.
  WarranTTor is a registered trademark of SafeTTy Systems Ltd.

  * Patents applied for.

-*--------------------------------------------------------------------*/

// Project header
#include "main.h"

bit RS_Xbusy = 0;

void Delay(void)
{
    int x;
    
    for (x = 0;x < 500;x)
        x++;
}

void sysclk_init(void)
{
    OSCICN |= 0x03;                     // Configure internal oscillator for
                                   // its maximum frequency and enable
                                   // missing clock detector

    CLKMUL  = 0x00;                     // Select internal oscillator as
                                   // input to clock multiplier

    CLKMUL |= 0x80;                     // Enable clock multiplier
    Delay();                            // Delay for clock multiplier to begin
    CLKMUL |= 0xC0;                     // Initialize the clock multiplier
    Delay();                            // Delay for clock multiplier to begin

    while(!(CLKMUL & 0x20));            // Wait for multiplier to lock
    CLKSEL  = 0x03;                     // Select system clock from internal High-Frequency Osc = 48MHz
}

//-----------------------------------------------------------------------------
// PORT_Init
// P0 : 0(o)-LED-Red, 1(o)-LED-Green, 2()-, 3()-, 4,5-UART0, 6()-, 7()-
// P1 : 0~3(i)-LCD_ID, 4(i)-SDA1, 5(i)-SCL1, 6(i)-SDA2, 7(i)-SCL2
// P2 : 0()-RESET, 1(i)-En_MIPI_Rx, 2()-FPPWC, 3()-FPBIAS, 4()-EE/SPI, 5()-SEL_MODE, 6()-, 7()-
// P3 : 0(i)-MODE_KEY, 1(i)-ENTER_KEY, 2(i)-UP_KEY, 3(i)-DOWN_KEY, 4(i)-LEFT_KEY, 5(i)-RIGHT_KEY, 6()- 7()-EN_LVDS
// P4 : 0~3(i)-DTVB, 4~7(i)-DTVA
//-----------------------------------------------------------------------------
void port_init(void)
{
    P0MDOUT = 0x03;                     // LED-R, LED-G
    P1MDOUT = 0x00;                     // 
    P2MDOUT = 0x00;                     // LED1, 2
    P3MDOUT = 0x00;                     //
    P4MDOUT = 0x00;

    P0SKIP = 0xCF;                      // GPIO, GPIO, TX, RX, GPIO...
    P1SKIP = 0xFF;                      // GPIOs
    P2SKIP = 0xFF;                      // GPIOs
    P3SKIP = 0xFF;                      // GPIOs

    XBR0 = 0x01;                        // .... ...(UART0)
    XBR1 = 0xC0;                        // disable weak pull-up, XBAR enable, important always!!!
    XBR2 = 0x00;                        // 

    EX0 = 0;        // INT0 disable
    EX1 = 0;        // INT1 disable
    IT0 = 1;        // Edge trigger
    IT1 = 1;        // Edge trigger
    IT01CF = 0x76;                      // P0.6(MPO0) as INT0, P0.7(MPO1) as INT1

    LED_R = 1;
    LED_G = 1;
}

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
    
int main(void)
{
    // Check mode, add tasks to schedule
    SYSTEM_Init();

    // Start the scheduler
    SCH_Start();

    while (1)
    {
        SCH_Dispatch_Tasks();
    }

    return 1;
}
  
/*--------------------------------------------------------------------*-
  ------ END OF FILE -------------------------------------------------
-*--------------------------------------------------------------------*/
