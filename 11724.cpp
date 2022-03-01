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
		if (!visited[i] && map[num][i] == 1)//������ ����Ǿ� �����鼭 ������ �湮���� ���� ���
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
		map[a][b] = 1;//������ ���� �׷��� �̹Ƿ� �������� 1����
		map[b][a] = 1;
	}

	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])//���� �湮���� ���� ������ ���
		{
			ans++;
			dfs(i);
		}
	}


	cout << ans;

	return 0;

}