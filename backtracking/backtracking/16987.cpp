#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> egg;
int N;
bool iscrushed[9];//각 계란이 깨졌는지 안깨졌는지 판단g하려고 했으나 굳이 필요없는 배열이엇다.

int Mx = 0;
int cnt = 0;//깨져있는 계란의 수

void dfs(int idx)//idx번째 계란으로 다른걸 깰 차례
{
	if (idx == N)//가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 종료
	{
		Mx = max(Mx, cnt);
		return;
	}//idx가 N-1이 아니라 N일때 종료이다.
	if (egg[idx].first <= 0 || cnt == N - 1)//현재 든 계란이 깨져있거나 다른 모든 계란이 깨져있으면 넘어감
	{
		dfs(idx + 1);
		return;
	}

	for (int i = 0; i < N; i++)//i번째 계란을 내려치고 싶다
	{
		if (i == idx or egg[i].first<=0)//같은 계란이거나 내려칠 계란이 이미 깨져있는경우
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