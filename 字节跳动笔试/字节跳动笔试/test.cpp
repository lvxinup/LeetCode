#define  _CRT_SECURE_NO_WARNINGS 1

//ʹ��һ����ά���飬���й�ϵ�ķ���һ�У����Ķ���ƿ����Ϊ��ά�����size
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<algorithm>
//
//using namespace std;
//int main()
//{
//	long long int N;
//	while (cin >> N){
//		vector<vector<long long int>> input;
//		for (long long int i = 0; i < N; ++i){
//			vector<long long int> tmp;
//			for (int j = 0; j < N; ++j){
//				long long int cur;
//				cin >> cur;
//				tmp.push_back(cur);
//			}
//			input.push_back(tmp);
//		}
//		vector<vector<long long int>> output;
//		//���Ƚ�����Ԫ�ر���һ��
//		for (long long int i = 0; i < input.size(); ++i){
//			for (long long int j = 0; j < input[i].size(); ++j){
//				if (input[i][j] >= 3){
//					//������output�в���
//					bool index = false;	//��������ж�Ҫ��Ҫ���Ӷ���ƿ������
//					for (long long int k = 0; k < output.size(); k++){
//						//���i��������
//						if (find(output[k].begin(), output[k].end(), i + 1) != output[k].end()){
//							index = true;
//							//�ж�j�ڲ��ڣ����ڵĻ�������j
//							if (find(output[k].begin(), output[k].end(), j + 1) == output[k].end()){
//								output[k].push_back(j + 1);
//								N--;
//							}
//							//j�������еĻ�����ʲô��������ֱ������������жϣ�����ƿ��������
//							else{
//								break;
//							}
//						}
//						//���j��������
//						else if (find(output[k].begin(), output[k].end(), j + 1) != output[k].end()){
//							index = true;
//							//���i���������У�����i
//							if (find(output[k].begin(), output[k].end(), i + 1) == output[k].end()){
//								output[k].push_back(i + 1);
//								N--;
//							}
//								
//							//�������еĻ���ʲô������������������жϣ�����ƿ��������
//							else
//								break;
//						}
//					}
//					//���i��j�����������У����������в����µ�һ��
//					if (index == false){
//						vector<long long int> temp;
//						temp.push_back(i + 1);
//						temp.push_back(j + 1);
//						output.push_back(temp);
//						N--;
//					}
//				}
//				else
//					continue;
//			}
//		}
//		cout << N << endl;	
//	}
//}


