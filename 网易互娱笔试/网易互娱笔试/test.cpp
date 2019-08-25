#define  _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include<vector>
//#include<string>
//#include<cstdio>
//#include<cstdlib>
//#include<Windows.h>
//
//using namespace std;
//
//int onenumber(int a){
//	int flag = 0;
//	while (a > 0){
//		if (a % 2 == 1)
//			flag++;
//		a /= 2;
//	}
//	return flag;
//}
//
//int main()
//{
//	//2147483646
//	int T;//��������
//	while (cin >> T){
//		vector<vector<int>> input;//��������
//		for (int j = 0; j < T; j++){
//			int N, tmp;//N��ʾ����ĳ���
//			cin >> N;
//			vector<int> temp;
//			for (int i = 0; i < N; i++){
//				cin >> tmp;
//				temp.push_back(tmp);
//			}
//			input.push_back(temp);
//		}
//		for (int i = 0; i < T; i++){
//			vector<int> output(32, 0);//32λ��ʾ1�ĸ�������಻����32
//			int cur = 0;
//			for (int j = 0; j < input[i].size(); j++){
//				int index = onenumber(input[i][j]);
//				if (output[index] == 0)
//					cur++;
//				output[index] = 1;
//			}
//			cout << cur << endl;
//		}
//		
//	}
//
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//#include<cstdio>
//#include<cstdlib>
//
//using namespace std;
//
//int main()
//{
//	int T;//��������
//	while (cin >> T){
//		vector<vector<int>> input;//��������
//		for (int j = 0; j < T; j++){
//			vector<int> temp;
//			int tmp;
//			for (int i = 0; i < 6; i++){
//				cin >> tmp;
//				temp.push_back(tmp);
//			}
//			input.push_back(temp);
//		}
//
//
//	}
//	return 0;
//}









#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>

using namespace std;

int main()
{
	//2147483646
	long long int n;//�����վ�ĸ���
	while (cin >> n){
		vector<long long int> input;//�����վ�ĺ���
		vector<long long int> nums;//��ˮ�ĸ߶�
		unordered_map<int, int> map;
		for (long long int i = 0; i < n; i++){
			long long int tmp1;
			cin >> tmp1;
			input.push_back(tmp1);
		}
		long long int q;//��ʾ��ˮ������
		cin >> q;
		long long int tmp2;
		for (long long int i = 0; i < q; i++){
			cin >> tmp2;
			nums.push_back(tmp2);
		}
		//ÿһ����ˮ����һ�����
		for (long long int i = 0; i < nums.size(); i++){
			if (map.count(nums[i])){
				cout << map[nums[i]] << endl;
				continue;
			}
			long long int flag = 0;
			vector<long long int> temp(input);	//ÿ���ж�ʱ��ʹ�ú��������һ������
			bool up = false, down = false;
			if (temp[0] > nums[i])
				up = true;
			if (temp[0] > nums[i] && temp[1] <= nums[i]){
				flag++;
				up = false;
			}
			if (temp[temp.size() - 1] > nums[i] && temp[temp.size() - 2] <= nums[i])
				flag++;
			for (int j = 1; j < temp.size()-1; j++){
				if (temp[j] > nums[i] && temp[j - 1] <= nums[i])
					up = true;	//����
				if (temp[j] > nums[i] && temp[j + 1] <= nums[i])
					down = true;	//�½�
				if (up && down){
					flag++;
					up = false;
					down = false;
				}
			}
			if (up == true)	//���һλ���Ǵ���0
				flag++;
			cout << flag << endl;
			map[nums[i]] = flag;
		}
	}
	return 0;
}

/*
10
2147483646 2147483644 2147483642 2147483643 2147483645 2147483641 2147483643 2147483645 2147483644 2147483646
6
2147483646 2147483644 2147483642 2147483643 2147483645 2147483641

*/