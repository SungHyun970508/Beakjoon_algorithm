//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//int n;
//int mone = 0, zero = 0, one = 0;
//int map[3000][3000];
//
//void recur(int n, int x, int y)
//{
//	int now = map[x][y];
//
//	for (int i = x; i < x + n; i++)
//	{
//		for (int j = y; j < y + n; j++)
//		{
//			if (now != map[i][j])
//			{
//				recur(n / 3, x, y);
//				recur(n / 3, x, y + n / 3);
//				recur(n / 3, x, y + 2 * (n / 3));
//				recur(n / 3, x+n/3, y);
//				recur(n / 3, x+n/3, y+n/3);
//				recur(n / 3, x +n / 3, y+2*(n/3));
//				recur(n/3,x+2*(n/3), y);
//				recur(n / 3, x + 2 * (n / 3), y+n/3);
//				recur(n / 3, x + 2 * (n / 3), y + 2*(n / 3));
//
//				return;
//			}
//		}
//	}
//	if (now == -1)
//		mone++;
//	else if (now == 0)
//		zero++;
//	else if (now == 1)
//		one++;
//}
//
//
//int main()
//{
//
//	cin >> n;
//	
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//
//	recur(n, 0, 0);
//	cout << mone << '\n' << zero << '\n' << one;
//
//
//
//	return 0;
//}