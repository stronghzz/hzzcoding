#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void menu()
{
	printf("********************************************\n");
	printf("********************************************\n");
	printf("*************welcome  to saolei*************\n");
	printf("*************   1.      play   *************\n");
	printf("*************   0.      exit   *************\n");
	printf("********************************************\n");
	printf("********************************************\n");

}
void game()
{
	char mine[ROW][COL];
	char show[ROW][COL];
	Inie_mine(mine, show);
	Display(show);
	Set_mine(mine);
	//Display(mine);
	Sweep(mine,show);

}

int main()
{
		int input = 0;
		srand((unsigned int)time(NULL));
		do
		{
			menu();
			printf("请输入-》");
			scanf("%d", &input);
			switch (input)
			{
			case  1:
				game();
				break;
			case  0:
				printf("退出游戏");
				break;
			default:
				printf("选择错误,请重新选择-》\n");
				break;
			}

		} while (input);
	
	return 0;
}