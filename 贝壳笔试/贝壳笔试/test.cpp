#define  _CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//#include<vector>
//#include <climits>
//using namespace std;
////����n����������Ҫ���ҳ��������������в�ľ���ֵ��С��һ�����֣�����в�ľ���ֵ��ͬ�ģ��������ǰ���һ������
//
////2<n <= 100������������10 ^ 16��Χ��
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
//		long long int left, right;//��ʾ�±�
//		long long int min = INT_MAX*INT_MAX;//����ֵ
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
//		//��̬�滮
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


//���ش�����ʼ�ˣ�Ϊ�˱�֤��ƽ��Ҫ�������˫�����ؽ�СֵҪ���ڵ��ڽϴ�ֵ��90%��
//��ô������N��������ܽ��ж��ٳ������أ���������֮��������һ��������
//
//��һ��N����ʾ����������2 <= N <= 10 ^ 5��
//
//�ڶ���N����������ʾ���أ�0<���� <= 10 ^ 8��
//һ��������ʾ����ܽ��еı�������
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

		//����
		sort(input.begin(), input.end());
		int flag = 0;
		//���ȫ�����ϣ��򷵻ؽ׳�
		if (input[0] == input[input.size() - 1] ){	
			for (int i = input.size() - 1; i>0; i--){
				flag += i;
			}
		}
		else{
			for (int i = 0; i < input.size(); i++){
				long long int index = input[i] * 11111;//��ʾ�ٽ��
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