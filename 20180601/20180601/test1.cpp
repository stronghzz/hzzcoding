#include <iostream>
using namespace std;

void fun(int a );


int main()
{
	fun(10);
}
void fun(int a=0 )
{
	
	cout << a << " " << a + 10 << endl;
	
}
