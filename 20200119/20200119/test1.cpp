#include <stdio.h>
#include <iostream>

int main()
{
	enum week { Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } ;
	//printf("%d, %d, %d, %d, %d\n", sizeof(enum week), sizeof(day), sizeof(Mon), sizeof(Wed), sizeof(int));
	enum week day = Mon;
	std::cout << week::Mon << std::endl;
	std::cout << day << std::endl;
	return 0;
}