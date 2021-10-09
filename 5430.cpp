#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int t;
	
	int n;
	int num;
	string s;
	string numbers;

	bool reverse;
	bool error;

	deque <int> d;

	cin >> t;

	while (t--)
	{
		d.clear();
		num = 0;
		reverse = false;
		error = false;

		cin >> s;
		cin >> n;
		cin >> numbers;

		numbers = numbers.substr(1, numbers.size() - 2);

		for (int i = 0; i < numbers.size(); i++)
		{
			if (atoi(numbers.substr(i, 1).c_str()) != 0 || numbers.substr(i, 1).compare("0") == 0)
			{
				num *= 10;
				num += stoi(numbers.substr(i, 1));
			}
			else
			{
				d.push_back(num);
				num = 0;
			}

			
		}
		if (num != 0)
		{
			d.push_back(num);
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R')
			{
				reverse = !reverse;//�����ϱ� reverse�� true�� false�� ������ �ƴ϶� reverse�� �ݴ�� ������Ѵ�
			}
			else if (s[i] == 'D')
			{
				if (d.empty())
				{
					error = true;
					break;
				}
				if (reverse)
					d.pop_back();
				else
					d.pop_front();
			}
		}

		if (error)
		{
			cout << "error" << endl;
			continue;
		}

		cout << "[";
		if (reverse)
		{
			while (d.size())
			{
				cout << d.back();
				d.pop_back();
				if (d.size())
				{
					cout << ",";
				}
			}
		}
		else
		{
			while (d.size())
			{
				cout << d.front();
				d.pop_front();
				if (d.size())
					cout << ",";
			}
		}
		cout << "]" << endl;

	}




	return 0;
}