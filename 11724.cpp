#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int map[1001][1001] = { 0, };
bool visited[1001] = { false, };

void dfs(int num)
{
	visited[num] = true;
	
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && map[num][i] == 1)//간선이 연결되어 있으면서 정점이 방문되지 않은 경우
		{
			dfs(i);//dfs
		}
	}

}

int main()
{

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;//방향이 없는 그래프 이므로 양쪽으로 1저장
		map[b][a] = 1;
	}

	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])//아직 방문하지 않은 정점일 경우
		{
			ans++;
			dfs(i);
		}
	}


	cout << ans;

	return 0;

}