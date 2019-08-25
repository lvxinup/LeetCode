#define  _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int m;
	
	while (cin >> m){
		vector<vector<string>> input;
		//��ȡ����
		for (int i = 0; i < m; ++i){
			string left, right;
			cin >> left >> right;
			vector<string> tmp;
			tmp.push_back(left);
			tmp.push_back(right);
			input.push_back(tmp);

			//�����ж�
			for (int i = 0; i < m; ++i){
				string left = input[i][0];
				string right = input[i][1];
				int j = 0;
				int output = 0;//0��ʾ��ȣ�-1��ʾ���1��ʾ�Ҵ�
				//��һ���ַ����ߵ�βʱ����ѭ����Ȼ���ж��Ƿ��ߵ�β
				for (j = 0; j < left.size() && j < right.size(); ++j){
					if (left[j] == right[j]){
						output = 0;
						continue;
					}
					else if (left[j]>right[j]){
						output = -1;
						break;
					}
					else{
						output = 1;
						break;
					}
				}
				//�������������ֱ���жϣ�������ѭ��
				if (output == -1){
					cout << "false" << endl;
					continue;
				}
				else if (output == 1){
					cout << "true" << endl;
					continue;
				}
				//������˵��������ȵĲ��ֶ����

				//�����û�ߵ�β
				if (j < left.size()){
					for (; j < left.size(); ++j){
						if (left[j] == '.' || left[j] == '0')
							continue;
						else if (left[j]>'0' && left[j] < '9'){
							output = -1;
							break;
						}
					}
				}
				//����Ҵ�û�ߵ�β
				if (j < right.size()){
					for (; j < right.size(); ++j){
						if (right[j] == '.' || right[j] == '0')
							continue;
						else if (right[j]>'0' && right[j] < '9'){
							output = 1;
							break;
						}
					}
				}
				if (output == 1)
					cout << "true" << endl;
				else
					cout << "false" << endl;
			}
		}
	}

	return 0;
}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int m;
//	vector<int> input;
//	while (cin >> m){
//		for (int i = 0; i<m; ++i){
//			int tmp;
//			cin >> tmp;
//			input.push_back(tmp);
//		}
//		for (int i = 0; i<m; ++i){
//			int flag = input[i];
//			bool output = false;
//			for (int k = 0; k<1000; ++k){
//				long long int index = 0;
//				while (flag){
//					index += ((flag % 10)*(flag % 10));
//					flag = flag / 10;
//				}
//				if (index == 1){
//					output = true;
//					break;
//				}
//				flag = index;
//			}
//			if (!output)
//				cout << "false" << endl;
//			else
//				cout << "true" << endl;
//		}
//	}
//}

//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	string left, right;
//	getline(cin, left);
//	getline(cin, right);
//	if (left.size() <right.size()){
//		string tmp = left;
//		left = right;
//		right = tmp;
//	}
//	int index = 7;
//	for (int i = 0; i < left.size(); i++){
//		if (i == index && !right.empty()){
//			string cur = right.substr(0, 1);
//			left.insert(i, " ");
//			left.insert(i + 1, cur);
//			right.erase(0, 2);
//			index += 10;
//		}
//	}
//	if (!right.empty()){
//		left += " ";
//		left += right;
//	}
//	for (int i = 0; i < left.size(); i++){
//		cout << left[i];
//	}
//	cout << endl;
//}