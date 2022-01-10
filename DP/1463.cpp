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

	//n은 n-1에서 1을 더해서 만들 수 있고, n/2에서 2을 곱해서 만들 수 있고,
	//n/3에서 3을 곱해서 만들 수 있다.
	
	for (int i = 4; i <=N; i++)
	{
		dp[i] = dp[i - 1] + 1;//현재 dp배열을 1을 더해서 미리 값을 넣어놓기

		if (i % 2 == 0)//2로 나눌 수 있는 경우
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)//3으로 나눌 수 있는 경우
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N];

	return 0;
}