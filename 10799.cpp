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
		if (s[i] == '(')//���� ��ȣ��� ���ÿ� �߰�
			num.push(1);
		else {
			//�������� ���� ���̹Ƿ� ������ 1�� �ٿ���
			num.pop();
			//�� ��ȣ�� ���� ��ȣ���ٸ� �������̹Ƿ� ������ȣ��ŭ ���� �߰�
			if (s[i - 1] == '(')
				answer += num.size();//answer�� ��������� �踷��� ���� �߰�
			else//�� ��ȣ�� ���� ��ȣ�� �ƴϾ��ٸ� �踷����� �������̹Ƿ� 1�� �߰�
				answer++;

		}
	}

	cout << answer;


}

