//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int n, x;
//
//
//void findpair()
//{
//
//}
//
//int main()
//{
//
//	int answer = 0;
//	cin >> n;
//	vector<int> v;
//
//	for (int i = 0; i < n; i++)
//	{
//		int num;
//		cin >> num;
//		v.push_back(num);
//	}
//	
//	cin >> x;
//	int arr[2000001] = { 0, };
//
//	for (auto i : v)
//	{
//		//x-v[i]�� �����ϴ��� Ȯ��
//		//������������ �ڵ� �ۼ��� O(n^2)�̶� �ð��ʰ� ����
//		if (x-i>0 && arr[x - i] == 1)
//		{
//			answer++;
//		}
//		arr[i] = 1;
//
//	}
//
//	cout << answer;
//
//	return 0;
//
//
//}