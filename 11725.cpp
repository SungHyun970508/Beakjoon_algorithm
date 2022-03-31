#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int parent[100001];
vector <int> tree[100001];

void Findparent(int nodenum,vector<bool> &visited)
{
	visited[nodenum] = true;

	//dfs진행

	for (int i = 0; i < tree[nodenum].size(); i++)
	{
		int next = tree[nodenum][i];
		if (!visited[next])
		{
			parent[next] = nodenum;
			Findparent(next, visited);
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(0);

	cin.tie(0); //cin 속도 향상

	cin >> N;
	vector<bool> visited(N + 1, false);

	for (int i = 0; i < N - 1; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);//양방향 노드로 삽입
		tree[node2].push_back(node1);
	}

	Findparent(1, visited);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}


	return 0;
}

