#define  _CRT_SECURE_NO_WARNINGS 1

//������Ҫ����Ϊlong long int
//#include<iostream>
//#include<vector>
//#include<deque>
//
//using namespace std;
//
//int main()
//{
//	long long int n, a, b, c, f0;
//	while (cin >> n >> a >> b >> c >> f0){
//		if (n <= 1000000){
//			long long int res;
//			vector<long long int> output(n + 4, 0);
//			output[3] = f0;
//			for (long long int i = 4; i <= n + 3; i++){
//				output[i] = (a*output[i - 1] + b*output[i - 2] + c*output[i - 3] + 2 * (i - 3)*(i - 3) - i + 3 + 32767) % 1000000007;
//			}
//			cout << output[n + 3] << endl;
//		}
//		else{
//			deque<long long int> output2(4, 0);
//			output2[3] = f0;
//			long long int index = 1;
//			while (n--){
//				long long int cur = (a*output2[1] + b*output2[2] + c*output2[3] + 2 * index*index - index + 32767) % 1000000007;
//				//β��֮���ٰ���Ԫ��ɾ��
//				output2.push_back(cur);
//				output2.pop_front();
//				index++;
//			}
//			cout << output2[3] << endl;
//		}
//	}
//}

//������Ҫ����Ϊlong long int
//#include<iostream>
//#include<vector>
//#include<deque>
//
//using namespace std;
//
//int main()
//{
//	long long int n, a, b, c, f0;
//	while (cin >> n >> a >> b >> c >> f0){
//		//���ݳ���ʱ����Ҫ�������飬��������ֻ�����ĸ�ֵ
//		//ʹ��˫�˶���
//		if (n < 0){
//			cout << "0" << endl;
//			continue;
//		}
//		else if (n == 0){
//			cout << f0 << endl;
//			continue;
//		}
//		deque<long long int> output2(4, 0);
//		output2[3] = f0;
//		long long int index = 1;
//		while (n--){
//			long long int cur = (a*output2[1] + b*output2[2] + c*output2[3] + 2 * index*index - index + 32767) % 1000000007;
//			//β��֮���ٰ���Ԫ��ɾ��
//			output2.push_back(cur);
//			output2.pop_front();
//			index++;
//		}
//		cout << output2[3] << endl;
//	}
//}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<long long int> input;
	long long int n = 0;
	cin >> n;
	long long int tmp;
	for (long long int i = 0; i<n; i++){
		cin >> tmp;
		input.push_back(tmp);
	}
	int flag = 0;    //���Ƶ���,�ݼ�
	long long int maxnum = 0;
	long long int index = 0;
	flag = input[0]>input[1] ? 1 : 0;
	for (long long int i = 1; i<input.size(); i++){
		//��ʼ����
		//9 2 5 8 4 1 7
		if (flag == 0){
			if (input[i] > input[i - 1]){
				index++;
				maxnum = max(maxnum, index);
			}
			else if (input[i] < input[i - 1]){
				//˵����ʼ�ݼ���
				flag = 1;//�ı�flag
				index++;
				maxnum = max(maxnum, index);
				continue;//�������ѭ��
			}
			else{//���ʱ��Ҫ���¿�ʼ
				maxnum = max(maxnum, index);
				index = 0;
			}
		}
		//��ʼ�ݼ�
		if (flag == 1){
			if (input[i] < input[i - 1]){
				index++;
				maxnum = max(maxnum, index);
			}
			else if (input[i] > input[i - 1]){
				//��ʼ������
				flag = 0;//�ı�flag
				maxnum = max(maxnum, index);
				index = 1;
				continue;//�������ѭ��
			}
			else{//���ʱ��Ҫ���¿�ʼ
				maxnum = max(maxnum, index);
				index = 0;
			}
		}
		
	}
	cout << maxnum << endl;
}