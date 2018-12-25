#include<iostream>
#include<stdlib.h>
#include <math.h>
using namespace std;



int main()
{
	int N, M, i, j, sum_eat, current_eat, last_eat;

	cin >> N >> M;

	for (i = M - N + 1; i >= 1; i--)
	{
		sum_eat = i;
		j = 1;
		last_eat = i;

		while (j<N)
		{
			if (last_eat <= 2)
			{
				current_eat = 1;
			}
			else
			{
				current_eat = last_eat / 2 + (last_eat % 2);
			}

			sum_eat += current_eat;
			if (sum_eat > M)
			{
				break;
			}

			last_eat = current_eat;
			j++;
		}
		if (j == N)
		{
			break;
		}
	}
	cout << i << endl;

	system("pause");
	return 0;
}
