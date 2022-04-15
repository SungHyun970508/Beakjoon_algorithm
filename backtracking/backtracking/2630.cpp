//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int n;
//int map[129][129];
//int onecnt = 0, zcnt = 0;
//
//void recur(int n, int x, int y)
//{
//	int cur = map[x][y];
//
//	
//	for (int i = x; i < x + n; i++)
//	{
//		for (int j = y; j < y + n; j++)
//		{
//			if (map[i][j] != cur)
//			{
//				recur(n / 2, x, y );
//				recur(n / 2, x, y+n/2);
//				recur(n / 2, x + n / 2, y);
//				recur(n / 2, x + n / 2, y + n / 2);
//
//				return;
//			}
//		}
//	}
//
//	if (cur == 0)
//	{
//		onecnt++;
//
//	}
//	else {
//		zcnt++;
//
//	}
//
//	
//}
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//	recur(n, 0, 0);
//	cout << onecnt << endl << zcnt;
//}