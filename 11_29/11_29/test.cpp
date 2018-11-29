#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//namespace N1
//{
//	int a = 10;
//	void test()
//	{
//		cout << "N1::test()" << endl;
//	}
//
//}
//int a = 20;
//int main()
//{
//	int a = 30;
//	cout << a << endl;
//	cout << ::a << endl;
//	cout << N1::a << endl;
//	return 0;
//}
/*struct A
{
int _a;
char _b;
double _c;
char _d;

};
*/
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
	void InitStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PirntStudent()
	{
		cout << _name << "" << _gender << "" << _age << endl;
	}
};
int main()
{
	Student s1, s2, s3;
	s1.InitStudentInfo("peter", "ÄÐ", 18);
	s2.InitStudentInfo("ÐÜ´ó", "Å®", 5);
	s2.InitStudentInfo("¼ª¼ª", "¹«", 5);

	return 0;

}
