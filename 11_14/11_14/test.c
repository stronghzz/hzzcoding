
#include<stdio.h>
#include<Windows.h>
struct tagAAA
{

	unsigned char ucld : 1;
	unsigned char ucpara : 2;
	unsigned char ucState : 6;
	unsigned char ucTail : 4;
	unsigned char ucAvail;
	unsigned char ucTail2;
	unsigned char ucData;
}AAA_S1;
struct tagAAA2
{

	unsigned int ucld : 1;
	unsigned int ucpara : 2;
	unsigned int ucState : 6;
	unsigned int ucTail : 4;
	unsigned int ucAvail;
	unsigned int ucTail2;
	unsigned int ucData;
}AAA_S2;
int main()
{
	printf("%d  %d\n", sizeof(AAA_S1), sizeof(AAA_S2));
	system("pause");
	return 0;
}
