#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int n, e;
int v1, v2;
int dis[801];
int Max = 987654321;
vector <pair<int, int>> graph[801];


void dijk(int start)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = Max;
	}

	dis[start] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0,start });
	
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int ncost = graph[cur][i].second;

			if (dis[next] > dis[cur] + ncost)
			{
				dis[next] = dis[cur] + ncost;
				pq.push({ dis[next],next });
			}
		}
	}
}

int main()
{


	cin >> n >> e;

	
	int a, b, c;

	for (int i = 0; i < e; i++)
	{
		
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	cin >> v1 >> v2;

	/*
	1에서 N까지 가는데 v1과 v2를 무조건 지나야 하므로
	경로는 1->v1->v2->N 혹은 1->v2->v1->N 두가지의 경우가 있고
	이 두가지 경로를 구해서 둘중 작은 값이 답.
	*/

	dijk(1);

	int startTov1 = dis[v1];
	int startTov2 = dis[v2];

	dijk(v1);

	int v1Toend = dis[n];
	int v1Tov2 = dis[v2];

	dijk(v2);

	int v2Toend = dis[n];
	int v2Tov1 = dis[v1];

	int ans1 = Max;
	int ans2 = Max;


	if (startTov1 != Max && v1Tov2 != Max && v2Toend != Max)
		ans1 = startTov1 + v1Tov2 + v2Toend;

	if (startTov2 != Max && v2Tov1 != Max && v1Toend != Max)
		ans2 = startTov2 + v2Tov1 + v1Toend;


	int answer = Max;

	answer = min(ans1, ans2);

	if (answer == Max)
		cout << -1;
	else
		cout << answer;


	return 0;

}