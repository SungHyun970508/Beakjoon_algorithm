#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001];

int N;

int main()
{
	
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	//n�� n-1���� 1�� ���ؼ� ���� �� �ְ�, n/2���� 2�� ���ؼ� ���� �� �ְ�,
	//n/3���� 3�� ���ؼ� ���� �� �ִ�.
	
	for (int i = 4; i <=N; i++)
	{
		dp[i] = dp[i - 1] + 1;//���� dp�迭�� 1�� ���ؼ� �̸� ���� �־����

		if (i % 2 == 0)//2�� ���� �� �ִ� ���
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)//3���� ���� �� �ִ� ���
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N];

	return 0;
}