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
	//arr�� 0�̸� ��������. �̹� ���� ĥ���� �ִ� ��� 

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

		if (state[cur.first][cur.second].second == 3)//���� 3�ϰ�� �̹� ���̴�
			continue;

		for (int d = 0; d < 4; d++)
		{
			int nx = cur.first + dir[0][d];
			int ny = cur.second + dir[1][d];

			if (nx < 0 || nx >= n || nx < 0 || ny >= m)
				continue;

			if (arr[nx][ny] == 0)//0�ϰ�� ȣ���� �� �� ����
				continue;

			if (state[nx][ny].second == 0)//���� �ƹ� ���� ĥ������ ���� ���
			{
				state[nx][ny] = { curtime + 1,curcolor };
				q.push({ nx,ny });
			}

			else if (state[nx][ny].second == 1)//�������� ���
			{
				//������� �ʷϻ��̰� ����ð����� 1�� ���� ���ϰ�� ������ �� �� �ִ�
				if (curcolor == 2 && state[nx][ny].first == curtime + 1)
				{
					cnt++;
					state[nx][ny].second = 3;
				}

			}
			else if (state[nx][ny].second == 2)//�ʷϻ��� ���
			{
				//������� �������̰� ����ð����� 1�� ���� ���ϰ��
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
	
	vector <int> permu(idxcand.size(), 0);//next_permutation�� ���� ����

	fill(permu.begin(),permu.begin()+ g, 2);//Green�� 2,Red�� 1
	fill(permu.begin() + g, permu.begin() + g + r, 1);
	
	int mx = 0;

	do {
		mx = max(mx, bfs(permu));
	} while (prev_permutation(permu.begin(), permu.end()));

	cout << mx;

	return 0;
}