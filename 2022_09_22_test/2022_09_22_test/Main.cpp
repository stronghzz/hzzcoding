#include <iostream>
#include <string>
using namespace std;


//int main()
//{
//	int n = 0;
//	int ans = 0;
//	while (cin >> n)
//	{
//		if (n == 0)
//		{
//			continue;
//		}
//		if (n >= 3)
//		{
//			ans += n / 3;
//			n = n / 3 + n % 3;
//		}
//		if (n == 2)
//		{
//			ans += 1;
//		}
//		cout << ans << endl;
//	}
//
//	return 0;
//}

int main()
{
	int n;
	while (cin >> n)
	{
		int ans = 0;
		if (n == 0)
		{
			break;
		}
		while (n >= 3)
		{
			ans += n / 3;
			n = n / 3 + n % 3;
		}
		if (n == 2)
		{
			ans++;
		}
		cout << ans << endl;
	}

	return 0;
}

//int main()
//{
//    string s;
//    while (cin >> s)
//    {
//        if (s.size() <= 8)
//        {
//            cout << "NG" << endl;
//        }
//        else
//        {
//            int bw = 0, sw = 0, num = 0, oth = 0;
//            for (int i = 0; i < s.size(); i++)
//            {
//                if (s[i] >= 'A' && s[i] <= 'Z') bw = 1;
//                else if (s[i] >= 'a' && s[i] <= 'z') sw = 1;
//                else if (s[i] >= '0' && s[i] <= '9') num = 1;
//                else oth = 1;
//            }
//            if (bw + sw + num + oth < 3)
//            {
//                cout << "NG" << endl;
//                continue;
//            }
//            else
//            {
//                int count = 0;
//                for (int i = 0; i <= s.size() - 6; i++)
//                {
//                    for (int j = i + 3; j < s.size(); j++)
//                    {
//                        if (s[i] == s[j] && s[i + 1] == s[j + 1] && s[i + 2] == s[j + 2])
//                        {
//                            cout << "NG" << endl;
//                            count = 1;
//                            break;
//                        }
//                    }
//                    if (count == 1) break;
//                }
//                if (count == 1) continue;
//                cout << "OK" << endl;
//            }
//        }
//    }
//    return 0;
//}

//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		if (str.size() < 8)
//		{
//			cout << "NG" << endl;
//		}
//		else
//		{
//			for (int i = 0; i <= str.size(); i++)
//			{
//				int bw = 0, sw = 0, num = 0, oth = 0;
//				if (str[i] >= '0' && str[i] <= '9')
//				{
//					bw = 1;
//				}
//				else if (str[i] >= 'a' && str[i] <= 'z')
//				{
//					sw = 1;
//				}
//				else if (str[i] >= 'A' && str[i] <= 'Z')
//				{
//					num = 1;
//				}
//				else
//				{
//					oth = 1;
//				}
//				if (bw + sw + num + oth < 3)
//				{
//					cout << "NG" << endl;
//				}
//				else
//				{
//					int count = 0;
//					for (int i = 0; i <= str.size() - 6; i++) 
//					{
//						for (int j = i + 3; j < str.size(); j++)
//						{
//							if (str[i] == str[j] && str[i + 1] == str[j + 1] && str[i + 2] == str[j + 2])
//							{
//								cout << "NG" << endl;
//								count = 1;
//								break;
//							}
//						}
//						if (count == 1)
//						{
//							break;
//						}
//					}
//					if (count == 1)
//					{
//						continue;
//					}
//					cout << "ok" << endl;
//				}
//			}
//		}
//	}
//	
//	return 0;
//}



//using namespace std;
//enum S
//{
//	A = 3,
//	B,
//	C,
//};
//int main()
//{
//	enum S a = A;
//	cout << a << endl;
//	cout << S::A << endl;
//	cout << S::B << endl;
//	cout << S::C << endl;
//	cout << S::A << endl;
//	
//	
//	return 0;
//}