#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<Windows.h>
using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		std::sort(gifts.begin(), gifts.end());
		unordered_map<int, int> map;
		for (int i = 0; i < gifts.size(); i++)
		{
			map[gifts[i]]++;
		}
		for (auto& x : map) {
			if (x.second>n / 2)
				return x.first;
		}
		
		return 0;
	}
};

int main()
{
	vector<int> tmp = { 1, 2, 3, 3, 2 };

	Gift g;
	cout << g.getValue(tmp, 5) << endl;

	system("pause");
	return 0;
}