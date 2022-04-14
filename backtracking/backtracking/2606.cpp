//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//vector <int> v[1001];
//bool visit[1001];
//
//int n, m;
//
//int bfs(int start)
//{
//	queue <int> q;
//	q.push(start);
//	int cnt = 0;
//
//	visit[start] = true;
//
//	while (!q.empty())
//	{
//		int now = q.front();
//		q.pop();
//
//		for (auto nxt : v[now])
//		{
//			if (visit[nxt])
//				continue;
//			q.push(nxt);
//			visit[nxt] = true;
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		v[from].push_back(to);
//		v[to].push_back(from);
//	}
//
//	int answer = 0;
//	fill(visit,visit+n+1,false);
//
//	
//	answer= bfs(1);
//
//	cout << answer;
//	return 0;
//}