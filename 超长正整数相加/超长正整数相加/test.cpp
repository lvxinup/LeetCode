#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

int main()
{
	string a, b;
	string tmp;
	int flag = 0;
	while (cin >> a >> b)
	{
		int pos1 = a.size() - 1, pos2 = b.size() - 1;
		while (pos1 >= 0 && pos2 >= 0)
		{
			if ((a[pos1] - 48) + (b[pos2] - 48) + flag>9)
			{
				tmp.push_back(((a[pos1] - 48) + (b[pos2] - 48) + flag) % 10 + 48);
				pos1--; pos2--;
				flag = 1;
			}
			else
			{
				tmp.push_back(((a[pos1] - 48) + (b[pos2] - 48) + flag) % 10 + 48);
				pos1--; pos2--;
				flag = 0;
			}
		}
		if (pos1 == -1)
		{
			for (int i = pos2; i >= 0; i--)
			{
				tmp.push_back((b[i] - 48 + flag) % 10 + 48);
				if (b[i] - 48 + flag>9)
					flag = 1;
				else
					flag = 0;
			}
		}
		else if (pos2 == -1)
		{
			for (int i = pos1; i >= 0; i--)
			{
				tmp.push_back((a[i] - 48 + flag) % 10 + 48);
				if (a[i] - 48 + flag>9)
					flag = 1;
				else
					flag = 0;
			}
		}
		if (flag != 0)
			tmp.push_back(flag + 48);

		pos1 = 0; pos2 = tmp.size() - 1;
		while (pos1 < pos2)
		{
			tmp[pos1] = tmp[pos1] ^ tmp[pos2];
			tmp[pos2] = tmp[pos1] ^ tmp[pos2];
			tmp[pos1] = tmp[pos1] ^ tmp[pos2];
			pos1++; pos2--;
		}
		cout << tmp << endl;
		tmp = "";
		flag = 0;
	}
	

	system("pause");
	return 0;
}