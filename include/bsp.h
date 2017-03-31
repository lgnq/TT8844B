#ifndef __BSP_H__
#define __BSP_H__

// SYSCLK frequency in Hz
#define SYSCLK (48000000)

void sysclk_init(void);
void port_init(void);

#endif