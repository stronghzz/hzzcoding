#include <iostream>
#include <fstream>
#include <thread>
#include <windows.h>
using namespace std;

class hello
{
public:
	//hello()
	//{
	//	cout << "hello,thread" << endl;
	//}
	void operator()()const
	{
		cout << "hello,world" << endl;
	}

};
//void hell()
//{
//	cout << "hello,world" << endl;
//	//time(10);
//}
int main()
{

/*	const char* msg = "hello,world";
	fwrite(msg, strlen(msg), 1, stdout);
	fprintf(stdout, "hello,world")*/;
	//hello h;
	//thread my_thread(h);
	//my_thread.join();
	//thread mythread{ hello() };

	////cout << "hello,world123" << endl;
	//mythread.join();
	//ifstream fin("test.txt");
	//char buffer[10];
	//while (!fin.eof())
	//{
	//	fin.read(buffer, 9);
	//	cout << buffer << endl;
	//}
	//
	//const char* p = "adfcd";
	//
	return 0;
}

