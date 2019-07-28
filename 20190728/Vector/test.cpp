#include <iostream>
#include <vector>
#include <string>
using namespace std;

//int main()
//{
//	vector<string> arr;
//
//	arr.push_back("hello");
//	arr.push_back("world");
//	cout << arr.at(0)<<endl;
//	vector<string>::iterator it = arr.begin();
//	cout << *it << endl;
//	cout << arr.capacity() << endl;
//	vector<int> arr1;
//	vector<int>::iterator it1 = arr1.begin();
//	it++;
//	cout << *it << endl;
//	return 0;
//}
void PrintV(const vector<int>& v)
{
	//vector<int>::const_iterator vit = v.begin();
	auto vit = v.begin();

	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}

//int main()
//{
//	vector<int> v;
//
//	vector<int> v2(10, 8);
//
//	vector<int> v3(v2.begin(), v2.end());
//
//	string s("hello");
//
//	//只要迭代器解引用之后的类型一致，就可以使用迭代器传参
//	vector<char> v4(s.begin(), s.end());
//
//	//vector<Date> v5(s.begin(), s.end());
//	
//	/*vector<int>::reverse_iterator vit = v7.rbegin();
//	while (vit != v7.rend())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;*/
//
//
//	/*for (const auto& e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < v2.size(); i++)
//	{
//		cout << v2[i] << " ";
//	}
//	
//	cout << endl;*/
//	vector<int> v7;
//	v7.push_back(1);
//	v7.push_back(2);
//	v7.push_back(3);
//	v7.push_back(4);
//	auto vit = v7.begin();
//	cout << *vit << endl;
//	//insert会引起迭代器失效,增容导致的原有指向的空间已经被释放：迭代器指向的位置非法
//	//v7.insert(v7.begin() + 3, 0);  // 1 2 3 0 4
//	// 插入完成之后，重新获取迭代器才能继续使用
//	vit = v7.begin();
//	cout << *vit << endl;
//	//v7.insert(v7.end() - 2, 5);  // 1 2 3 5 0 4
//	// erase可能导致迭代器访问越界
//	// 删除完成之后，获取erase返回值，更新迭代器的值
//	vit = v7.erase(vit);
//	cout << *vit << endl;
//	v7.clear();
//	cout << v7.size() << endl;
//	cout << v7.capacity() << endl;
//	PrintV(v7);
//		return 0;
//	
//}

//int main()
//{
//	vector<int> v;
//	v.reserve(200);
//	size_t capa = v.capacity();
//	cout << "init capacity: ";
//	cout << capa << endl;
//	for (int i = 0; i < 200; i++)
//	{
//		v.push_back(i);
//		if (capa != v.capacity())
//		{
//			capa = v.capacity();
//			cout << capa << endl;
//		}
//	}
//
//	return 0;
//}

class Date
{
public:
	Date(int y, int month, int day)
		:_year(y)
	{
		cout << "Date(int)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
	{
		cout << "Date(const Date&)" << endl;
	}
private:
	int _year;
};

//int main()
//{
//	vector<Date> v;
//	auto vit = v.begin();
//	v.insert(vit, Date(2019, 4, 3));
//	vit = v.begin();
//	cout << "emplace: " << endl;
//	v.emplace(vit, 2019, 4, 3);
//	vector<Date> v2;
//	int a = 10; int b = 2;
//	swap(a, b);
//	// 成员swap和非成员swap内在逻辑相同， 非成员swap内部调用成员swap完成交换
//	swap(v, v2);  // --->  v.swap(v2)
//	v.swap(v2);
//
//	string s("hello");
//	string s2 = "hello";
//	return 0;
//}

//string mapLetter[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//
//class Solution {
//public:
//	// C++11 普通成员可以在类里面初始化，相当于缺省值, 数组不能在类里面初始化
//	//string mapLetter[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//	//用digits的长度控制递归的深度
//	//每次把当前层的组合的子串传入到下一层的递归，和下一层的字母组合更长的子串
//	//直到最后一层，组合完成，把对应的组合存放到vector
//	
//	void combination(int depth, string& digits, 
//		const string& comStr, vector<string>& vec)
//	{
//		//走完最后一层，获取字母组合
//		if (depth == digits.size())
//		{
//			vec.push_back(comStr);
//			return;
//		}
//		// digits --> "234"  digits[0] --> '2'   --> mapLetter[2]
//		int mapNum = digits[depth] - '0';
//		string Letters = mapLetter[mapNum];  // "def"
//		//当前的子串和每一个字母组合
//		for (int i = 0; i < Letters.size(); i++)
//		{
//			combination(depth + 1, digits, comStr + Letters[i], vec);
//		}
//	}
//
//	vector<string> letterCombinations(string digits) {
//		vector<string> vec;
//		if (digits.empty())
//			return vec;
//		string comStr;
//		combination(0, digits, comStr, vec);
//		return vec;
//	}
//};


class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> matrix;
		matrix.resize(numRows);
		for (int i = 0; i < numRows; i++)
		{
			matrix[i].resize(i + 1);
			// vector<vector<int>>.operator[](i)--> vector<int>.operator[](i)--> int
			matrix[i][0] = matrix[i][i] = 1;
		}

		for (int i = 2; i < numRows; i++)
		{
			for (int j = 1; j < i; j++)
			{
				matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
			}
		}

		return matrix;
	}
};

int main()
{
	Solution s;
	s.generate(10);
	return 0;
}