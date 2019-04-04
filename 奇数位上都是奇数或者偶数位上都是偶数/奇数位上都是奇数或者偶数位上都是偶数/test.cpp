#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		while (i<len && j<len)
		{
			/*if(arr[i]%2!=0 && arr[j]%2==0)
			{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i+=2;
			j+=2;
			continue;
			}*/
			if (arr[i] % 2 == 0)
				i += 2;
			else if (arr[j] % 2 != 0)
				j += 2;
			else
			{
				swap(arr[i], arr[j]);
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> cur{ 1, 2, 3, 4 };
	s.oddInOddEvenInEven(cur,cur.size());
	for (auto& x : cur)
		cout << x << " ";

	system("pause");
	return 0;
}