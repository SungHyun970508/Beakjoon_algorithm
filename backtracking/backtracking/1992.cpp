//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//string answer = "";
//int map[65][65];
//int n;
//
//
//void dfs(int n, int x, int y)
//{
//	if (n == 1)
//	{
//		cout << map[x][y];
//		return;
//	}
//
//	bool zero = true, one = true;
//	for (int i = x; i < x + n; i++)
//	{
//		for (int j = y; j < y + n; j++)
//		{
//			if (map[i][j])
//				zero = false;
//			else
//				one = false;
//
//		}
//	}
//	if (zero)
//		cout << 0;
//	else if(one)
//		cout << 1;
//	else
//	{
//		cout << "(";
//		dfs(n / 2, x, y);//왼쪽 위
//		dfs(n / 2, x, y + n / 2);//오른쪽 위
//		dfs(n / 2, x + n / 2, y);//왼쪽아래
//		dfs(n / 2, x + n / 2, y + n / 2);//오른쪽 아래
//		cout << ")";
//	}
//	return;
//}
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		
//		string temp;
//		cin >> temp;
//		for (int j = 0; j < n; j++)
//		{
//			map[i][j] = temp[j] - '0';
//		}
//			
//	}
//
//	dfs(n, 0, 0);
//
//
//
//	return 0;
//}