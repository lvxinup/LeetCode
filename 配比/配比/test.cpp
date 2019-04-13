#define  _CRT_SECURE_NO_WARNINGS 1

//小M要制作一种黑暗饮料，这种饮料的原料有n种，编号为1 - n，
//已知小M的容器最多容纳V升材料，黑暗料理的各种原料配比为 a1 : a2 : a3 : ... : an, 每种原料分别有b1，b2，... bn升。
//问小M最多可以制作多少升这种饮料。小M使用的各种原料体积和不能超过V

//输入第一行，两个正整数n 和 V，表示原料种类数和容器容积。(1 <= n <= 1000，1 <= V <= 1000000)
//输入第二行包含n个数a1, a2, a3, ...an，表示n种原料的配比。
//输入第三行包含n个数b1, b2, b3...bn，表示小M拥有的各种原料数。（数字间以空格隔开）

//输出包含一个非负数，表示小M最多可以制作多少饮料，结果保留4位小数。

//样例输入2
//2 100
//1 1
//60 60
//
//样例输出2
//100.0000

#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;
int main()
{
	long int n,index;
	long long int max;//容积
	long int sum = 0;
	cin >> n >> max;
	index = n;
	int tmp;
	vector<int> cur;	//配比
	vector<int> input;	//原料数量
	float answer = 0.0;
	while (index)
	{
		cin >> tmp;
		cur.push_back(tmp);
		index--;
	}
	while (n)
	{
		cin >> tmp;
		input.push_back(tmp);
		n--;
	}
	for (auto x : cur)
		sum += x;
	float yifen = (float)max / sum;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i]<=(cur[i] * yifen))	//原料少于比例所需要的
			if(yifen > (float)input[i] / (float)cur[i])
				yifen = (float)input[i] / (float)cur[i];
	}
	for (int i = 0; i < input.size(); i++)
	{
		answer += cur[i] * (float)yifen;
	}
	printf("%0.4f", answer);
	system("pause");
	return 0;
}