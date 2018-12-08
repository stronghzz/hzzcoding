

#include <ioCC2530.h>
//#include "hal_board_cfg.h"
//#include "hal_defs.h"
#include "hal_types.h"

#define uchar unsigned char
#define uint unsigned int 
extern void  delay_50ms(uint t);
extern void InitUart1(void);
extern void printsuart(char *s);
extern void send_call(void);
extern void send_cmgf(void);
extern void send_csca(void);
extern void send_cmgs(void);
extern void sendmessage(void);
extern uint8 senduart_a_byte(char c);

