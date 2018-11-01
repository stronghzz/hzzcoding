#ifndef _GAME_H__
#define _GAME_H__



#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define ROW 11
#define COL 11
#define rows 9
#define cols 9
#define Count 10 //雷的个数

void menu();//菜单
void Inie_mine(char	 mine[ROW][COL], char show[ROW][COL]);//初始化棋盘
void Display(char show[ROW][COL]);
void Set_mine(char mine[ROW][COL]);//设置雷的位置
void Sweep(char mine[ROW][COL], char show[ROW][COL]);//开始扫雷
int Get_num(char mine[ROW][COL], int x, int y);//计算雷的个数

#endif //_GAME_H__
