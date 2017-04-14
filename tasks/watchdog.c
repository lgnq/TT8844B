/*--------------------------------------------------------------------*-

  watchdog_f85x_003-0_c02a.c (Released 2015-03)

  --------------------------------------------------------------------
   
  Simple 'Watchdog' module for F85x (8051).

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

// Task header
#include "watchdog.h"

/*--------------------------------------------------------------------*-

  WATCHDOG_Init()

  Set up watchdog timer on F38x (8051).

  Based on Sci Labs examples code.

-*--------------------------------------------------------------------*/
void WATCHDOG_Init(void)
{
    // Even though the LFOSC is disabled after a reset and the register reads
    // disabled, the oscillator is automatically enabled whenever it's used by
    // the WDT. This means we do not need to enable it here.

    // WDT interval given by:
    //
    // 4 ^ (3 + WDTCN[2:0]) * TLFOSC
    //
    // The LFOSC is running at 80 kHz
    //
    // We want a timeout of approximately 10 ms.
    //
    // 4 ^ (3 + 2) * 12.5 us = 12.8 ms

    // WDTCN.7 must be cleared to 0 to write the timeout interval
    ///WDTCN = 0x02;

    // Enable and feed the watchdog
    ///WDTCN = 0xA5;
    
    /*
    To configure the WDT, perform the following tasks:
    1. Disable the WDT by writing a 0 to the WDTE bit.
    2. Select the desired PCA clock source (with the CPS2¨CCPS0 bits). default is SYSCLK/12
    3. Load PCA0CPL4 with the desired WDT update offset value.
    4. Configure the PCA Idle mode (set CIDL if the WDT should be suspended while the CPU is in Idle mode).
    5. Enable the WDT by setting the WDTE bit to 1.
    6. Reset the WDT timer by writing to PCA0CPH4.    
    */
    
    PCA0CPL4 = 0xFF;

    PCA0MD |= 0x40;						// Enable Watchdog timer, WDTE = 1
}

/*--------------------------------------------------------------------*-

  WATCHDOG_Update()

  Feed the watchdog timer.

  See Watchdog_Init() for further information.

-*--------------------------------------------------------------------*/
void WATCHDOG_Update(void)
{
    // Feed the watchdog
    //PCA0CPH4 = 0xFF;
    PCA0CPH4 = 0x0;
}

/*--------------------------------------------------------------------*-
  ------ END OF FILE -------------------------------------------------
-*--------------------------------------------------------------------*/
