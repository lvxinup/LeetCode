#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	while (cin >> N >> M){
		vector<int> step(M + 1, INT_MAX);
		step[N] = 0;
		for (int i = 0; i <= M; i++){
			if (step[i] == INT_MAX){
				//N֮ǰֱ��continue������ѭ�����������Ч�ʡ�
				continue;
			}
			for (int j = 2; (j*j) <= i; j++){
				if (i%j == 0){
					if (i + j <= M){    //Լ��
						//״̬ת�Ʒ��̣������Լ����������1��ͬʱ��Ҫ�ŵ�λ�ñȽ�
						//��ʼֵΪINT_MAX������С��ֵ���棬������õ����С����
						step[i + j] = min(step[i] + 1, step[i + j]);
					}
					if (i + (i / j) <= M){    //Լ��
						step[i + (i / j)] = min(step[i] + 1, step[i + (i / j)]);
					}
				}
			}
		}
		//������ܵ����� -1
		if (step[M] == INT_MAX)
			step[M] = -1;
		cout << step[M] << endl;
	}

	return 0;
}