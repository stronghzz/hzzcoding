#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
typedef struct PersonInfo
{
	char name[1024];
	char phone[1024];

}PersonInfo;

typedef struct AddrBook
{
	PersonInfo person_info[SIZE];//SIZE表示的是通讯录中信息的上限；
								 //需要标注出哪些信息是有意义的，哪些信息是没有意义的
								 //通讯录并不是程序已启动，里面的1000条数据都是有意义的
	int size;//[0,size]有意义的区间
}AddrBook;
AddrBook g_addr_book;
void Init()
{
	g_addr_book.size = 0;
	memset(g_addr_book.person_info, 0x0, sizeof(g_addr_book.person_info));
}
int Menu()
{
	//打印出给用户提供的操作
	//并且提示进行输入
	//把用户输入的结果返回出来
	printf("============================\n");
	printf("1.添加\n");
	printf("2.删除\n");
	printf("3.修改\n");
	printf("4.查找\n");
	printf("5,显示\n");
	printf("6,清空\n");
	printf("0.退出\n");
	printf("============================\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
enum
{
	EXIT = 0,
	ADD,
	DEL,
	MODIFY,
	FIND,//查找某条记录
	PRINT,//打印所有内容
	CLEAR,//清空所有内容
};

void AddPersonInfo()
{
	//添加一个用户信息到通讯录中
	//提示用户输入相关的用户信息，然后把对应的数据更新到数组中
	if (g_addr_book.size >= SIZE)
	{
		printf("当前通讯录已满，插入失败！\n");
		return;
	}
	printf("添加一个新用户！\n");
	printf("请输入用户名：");
	//下标位 size 的位置就是我们需要放置的新元素的位置
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("请输入电话号码：");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	++g_addr_book.size;
	printf("插入成功！");
	return;

}
void DelPersonInfo()//按照用户信息的编号进行删除
{
	printf("删除指定记录！\n");
	printf("请输入要删除的条目的编号：");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size)
	{
		printf("输入的编号不合法！删除失败！");
		return;
	}
	//此时采取一种比较简单的方案
	//1.如果用户要删除的是最后一个元素，那么就直接 --size
	if (num != g_addr_book.size - 1)
	{
		//2.如果用户要删除的是某个中间位置的元素，就把最后一个元素填充到该位置
		strcpy(g_addr_book.person_info[num].name, g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[num].phone, g_addr_book.person_info[g_addr_book.size - 1].phone);
	}
	g_addr_book.size--;
	printf("删除成功\n");
	return;
}
void ModifyPersonInfo()//根据编号进行修改
{
	printf("修改某条记录！\n");
	printf("请输入要修改的信息的编号：");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size)
	{
		printf("输入的编号不合法！");
		return;
	}
	printf("请输入新的用户名：");
	scanf("%s", g_addr_book.person_info[num].name);
	printf("请输入新的电话号码：");
	scanf("%s", g_addr_book.person_info[num].phone);
	printf("修改成功！");

}
void FindPersonInfo()
{
	printf("查找电话号码：");
	printf("请输入要查找的姓名：");
	char name[1024] = { 0 };
	scanf("%s", name);
	int count = 0;
	for (int i = 0; i < g_addr_book.size; ++i)
	{
		if (strcmp(name, g_addr_book.person_info[i].name) == 0)
		{
			printf("电话号码为：%s\n", g_addr_book.person_info[i].phone);
			count++;
		}
	}
	if (count == 0)
	{
		printf("没有找到！\n");
	}
	else
	{
		printf("找到%d条记录\n", count);
	}
}
void PrintPersonInfo()//打印所有用户的相关信息
{
	printf("打印所有用户信息！\n");
	for (int i = 0; i < g_addr_book.size; ++i)
	{
		printf("[%d] %s %s\n", i, g_addr_book.person_info->name, g_addr_book.person_info[i].phone);
	}
	printf("打印完成!,共打印%d条记录。\n", g_addr_book.size);
}
void ClearPersonInfo()//清除所有
{
	printf("清除所有用户信息!\n");
	printf("是否清除所有用户信息？y  or  n    \n");
	char input[1024] = { 0 };
	scanf("%s", input);
	if (strcmp(input, "y") != 0)
	{
		printf("已取消删除操作\n");
		return;
	}
	g_addr_book.size = 0;
	printf("清除成功！\n");
}
int main()
{
	Init();//1.先创建一个通讯录的变量，并且也需要对这个变量进行初始化
	while (1)
	{
		//2.进入循环，打印一个用户菜单，并且提示用户进行操作
		int choice = Menu();
		//3.用户输入相应的编号之后，就调用对应的操作函数
		switch (choice)
		{
		case ADD:
			AddPersonInfo();
			break;
		case DEL:
			DelPersonInfo();
			break;
		case MODIFY:
			ModifyPersonInfo();
			break;
		case FIND:
			FindPersonInfo();
			break;
		case PRINT:
			PrintPersonInfo();
			break;
		case CLEAR:
			ClearPersonInfo();
			break;
		case EXIT:
			printf("Goodbye\n");
			system("pause");
			return 0;
		default:
			break;
		}
	}

	return 0;
}