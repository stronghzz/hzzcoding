/*
 * @Descripttion: 
 * @version: 
 * @Author: zz
 * @Date: 2022-10-06 23:58:25
 * @LastEditors: zz
 * @LastEditTime: 2022-10-06 23:58:26
 */
//#include <map>
#include <string>
#include <sstream>
#include <iostream> 
int main()
{
	//std::map<int,int> mp(1,1);
	//std::string num = "10000";
	//int a;
	//std::stringstream ss(num);
	//ss >> a;
	//std::cout << a;
	std::stringstream ss("1000");
	
	int a;
	//ss << "1000";
	ss >> a;
	std::cout << a;
	return 0;
}
