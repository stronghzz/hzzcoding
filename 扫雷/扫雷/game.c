#include "game.h"

void Inie_mine(char mine[ROW][COL], char show[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			mine[i][j] = '0';
			show[i][j] = '*';
		}
	}
}
void Display( char show[ROW][COL]) //打印棋盘
{
	int i = 0;
	int j = 0;
	printf(" ");
	for (i = 1; i <= rows; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i <= rows; i++)
	{
		printf("%d", i);
		for (j = 1; j <= cols; j++)
		{
			printf(" %c ", show[i][j]);
		}
		printf("\n");
	}
	
}
void Set_mine(char mine[ROW][COL])//设置雷的位置
{
	int i = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < Count; i++)
	{
		x = rand() % rows +1;
		y = rand() % cols +1;
		mine[x][y] = '1';
	}
}
void Sweep(char mine[ROW][COL], char show[ROW][COL])//输入坐标扫雷
{
	int count = 0;
	while (count!=(rows*cols-Count))
	{
		int x = 0;
		int y = 0;
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x < 1 || x>9 || y < 1 || y>9)
		{
			printf("请输入合法坐标");
		}
		else if (mine[ x ][ y ] == '1')
		{
			printf("你被炸死了\n");
			break;
		}
		else
		{
			int   ret = Get_num(mine, x, y);
			show[x][y] = ret+'0';
			Display(show);
			count++;
		}
		
	}
	if (count == (rows*cols - Count))
	{
		printf("你赢了\n");
	}
}
int Get_num(char mine[ROW][COL], int x, int y)//计算坐标周围雷的个数
{
	int count = 0;
	if (mine[x - 1][y - 1] == '1')//左上方
	{
		count++;
	}
	if (mine[x - 1][y] == '1')//左边
	{
		count++;
	}
	if (mine[x - 1][y + 1] == '1')//左下方
	{
		count++;
	}
	if (mine[x][y - 1] == '1')//上方
	{
		count++;
	}
	if (mine[x][y + 1] == '1')//下方
	{
		count++;
	}
	if (mine[x + 1][y - 1] == '1')//右上方
	{
		count++;
	}
	if (mine[x + 1][y] == '1')//右方
	{
		count++;
	}
	if (mine[x + 1][y + 1] == '1')//右下方
	{
		count++;
	}
	return  count;
	

}