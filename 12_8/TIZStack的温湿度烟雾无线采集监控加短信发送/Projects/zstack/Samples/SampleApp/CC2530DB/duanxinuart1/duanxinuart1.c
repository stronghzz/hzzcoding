/***********************************************************************************
Filename: duanxinuart1.c
Prozessor: 80C51 family

***********************************************************************************/
#include <ioCC2530.h>
#include "duanxinuart1.h"
#include "hal_board_cfg.h"
#include "hal_defs.h"
#include "hal_types.h"
#define uint unsigned int
#define uchar unsigned char

extern int readflag=0;
extern  unsigned char *duanxinStr;

void  delay_50ms(uint t)
 {
	uint j;
	for(;t>0;t--)
	for(j=6245;j>0;j--);
}
/*****************************************
//uart1初始化
*****************************************/
void InitUart1(void)
{	
 // CLKCONCMD &= ~0x40;                          //设置系统时钟源为32MHZ晶振
 // while(CLKCONSTA & 0x40);                     //等待晶振稳定
 // CLKCONCMD &= ~0x47;                          //设置系统主时钟频率为32MHZ
  
  P1SEL |= 0xc0; //1100 0000  0为普通口，1为外设 P1 6TX 7RX 为UART1
  P2DIR=0X40;
  U1CSR |= 0x80;
  PERCFG |= 0x02;
  //HAL_BOARD_INIT();//板级初始化
  U1GCR =9;    //BAUD_E = 9  //19200 
  U1BAUD = 59;  //BAUD_M =59   波特率计算公式 (256+BAUD_M)
  //UART_SETUP(1, 19200, HIGH_STOP);  // 串口设置
  UTX1IF=1;
  URX1IF=0;
  U1UCR |=0x82;

  U1CSR |= 0X40;				//允许接收
  IEN0 |= 0x88;				//开总中断，接收中断
  
}

/*********************************************************************
 * 函数名称：senduart_a_byte
 * 功    能：发送一个字符
 * 入口参数：c  发送的字符
 * 出口参数：无
 * 返 回 值：无
 ********************************************************************/
uint8 senduart_a_byte(char c)  
{
  /*if(c == '\n')  
 {
    while(!UTX1IF);
   U1DBUF = 0x0d;   
 }*/
  
   while (!UTX1IF);
   UTX1IF = 0;
   return(U1DBUF = c);
}


/*********************************************************************
 * 函数名称：read_a_byte
 * 功    能：接收一个字符
 * 入口参数：无
 * 出口参数：
 * 返 回 值：接收的字符
 ********************************************************************/
//uint8 read_a_byte( )  
//{
 
//   char b;
//   if(URX1IF)
//   {
//     b=U1DBUF;
//     readflag=1;
//     URX1IF = 0;
//   }
//   return (b);
//}

/*********************************************************************
 * 函数名称：printsuart
 * 功    能：发送一串字符
 * 入口参数：s         字符串指针
 * 出口参数：无
 * 返 回 值：无
 ********************************************************************/
void printsuart(char *s)
{
 //uint8 i = 0;
 
  while(*s)//while(s[i] != '\0')    // 判断字符串是否结束
  {
    senduart_a_byte(*s);// 发送一字节
    s++;
  }
 
}

/*********************************************************************
 * 函数名称：readinstr
 * 功    能：接收一串字符
 * 入口参数：无
 * 出口参数：无
 * 返 回 值：字符串
 ********************************************************************/
//void readinstr( )
//{

//  if(URX1IF)
 //  {
 //   *duanxinStr= U1DBUF; //保存字符
 //   URX1IF=0; //清URX1IF
 //    readflag=1;
 //  }
 //while(*duanxinStr!= '\0') //判断是否到了字符串的尾部
 //{
 //  while(!URX1IF); //空语句判断字符是否收完
 // duanxinStr++; //字符串指针加一
 // *duanxinStr= U1DBUF; //保存字符
 //  URX1IF=0; //清URX1IF
 //}
//}


/*****************************************
//uart1发送
*****************************************/

char message[]={"Warning:the gas leak!"};

char AT_CMGF[]={"AT+CMGF=1"};//设置短信的格式为PDU格式
char AT_CSCA[]={"AT+CSCA=\"+8613800290500\""};//设置移动服务中心号码
char AT_CMGS[]={"AT+CMGS=\"1252018700443632\""};//发送短信指令，需要接收短信的手机号码,注意要定义为字符串（\0）
char  call_number[]={"ATD15191897096;"};
//char s1=0x0D;
//char s2=0x0A;
void send_call(void)
{
	printsuart(call_number);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}
void send_cmgf(void)
{
	printsuart(AT_CMGF);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}
void send_csca(void)
{
	printsuart(AT_CSCA);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}
void send_cmgs(void)
{
	printsuart(AT_CMGS);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}
void sendmessage(void)
{
	printsuart(message);
        //delay_50ms(30);
	senduart_a_byte(0x1A);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}


/*****************************************
//uart1接收
*****************************************/ 
	


