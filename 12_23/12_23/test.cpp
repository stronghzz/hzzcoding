#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct node {
	int x, y;
}machine[maxn], task[maxn], test[maxn];

int cmp(node a, node b)
{
	if (a.x == b.x)
		return a.y > b.y;
	return a.x > b.x;
}

int main()
{
	int n = 0, m = 0, count = 0, k = 0;
	long long moreIncome = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++)
	{
		scanf("%d %d", &machine[i].x, &machine[i].y);
	}
	for (int i = 0; i<m; i++)
	{
		scanf("%d %d", &task[i].x, &task[i].y);
	}
	sort(machine, machine + n, cmp);
	sort(task, task + m, cmp);

	printf("***************************\n");
	//	printf ("machine:\n");
	//	for (int i=0; i<n; i++)
	//		printf ("%d %d\n", machine[i].x, machine[i].y);
	//	printf ("+++++++++++++++++++++++++++\n");
	//	printf ("task:\n");
	//	for (int i=0; i<m; i++)
	//		printf ("%d %d\n", task[i].x, task[i].y);
	//	printf ("***************************\n");

	for (int i = 0; i<n; i++)
	{
		int flag1 = -1, flag2 = -1;
		for (int j = 0; j<m; j++)
		{
			if (machine[i].x >= task[j].x && machine[i].x>0 && task[j].x>0
				&& machine[i].y >= task[j].y && machine[i].y>0 && task[j].y>0)
			{
				flag1 = i;
				flag2 = j;
				break;
			}
		}
		if (flag1 != -1 && flag2 != -1) {
			//			printf ("machine[flag1].x, machine[flag1].y, task[flag2].x, task[flag2].y = %d %d %d %d\n", 
			//				machine[flag1].x, machine[flag1].y, task[flag2].x, task[flag2].y);
			//			printf("task[flag2].x task[flag2].y = %d %d\n", task[flag2].x, task[flag2].y); 
			test[k].x = task[flag2].x;
			test[k].y = task[flag2].y;
			k++;
			moreIncome += 200 * task[flag2].x + 3 * task[flag2].y;
			task[flag2].x = -1;
			machine[flag1].x = -1;
			task[flag2].y = -1;
			machine[flag1].y = -1;
			count++;
		}
	}
	sort(test, test + k, cmp);
	for (int i = 0; i<k; i++)
	{
		printf("test[i].x  test[i].y = %d %d\n", test[i].x, test[i].y);
	}
	printf("**************************\n");
	printf("%d %lld", count, moreIncome);
	return 0;
}
