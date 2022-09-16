#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	//vector迭代器是普通指针
	
	vector<int> iv(2, 9);
	cout << iv[0] << endl;
	cout << iv[1] << endl;
	cout << "size=" << iv.size() << endl;
	cout << "capacity=" << iv.capacity() << endl;
	iv.push_back(1);
	cout << "size=" << iv.size() << endl;
	cout << "capacity" << iv.capacity() << endl;
	

	//bool a = true;
	//cout << a;
	return 0;
}