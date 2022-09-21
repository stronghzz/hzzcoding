#include <iostream>
#include <thread>

void hello()
{
	std::cout << "hello,world" << std::endl;
}

int main()
{
	
	std::thread t(hello);
	t.join();
	std::cout << "nihaoshijie" << std::endl;
	return 0;
}