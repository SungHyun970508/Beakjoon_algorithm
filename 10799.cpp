#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;


int main()
{
	string s;
	cin >> s;

	int answer = 0;

	stack <int> num;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')//여는 괄호라면 스택에 추가
			num.push(1);
		else {
			//레이저를 만난 것이므로 스택을 1개 줄여줌
			num.pop();
			//전 기호가 여는 기호였다면 레이저이므로 열린괄호만큼 개수 추가
			if (s[i - 1] == '(')
				answer += num.size();//answer에 현재까지의 쇠막대기 개수 추가
			else//전 기호가 여는 기호가 아니었다면 쇠막대기의 마지막이므로 1개 추가
				answer++;

		}
	}

	cout << answer;


}

