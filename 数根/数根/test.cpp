// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int gen(vector<int> tmp)
{
	long max = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		max += tmp[i];
	}
	if (max < 10)
	{
		return max;
	}
	else
	{
		vector<int> cur;
		while (max)
		{
			cur.push_back(max % 10);
			max=max /10;
		}
		return gen(cur);
	}

}
int main()
{
	string  tmp;
	long max = 0;
	long flag = 0;

	while (getline(cin, tmp))
	{
		vector<int> cur;
		for (int i = 0; i<tmp.size(); i++)
		{
			cur.push_back(tmp[i] - '0');
		}
		cout << gen(cur) << endl;
	}
	return 0;
}