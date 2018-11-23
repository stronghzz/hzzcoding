#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 100
#include <stdio.h>
#include <stdlib.h>
void main()
{
	FILE*fp;
	char ch, filename[10];
	printf("输入文件名: ");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("无法打开此文件!");
		exit(0);
	}
	ch = getchar();
	printf("输入将要存储在磁盘的字符“#”结束");
	printf("\n");
	ch = getchar();
	while (ch != '#')
	{
		fputc(ch, fp);
		putchar(ch);
		ch = getchar();
	}
	fclose(fp);
	printf("\n");
}
//void main()
//{
//	FILE*fp1, *fp2;
//	char ch, filename1[N], filename2[N];
//	printf("输入要读入的文件名:");
//	scanf("%s", filename1);
//	printf("输入要输出的文件名:");
//	scanf("%s", filename2);
//	if ((fp1 = fopen(filename1, "r")) == NULL)
//	{
//		printf("打不开此文件！！");
//		exit(0);
//	}
//	if ((fp2 = fopen(filename2, "w")) == NULL)
//	{
//		printf("打不开此文件！！");
//		exit(0);
//	}
//	while (!feof(fp1))//未到读入文件标志符
//	{
//		ch = fgetc(fp1);//获取字符
//		fputc(ch, fp2);// 写入文件
//		putchar(ch);//显示屏幕
//	}
//	putchar(N);
//	fclose(fp1);
//	fclose(fp2);
//	puts("\n");
//}
