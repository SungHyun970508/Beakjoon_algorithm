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

	for (int i = 1; i < n; i++)//dp���� dp�� �ش� ���ڰ� �����տ� ���� ��� �� dp[i]�� ���������� 
		//������ dp[i-1]�� �ڽ��� ��(num[i])�� ���Ͽ� �� �� ��ū���� dp[i]�� ����
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