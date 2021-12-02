#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <int> nums;
int dp[100001];

int main()
{
	

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		nums.push_back(temp);
	}

	
	dp[0] = nums[0];

	for (int i = 1; i < n; i++)//dp문제 dp를 해당 숫자가 연속합에 들어가는 경우 즉 dp[i]가 이전까지의 
		//연속합 dp[i-1]과 자신의 수(num[i])를 비교하여 둘 중 더큰값을 dp[i]에 갱신
	{
		if (nums[i] + dp[i - 1] > nums[i])
		{
			dp[i] = nums[i] + dp[i - 1];
		}
		else
			dp[i] = nums[i];
	}

	int ans = -987654321;

	for (int i = 0; i < n; i++)
	{
		ans = max(ans, dp[i]);
	}

	cout << ans;
	return 0;
}