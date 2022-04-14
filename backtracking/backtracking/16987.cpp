#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> egg;
int N;
bool iscrushed[9];//�� ����� �������� �ȱ������� �Ǵ�g�Ϸ��� ������ ���� �ʿ���� �迭�̾���.

int Mx = 0;
int cnt = 0;//�����ִ� ����� ��

void dfs(int idx)//idx��° ������� �ٸ��� �� ����
{
	if (idx == N)//���� �ֱٿ� �� ����� ���� �����ʿ� ��ġ�� ����� ��� ����
	{
		Mx = max(Mx, cnt);
		return;
	}//idx�� N-1�� �ƴ϶� N�϶� �����̴�.
	if (egg[idx].first <= 0 || cnt == N - 1)//���� �� ����� �����ְų� �ٸ� ��� ����� ���������� �Ѿ
	{
		dfs(idx + 1);
		return;
	}

	for (int i = 0; i < N; i++)//i��° ����� ����ġ�� �ʹ�
	{
		if (i == idx or egg[i].first<=0)//���� ����̰ų� ����ĥ ����� �̹� �����ִ°��
			continue;

		egg[idx].first -= egg[i].second;
		egg[i].first -= egg[idx].second;

		if (egg[idx].first <= 0)
			cnt++;
		if (egg[i].first <= 0)
			cnt++;

		dfs(idx + 1);

		if (egg[idx].first <= 0)
			cnt--;
		if (egg[i].first <= 0)
			cnt--;

		egg[idx].first += egg[i].second;
		egg[i].first += egg[idx].second;
	}


}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int strong, wei;
		cin >> strong >> wei;

		egg.push_back({ strong,wei });
	}

	fill(iscrushed, iscrushed + 9, false);

	dfs(0);

	cout << Mx;




	return 0;
}