#define  _CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//#include<vector>
//#include <climits>
//using namespace std;
////给出n个正整数，要求找出相邻两个数字中差的绝对值最小的一对数字，如果有差的绝对值相同的，则输出最前面的一对数。
//
////2<n <= 100，正整数都在10 ^ 16范围内
//
////9
////1 3 4 7 2 6 5 12 32
////3 4
//
//int main()
//{	
//	int n;
//	while (cin >> n){
//		vector<long long int> input;
//		for (int i = 0; i < n; i++){
//			long long int tmp;
//			cin >> tmp;
//			input.push_back(tmp);
//		}
//
//		long long int left, right;//表示下标
//		long long int min = INT_MAX*INT_MAX;//绝对值
//		for (int i = 1; i < input.size(); i++){
//			long long int cur = input[i] - input[i - 1];
//			if (cur < 0)
//				cur = -cur;
//			if (cur == min)
//				continue;
//			if (cur < min){
//				min = cur;
//				left = input[i - 1];
//				right = input[i];
//			}
//		}
//		cout << left << " " << right << endl;
//	}
//}	

//#include<iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n){
//		vector<int> input;
//		for (int i = 0; i < n; i++){
//			int tmp;
//			cin >> tmp;
//			input.push_back(tmp);
//		}
//
//		//动态规划
//		vector<int> dp;
//		for (int i = 0; i < input.size(); ++i){
//			int left = 0, right = dp.size();
//			while (left < right) {
//				int mid = left + (right - left) / 2;
//				if (dp[mid] < input[i]) left = mid + 1;
//				else right = mid;
//			}
//			if (right >= dp.size()) dp.push_back(input[i]);
//			else dp[right] = input[i];
//		}
//		cout << dp.size() << endl;
//	}
//}


//举重大赛开始了，为了保证公平，要求比赛的双方体重较小值要大于等于较大值的90%，
//那么对于这N个人最多能进行多少场比赛呢，任意两人之间最多进行一场比赛。
//
//第一行N，表示参赛人数（2 <= N <= 10 ^ 5）
//
//第二行N个正整数表示体重（0<体重 <= 10 ^ 8）
//一个数，表示最多能进行的比赛场数
//5
//1 1 1 1 1
//10

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n){
		vector<long long int> input;
		for (int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			input.push_back(tmp);
		}

		//二分
		sort(input.begin(), input.end());
		int flag = 0;
		//如果全部符合，则返回阶乘
		if (input[0] == input[input.size() - 1] ){	
			for (int i = input.size() - 1; i>0; i--){
				flag += i;
			}
		}
		else{
			for (int i = 0; i < input.size(); i++){
				long long int index = input[i] * 11111;//表示临界点
				bool cur = false;
				for (int j = i + 1; j < input.size(); j++){
					if ((input[j] * 10000) <= index)
						flag++;
				}
			}
		}
		cout << flag << endl;
	}
}