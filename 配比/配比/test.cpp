#define  _CRT_SECURE_NO_WARNINGS 1

//СMҪ����һ�ֺڰ����ϣ��������ϵ�ԭ����n�֣����Ϊ1 - n��
//��֪СM�������������V�����ϣ��ڰ�����ĸ���ԭ�����Ϊ a1 : a2 : a3 : ... : an, ÿ��ԭ�Ϸֱ���b1��b2��... bn����
//��СM�����������������������ϡ�СMʹ�õĸ���ԭ������Ͳ��ܳ���V

//�����һ�У�����������n �� V����ʾԭ���������������ݻ���(1 <= n <= 1000��1 <= V <= 1000000)
//����ڶ��а���n����a1, a2, a3, ...an����ʾn��ԭ�ϵ���ȡ�
//��������а���n����b1, b2, b3...bn����ʾСMӵ�еĸ���ԭ�����������ּ��Կո������

//�������һ���Ǹ�������ʾСM�����������������ϣ��������4λС����

//��������2
//2 100
//1 1
//60 60
//
//�������2
//100.0000

#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;
int main()
{
	long int n,index;
	long long int max;//�ݻ�
	long int sum = 0;
	cin >> n >> max;
	index = n;
	int tmp;
	vector<int> cur;	//���
	vector<int> input;	//ԭ������
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
		if (input[i]<=(cur[i] * yifen))	//ԭ�����ڱ�������Ҫ��
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