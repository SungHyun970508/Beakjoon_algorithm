#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int DP[1001][10];//DP[a][b] a�ڸ��� ������ b�� ���� �������� ���� �� ���������� �� �� �ִ� ����� ��



int main()
{
	cin >> n;
	int ans = 0;

	for (int i = 0; i < 10; i++)
	{
		DP[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				DP[i][j] = DP[i][j] + DP[i - 1][k];
				DP[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		ans += DP[n][i];
	}

	ans = ans % 10007;

	cout << ans;
	return 0;
}