#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int n;
	while (cin >> n){
		vector<vector<long long int>> input;
		for (long long int i = 0; i < 4; ++i){
			vector<long long int> tmp;
			for (int j = 0; j < 4; ++j){
				long long int cur;
				cin >> cur;
				tmp.push_back(cur);
			}
			input.push_back(tmp);
		}
		//����n�ж���������
		//����
		if (n == 1){
			//�Ⱥϲ���Ȼ��ϲ�����������һ��Ȼ����һ��0���������ƶ����������Ϊ0���������ƶ�
			//���ж������������ܲ��ܺϲ�
			for (int i = 0; i < 4; i++){
				//����Ҳ�Ϊ0������Ժϲ���
				if ((input[0][i] == input[1][i]) && (input[0][i] != 0) && (input[1][i] != 0)){
					input[0][i] = (input[0][i] + input[1][i]);
					input[1][i] = 0;
				}
				//�����ܺϲ�,���ܺϲ����ù�
			}
			//Ȼ���ж����������ܲ��ܺϲ�
			for (int i = 0; i < 4; i++){
				//����Ҳ�Ϊ0������Ժϲ���
				if ((input[2][i] == input[3][i]) && (input[2][i] != 0) && (input[3][i] != 0)){
					input[2][i] = (input[2][i] + input[3][i]);
					input[3][i] = 0;
				}
				//�����ܺϲ�,���ܺϲ����ù�
			}
			//Ȼ��������ƣ��������Ϊ0���������ƶ�
			for (int i = 0; i < 4; i++){//��
				for (int j = 1;j <=3; j++){//��
					//��Ϊ0��������Ϊ0���������ƶ�
					int i1 = i, j1 = j;
					while (input[j1][i1] != 0 && input[j1-1][i1] == 0){
						//�������ƣ�����ԭ����λ����0
						input[j1 - 1][i1] = input[j1][i1];
						input[j1][i1] = 0;
						j1--;
						if (j1 == 0)
							break;
					}
				}
			}
		}
		else if (n == 2){
			//�Ⱥϲ���Ȼ��ϲ�����������һ��Ȼ����һ��0���������ƶ����������Ϊ0���������ƶ�
			//���ж������������ܲ��ܺϲ�
			for (int i = 0; i < 4; i++){
				//����Ҳ�Ϊ0������Ժϲ���
				if ((input[0][i] == input[1][i]) && (input[0][i] != 0) && (input[1][i] != 0)){
					input[1][i] = (input[0][i] + input[1][i]);
					input[0][i] = 0;
				}
				//�����ܺϲ�,���ܺϲ����ù�
			}
			//Ȼ���ж����������ܲ��ܺϲ�
			for (int i = 0; i < 4; i++){
				//����Ҳ�Ϊ0������Ժϲ���
				if ((input[2][i] == input[3][i]) && (input[2][i] != 0) && (input[3][i] != 0)){
					input[3][i] = (input[2][i] + input[3][i]);
					input[2][i] = 0;
				}
				//�����ܺϲ�,���ܺϲ����ù�
			}
			//Ȼ��������ƣ��������Ϊ0���������ƶ�
			for (int i = 0; i < 4; i++){//��
				for (int j = 2; j >=0; j--){//��
					//��Ϊ0��������Ϊ0���������ƶ�
					int i1 = i, j1 = j;
					while (input[j1][i1] != 0 && input[j1 + 1][i1] == 0){
						//�������ƣ�����ԭ����λ����0
						input[j1 + 1][i1] = input[j1][i1];
						input[j1][i1] = 0;
						j1++;
					}
				}
			}
		}
		//�����ƶ�
		else if (n == 3){
			//�Ⱥϲ���Ȼ��ϲ�����������һ��Ȼ����һ��0���������ƶ����������Ϊ0���������ƶ�
			//���ж������������ܲ��ܺϲ�
			for (int i = 0; i < 4; i++){
				//����Ҳ�Ϊ0������Ժϲ���
				if ((input[i][0] == input[i][1]) && (input[i][0] != 0) && (input[i][1] != 0)){
					input[i][0] = (input[i][0] + input[i][1]);
					input[i][1] = 0;
				}
				//�����ܺϲ�,���ܺϲ����ù�
			}
			//Ȼ���ж����������ܲ��ܺϲ�
			for (int i = 0; i < 4; i++){
				//����Ҳ�Ϊ0������Ժϲ���
				if ((input[i][2] == input[i][3]) && (input[i][2] != 0) && (input[i][3] != 0)){
					input[i][2] = (input[i][2] + input[i][3]);
					input[i][3] = 0;
				}
				//�����ܺϲ�,���ܺϲ����ù�
			}
			//Ȼ��������ƣ��������Ϊ0���������ƶ�
			for (int i = 0; i < 4; i++){//��
				for (int j = 3; j >=1; j--){//��
					//��Ϊ0��������Ϊ0���������ƶ�
					int i1 = i, j1 = j;
					while (input[i1][j1] != 0 && input[i1][j1-1] == 0){
						//�������ƣ�����ԭ����λ����0
						input[i1][j1-1] = input[i1][j1];
						input[i1][j1] = 0;
						j1++;
					}
				}
			}
		}
		//����
		else if (n == 4){
			//�Ⱥϲ���Ȼ��ϲ�����������һ��Ȼ����һ��0���������ƶ����������Ϊ0���������ƶ�
			//���ж������������ܲ��ܺϲ�
			for (int i = 0; i < 4; i++){
				//����Ҳ�Ϊ0������Ժϲ���
				if ((input[i][0] == input[i][1]) && (input[i][0] != 0) && (input[i][1] != 0)){
					input[i][1] = (input[i][0] + input[i][1]);
					input[i][0] = 0;
				}
				//�����ܺϲ�,���ܺϲ����ù�
			}
			//Ȼ���ж����������ܲ��ܺϲ�
			for (int i = 0; i < 4; i++){
				//����Ҳ�Ϊ0������Ժϲ���
				if ((input[i][2] == input[i][3]) && (input[i][2] != 0) && (input[i][3] != 0)){
					input[i][3] = (input[i][2] + input[i][3]);
					input[i][2] = 0;
				}
				//�����ܺϲ�,���ܺϲ����ù�
			}
			//Ȼ��������ƣ��������Ϊ0���������ƶ�
			for (int i = 0; i < 4; i++){//��
				for (int j = 2; j>=0; j--){//��
					//��Ϊ0��������Ϊ0���������ƶ�
					if (input[i][j] != 0 && input[i][j+1] == 0){
						//�������ƣ�����ԭ����λ����0
						input[i][j+1] = input[i][j];
						input[i][j] = 0;
					}
				}
			}
		}

		//��ӡ
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				cout << input[i][j] << " ";
			}
			cout << endl;
		}
	}
}