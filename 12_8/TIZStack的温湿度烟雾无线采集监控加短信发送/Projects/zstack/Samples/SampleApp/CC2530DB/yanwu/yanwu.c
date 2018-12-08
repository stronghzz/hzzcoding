/***********************************************************************************
Filename: yanwu.c
Prozessor: 80C51 family

***********************************************************************************/
#include <ioCC2530.h>
#include "yanwu.h"

#define uint unsigned int
#define uchar unsigned char


char yanwuflag=0;

void yanwuDelay(uint n)
{
    uint i,t;
    for(i = 0;i<5;i++);
    for(t = 0;t<n;t++);
}

/*****************************************
//ÑÌÎí³õÊ¼»¯
*****************************************/
void yanwuInit(void)
{
      // P1_2 input io initialized.
    P1DIR &= ~(0x01<<2);//P1_2 input mode
    P1INP &= ~(0x01<<2);//P1_2 Pull up  
 
    yanwuDelay(20);
}



char judgeyanwu(void)
{
    yanwuflag=P1_2;
    
   if(yanwuflag==1)
      return 1;
   else
      return 0;
   // yanwuDelay(50000);
}

 
	
