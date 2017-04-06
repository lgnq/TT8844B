#include "main.h"

void delay(void)
{
    int x;
    
    for (x = 0; x < 500; x)
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
    delay();                            // Delay for clock multiplier to begin
    CLKMUL |= 0xC0;                     // Initialize the clock multiplier
    delay();                            // Delay for clock multiplier to begin

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

