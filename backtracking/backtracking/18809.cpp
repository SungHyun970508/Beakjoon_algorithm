#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[51][51];
int n, m, g, r;
vector<pair<int, int>> idxcand;

int dir[2][4] = { {-1,1,0,0},{0,0,-1,1} };

int bfs(vector<int> permu)
{
	pair<int, int> state[51][51];// {arrival time,color}
	//arr이 0이면 갈수없음. 이미 색이 칠해져 있는 경우 

	queue <pair<int, int>> q;

	for (int i = 0; i < idxcand.size(); i++)
	{
		if (permu[i] == 1 || permu[i] == 2)
		{
			state[idxcand[i].first][idxcand[i].second] = { 0,permu[i] };
			q.push(idxcand[i]);
		}
	}
	int cnt = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		int curtime = state[cur.first][cur.second].first;
		int curcolor = state[cur.first][cur.second].second;

		if (state[cur.first][cur.second].second == 3)//색이 3일경우 이미 꽃이다
			continue;

		for (int d = 0; d < 4; d++)
		{
			int nx = cur.first + dir[0][d];
			int ny = cur.second + dir[1][d];

			if (nx < 0 || nx >= n || nx < 0 || ny >= m)
				continue;

			if (arr[nx][ny] == 0)//0일경우 호수라서 갈 수 없음
				continue;

			if (state[nx][ny].second == 0)//아직 아무 색도 칠해지지 않은 경우
			{
				state[nx][ny] = { curtime + 1,curcolor };
				q.push({ nx,ny });
			}

			else if (state[nx][ny].second == 1)//빨간색일 경우
			{
				//현재색이 초록색이고 현재시간보다 1초 지난 후일경우 꽃으로 필 수 있다
				if (curcolor == 2 && state[nx][ny].first == curtime + 1)
				{
					cnt++;
					state[nx][ny].second = 3;
				}

			}
			else if (state[nx][ny].second == 2)//초록색일 경우
			{
				//현재색이 빨간색이고 현재시간보다 1초 지난 후일경우
				if (curcolor == 1 && state[nx][ny].first == curtime + 1)
				{
					cnt++;
					state[nx][ny].second = 3;
				}
			}
		}

	}
	return cnt;


}

int main()
{

	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				idxcand.push_back({ i,j });
			}
		}
	}
	
	vector <int> permu(idxcand.size(), 0);//next_permutation을 위한 변수

	fill(permu.begin(),permu.begin()+ g, 2);//Green은 2,Red는 1
	fill(permu.begin() + g, permu.begin() + g + r, 1);
	
	int mx = 0;

	do {
		mx = max(mx, bfs(permu));
	} while (prev_permutation(permu.begin(), permu.end()));

	cout << mx;

	return 0;
}