#define  _CRT_SECURE_NO_WARNINGS 1


//������Ҫ����ģ��һ����Windowsϵͳ�ﴰ�ں�������Ĳ������������£�
//1.��Ļ�ֱ���Ϊ3840 * 2160�����Ͻ�����Ϊ(0, 0)�� ���½�����Ϊ(3839, 2159)
//2.������һ�����ε���״�������Ͻ�����(X, Y)���Ϳ��(W, H)���ĸ���������λ��
//���Ͻ�����Ϊ(X, Y)�����½�����Ϊ(X + W, Y + H)���������Ͻ�����һ��������Ļ��Χ�ڣ�����һЩ���ֿ��ܻᳬ����Ļ��Χ��
//3.���ڵĵ�����ڵ�����ͬWindows�����ǲ����ǹرմ��ڡ���󻯡���С����ǿ���ö����������
//3.1 ��������ص��Ļ�������򿪵Ĵ��ڻ���ʾ��ǰ��򿪵Ĵ�������
//3.2 ����귢��һ�ε����ʱ����Ҫ�жϵ�������ĸ����ڣ����ͬ�������ж�����ڣ����������ϲ���Ǹ�
//3.3 ��һ�����ڱ������ʱ�򣬻ḡ�������ϲ�
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
////��������ʹ����жϵĺ���
//bool inwindow(vector<int> zuobiao, vector<int> chuangkou){
//	if ((zuobiao[0] >= chuangkou[0] && zuobiao[0] <= chuangkou[2]) && (zuobiao[1] >= chuangkou[1] && zuobiao[1] <= chuangkou[3])){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//
//int main()
//{
//	int a, b;
//	//a��������Ŀ��b����������
//	while (cin >> a >> b){
//		vector<vector<int>> window;    //����
//		vector<vector<int>> index;    //���λ��
//		int mainwindow = 2;    //������ID
//		vector<int> primary(a + 1);    //�������ȼ�
//		for (int i = 1; i <= a; i++){
//			primary[i] = i;
//		}
//		int x, y, w, h;
//		while (a--){
//			cin >> x >> y >> w >> h;
//			//3840*2160
//			if (x + w >= 3840)
//				w = 3839;
//			if (y + h >= 2160)
//				h = 2159;
//			vector<int> tmp1;
//			tmp1.push_back(x);
//			tmp1.push_back(y);
//			tmp1.push_back(x + w);
//			tmp1.push_back(y + h);
//			window.push_back(tmp1);
//		}
//		int x1, y1;
//		for(int i = 0;i<b;i++){
//			cin >> x1 >> y1;
//			vector<int> tmp2;
//			tmp2.push_back(x1);
//			tmp2.push_back(y1);
//			index.push_back(tmp2);
//		}
//		vector<int> output;    //�������
//		for (int i = 0; i<index.size(); i++){
//			int temp;
//			bool need = false;//�ж��Ƿ���Ҫ���´������ȼ�
//			bool output1 = false;
//			for (int j = primary.size() - 1; j >= 1; j--){
//				if (inwindow(index[i], window[primary[j] - 1])){
//					output.push_back(primary[j]);
//					temp = j;
//					need = true;
//					output1 = true;
//					break;
//				}
//			}
//			if (output1 == false){
//				output.push_back(-1);
//			}
//			if (need){
//				//���Ĵ������ȼ�
//				int flag = primary[temp];
//				for (int k = temp; k<=primary.size() - 2; k++){
//					primary[k] = primary[k + 1];
//				}
//				primary[primary.size() - 1] = flag;
//			}
//		}
//
//		//��ӡ����id��output����
//		for (int i = 0; i<output.size(); i++){
//			cout << output[i] << endl;
//		}
//	}
//
//
//	return 0;
//}


//��Ϸ��������
//- ����������N�����֣�A1~AN�����������г�һ��
//- A��B�����������������Ϸ����һ�غ�A����ж����ڶ��غ�B����ж��������ж�ֱ����Ϸ����
//- ÿ�غ���ҿ���ѡ����������������߻������ұߵ�һ�����֣�����Ķ�������
//- ���ߵ��������δ������������Լ���ǰ
//- �������������ֱ����ߺ���Ϸ����
//- ���Ų��Ե�˵��������������£�������ȡ��ߵ����ֻ���ȡ�ұߵ����֣��������ŵ÷ֶ�һ������ôֻ��ȡ��ߵ�����
//
//���������ֶ������ߺ�A, B���������ǰ������һ�����С�
//����A�����ǰ���ִ�����Ϊ X1, X2, X3...XM�����������յ÷�Sa���㷽ʽ���£�B��ҵĵ÷ּ���SbҲ���ƣ���׸������
//Sa = abs(X1 - 0) + abs(X2 - X1) + abs(X3 - X2) + ... + abs(XM - X(M - 1))
//
//
//����������ϵĹ����£����������Ҷ����õ�������ķ����������Ų��Խ�����Ϸ�����������˵����յ÷֡�
//��������:
//��һ��һ������ N, һ��Ĳ�������(0 < N <= 50)��һ��Ĳ�������(0 < N <= 1000)
//	�ڶ���N������ Ai(0 <= Ai <= 50)
//������� :
//	 �ÿո��������������Sa��Sb
//	 ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
//	 ����
//	 4
//	 1 2 3 4
//	 ���
//   7 4



#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int main()
{
	int N;
	while (cin >> N){
		int tmp;
		vector<int> input;
		for (int i = 0; i<N; i++){
			cin >> tmp;
			input.push_back(tmp);
		}
		long long int sa = 0, sb = 0;
		vector<int> v1(1, 0);
		vector<int> v2(1, 0);
		int left = 0, right = input.size() - 1;//��ʾ���ݵĳ���
		//0��Ԫ��
		if (N == 0){
			cout << "0" << " " << "0" << endl;
			continue;
		}

		//һ��Ԫ��
		if (N == 1){
			cout << input[0] << " " << "0" << endl;
			continue;
		}
		while (left <= right){
			if (right<left)
				break;
			//a����
			//�ұߴ�
			if (abs(input[right] - v1[v1.size() - 1]) > abs(input[left] - v1[v1.size() - 1])){
				v1.push_back(input[right]);
				sa += abs(v1[v1.size() - 1] - v1[v1.size() - 2]);
				right--;
			}
			else{//��ߴ�
				v1.push_back(input[left]);
				sa += abs(v1[v1.size() - 1] - v1[v1.size() - 2]);
				left++;
			}
			if (right<left)
				break;
			//b����
			//�ұߴ�
			if (abs(input[right] - v2[v2.size() - 1]) > abs(input[left] - v2[v2.size() - 1])){
				v2.push_back(input[right]);
				sb += abs(v2[v2.size() - 1] - v2[v2.size() - 2]);
				right--;
			}
			else{//��ߴ�
				v2.push_back(input[left]);
				sb += abs(v2[v2.size() - 1] - v2[v2.size() - 2]);
				left++;
			}
		}
		cout << sa << " " << sb << endl;
	}

	return 0;
}