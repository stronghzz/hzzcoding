#include "String.h"



int main()
{
	String str("hello,world");
	cout << str.Size() << endl;
	String str1(str);
	cout << str1.Size() << endl;
	str.Append("cc");
	for (int i = 0; i < str.Size(); i++)
	{
		// s.operator[](&s, i)
		cout << str[i] << endl;
		//cout << s.operator[](i) << endl;
	}
	String::const_iterator sit = str.begin();
	while (sit != str.end())
	{
		//*sit = '10';
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	return 0;
} 