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
				//N之前直接continue，减少循环次数，提高效率。
				continue;
			}
			for (int j = 2; (j*j) <= i; j++){
				if (i%j == 0){
					if (i + j <= M){    //约数
						//状态转移方程，如果是约数，则步数加1，同时跟要放的位置比较
						//初始值为INT_MAX，将较小的值保存，即到达该点的最小步数
						step[i + j] = min(step[i] + 1, step[i + j]);
					}
					if (i + (i / j) <= M){    //约数
						step[i + (i / j)] = min(step[i] + 1, step[i + (i / j)]);
					}
				}
			}
		}
		//如果不能到达，输出 -1
		if (step[M] == INT_MAX)
			step[M] = -1;
		cout << step[M] << endl;
	}

	return 0;
}