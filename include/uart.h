#ifndef __UART_H__
#define __UART_H__

#define BAUDRATE0 (115200)

void uart0_init(void);

void Puts(char *ptr);
void putc(char c);

#endif