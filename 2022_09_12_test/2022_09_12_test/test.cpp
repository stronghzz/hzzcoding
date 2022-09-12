#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::string s("hello,world");
	size_t i = s.find(",");
	std::cout << std::string::npos << std::endl;
	std::cout << s.substr(0) << std::endl;
	std::cout << s.at(4) << std::endl;
	std::cout << i << std::endl;
	std::cout << sizeof(size_t) << std::endl;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(long) << std::endl;
	std::cout << sizeof(long long int) << std::endl;

	return 0;
}






//int main()
//{
//    std::string tmp;
//    int X = 0, Y = 0;
//    std::cin >> tmp;
//    while (true)
//    {
//        if (tmp.find(';') == std::string::npos)
//        {
//            break;
//        }
//        int ii = tmp.find(';');
//        std::string str = tmp.substr(0, (ii - 0));
//        if ((str.size() == 3 && str.at(1) >= '0' && str.at(1) <= '9' && str.at(2) >= '0' && str.at(2) <= '9')
//            || (str.size() == 2 && str.at(1) >= '0' && str.at(1) <= '9'))
//        {
//            switch (str.at(0))
//            {
//            case 'A':X -= std::stoi(str.substr(1), 0, 10); break;
//            case 'D':X += std::stoi(str.substr(1), 0, 10); break;
//            case 'W':Y += std::stoi(str.substr(1), 0, 10); break;
//            case 'S':Y -= std::stoi(str.substr(1), 0, 10); break;
//            default:break;
//            }
//        }
//        tmp = tmp.substr(ii + 1);
//    }
//    std::cout << X << "," << Y << "\n";
//    return 0;
//}