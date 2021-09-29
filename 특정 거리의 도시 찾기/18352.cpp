#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k, x;

bool visit[300001];
vector <int> ans;


int main()
{
	cin >> n >> m >> k >> x;

	vector<vector<int>> city(n + 1);

	int start, to;
	
	for (int i = 0; i < m; i++)
	{
		cin >> start >> to;
		city[start].push_back(to);
	}

	queue<pair<int, int>> q;
	q.push({ x,0 });//��������, �Ÿ�0

	visit[x] = true;

	while (!q.empty())//���ͽ�Ʈ�� Ȱ��
	{
		int now = q.front().first;
		int cost = q.front().second;

		q.pop();

		if (cost == k)
		{
			ans.push_back(now);
		}

		for (int i = 0; i < city[now].size(); i++)
		{
			int next = city[now][i];

			if (!visit[next])
			{
				visit[next] = true;
				q.push({ next,cost + 1 });
			}
		}
	}

	if (ans.empty())//������ ���� ��� -1 ���
	{
		cout << -1;
		return 0;
	}



	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]<<endl;
	}


	return 0;
}