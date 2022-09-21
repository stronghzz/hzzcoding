#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

//int main()
//{
//	int N, m;
//	cin >> N >> m;
//	N /= 10;
//	vector<vector<int> > prices(61, vector<int>(3,0));
//	vector<vector<int> > priceMutiplyPriority(61, vector<int>(3.0));
//	for (int i = 1; i <= m; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		a /= 10;
//		b *= a;
//		if (c == 0)
//		{
//			prices[i][0] = a;
//			priceMutiplyPriority[i][0] = b;
//		}
//		else
//		{
//			if (prices[c][1] == 0)
//			{
//				prices[c][1] = a;
//				priceMutiplyPriority[c][1] = b;
//			}
//		}
//	}
//	vector<vector<int> > dp(m + 1, vector<int>(N + 1, 0));
//	for (int i = 1; i <= m; ++i)
//	{
//		for (int j = 1; j <= N; ++j)
//		{
//			int a = prices[i][0], b = priceMutiplyPriority[i][0];
//			int c = prices[i][1], d = priceMutiplyPriority[i][1];
//			int e = prices[i][2], f = priceMutiplyPriority[i][2];
//			dp[i][j] = j >= a ? max(dp[i - 1][j - a] + b, dp[i - 1][j]) : dp[i - 1][j];
//			dp[i][j] = j >= (a + c) ? max(dp[i - 1][j - a - c] + b + d, dp[i][j]) : dp[i][j];
//			dp[i][j] = j >= (a + e) ? max(dp[i - 1][j - a - e] + b + f, dp[i][j]) : dp[i][j];
//			dp[i][j] = j >= (a + c + e) ? max(dp[i - 1][j - a - c - e] + b + d + f, dp[i][j]) : dp[i][j];
// 		}
//	}
//	cout << dp[m][N] * 10 << endl;
//	return 0;
//}



//int main()
//{
//	int X = 0;
//	int Y = 0;
//	string str;
//	cin >> str;
//	while (1)
//	{
//		if (str.find(';') == string::npos)
//		{
//			break;
//		}
//		int i = str.find(';');
//		string temp = str.substr(0, (i-0));
//		if (temp.size() == 3 && temp.at(1) >= '0' && temp.at(1) <= '9' && temp.at(2) >= '0' && temp.at(2) <= '9'|| temp.size() == 2 && temp.at(1) >= '0' && temp.at(1) <= '9')
//		{
//			switch (temp.at(0))
//			{
//			case 'A': X -= stoi(temp.substr(1), 0, 10); break;
//			case 'D': X += stoi(temp.substr(1), 0, 10); break;
//			case 'W': Y += stoi(temp.substr(1), 0, 10); break;
//			case 'S': Y -= stoi(temp.substr(1), 0, 10); break;
//			default:break;
//			}
//		}
//		str = str.substr(i + 1);
//	}
//	cout << X << ',' << Y << endl;
//	return 0;
//}

//int main()
//{	
//	string tmp;
//	int X = 0, Y = 0;
//	cin >> tmp;
//	while (1)
//	{
//		if (tmp.find(';') == string::npos)//Ã»ÕÒµ½£¬ÍË³ö
//		{
//			break;
//		}
//		int ii = tmp.find(';');
//		string str = tmp.substr(0, (ii - 0));
//		if (str.size() == 3 && str.at(1) >= '0' && str.at(1) <= '9' && str.at(2) >= '0' && str.at(2) <= '9')
//		{
//			switch (str.at(0))
//			{
//				case 'A':X -= stoi(str.substr(1), 0, 10); break;
//				case 'D':X += stoi(str.substr(1), 0, 10); break;
//				case 'W':Y += stoi(str.substr(1), 0, 10); break;
//				case 'S':Y -= stoi(str.substr(1), 0, 10); break;
//				default:break;
//			}
//		}
//		tmp = tmp.substr(ii + 1);
//	}
//	cout << X << "," << Y << "\n";
//	return 0;
//}

//int main()
//{
//	int N, m;
//	cin >> N >> m;
//	N /= 10;
//	vector<vector<int>> prices(61, vector<int>(3, 0));
//	vector<vector<int>> priceMultiplyPriority(61, vector<int>(3, 0));
//	for (int i = 1; i <= m; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		a /= 10;
//		b *= a;
//		if (c == 0)
//		{
//			prices[i][0] = a;
//			priceMultiplyPriority[i][0] = b;
//		}
//		else
//		{
//			if (prices[c][1] == 0)
//			{
//				prices[c][1] = a;
//				priceMultiplyPriority[c][1] = b;
//			}
//		}
//	}
//	vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			int a = prices[i][0], b = priceMultiplyPriority[i][0];
//			int c = prices[i][1], d = priceMultiplyPriority[i][1];
//			int e = prices[i][2], f = priceMultiplyPriority[i][2];
//			dp[i][j] = j >= a ? max(dp[i - 1][j - a] + b, dp[i - 1][j]) : dp[i - 1][j];
//			dp[i][j] = j >= (a + c) ? max(dp[i - 1][j - a] + b + d, dp[i][j]):dp[i][j];
//			dp[i][j] = j >= (a + e) ? max(dp[i - 1][j - a - e] + b + f, dp[i][j]) : dp[i][j];
//			dp[i][j] = j >= (a + c + e) ? max(dp[i - 1][j - a - c - e] + b + d + f, dp[i][j]) : dp[i][j];
//		}
//	}
//	cout << dp[m][N] * 10 << endl;
//	return 0;
//}
//int main()
//{
//	array<int, 3> arr = { 1,2,3 };
//	array<char, 3> str = { 'a','b','c' };
//	array<int, 3> arr1{ 1,2,3 };
//	array<char, 3> str1{ 'a','b','c' };
//	return 0;
//}



//int main()
//{
//	vector<string> a;
//	a.push_back("hello,world");
//	cout << a[0] << endl;
//	return 0;
//}


//int main()
//{
//    string str;
//    getline(cin, str);
//    string::reverse_iterator it = str.rbegin();
//    for (it; it != str.rend(); it++)
//    {
//        cout << *it;
//    }
//
//}