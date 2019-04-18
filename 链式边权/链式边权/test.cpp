#define  _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int tmp = 0;
//		vector<int> cur;
//		while (n)
//		{
//			cin >> tmp;
//			cur.push_back(tmp);
//			n--;
//		}
//		if (cur.size() % 2 == 1)
//		{
//			int index = cur.size() - 2;
//			for (int i = 0; i < cur.size()/2; i++)
//			{
//				cout << index << " ";
//				index -= 2;
//			}
//			index = 1;
//			for (int i = 0; i < cur.size() / 2; i++)
//			{
//				cout << index << " ";
//				index += 2;
//			}
//		}
//		else	//Å¼Êý
//		{
//			int index = cur.size() / 2;
//			for (int i = 0; i < cur.size()/2-1; i++)
//			{
//				cout << index << " ";
//				index -= 2;
//			}
//			cout << '0' << " ";
//			index = cur.size() / 2;
//			for (int i = 0; i < cur.size() / 2 - 1; i++)
//			{	
//				cout << index << " ";
//				index += 2;
//			}
//		}
//		cout << endl;
//	}
//}

#include<iostream>
#include<vector>
using namespace std;
int luxian(int number) {
	int result = 0;
	if (number == 0 || number == 1)
	{
		return 1;
	}
	int num = number;
	while (num--)
	{
		result = result + luxian(number - 1);
		number--;
	}
	return result;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> v;
		vector<int> tmp;
		int a, b;
		for (int i = 0; i<n; i++)
		{
			cin >> a >> b;
			tmp.push_back(a);
			tmp.push_back(b);
			v.push_back(tmp);
		}
		int max = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (luxian(v[i][1] - v[i][0])>=max)
				max = luxian(v[i][1] - v[i][0]);
		}
		cout << max-1 << endl;
	}
}