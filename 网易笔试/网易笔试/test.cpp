#define  _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include<math.h>
//#include<Windows.h>
//using namespace std;
//
//int main()
//{
//	long a, b;
//	while (cin >> a){
//		while (cin >> b){
//			long maxnum = 1;
//			long length = a>b ? a : b;
//			for (int i = 2; i <= length / 2; i++){
//				if (a % i == 0 && b % i == 0)    //i是a,b的约数
//					maxnum = maxnum > i ? maxnum : i;
//				if (i > a || i >b)
//					break;
//			}
//			cout << maxnum << endl;
//		}
//	}
//
//}

#include<Windows.h>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

string inttostr(int a){
	string index;
	while (a>0){
		index += (a % 2 + '0');
		a = a / 2;
	}
	string k;
	for (int i = index.size() - 1; i >= 0; i--)
		k += index[i];
	return k;
}

int main()
{
	int tmp;
	while (cin >> tmp){
		int a, b;
		vector<int> input1;
		vector<int> input2;
		while (tmp--){
			cin >> a >> b;
			if (a == 1)
				input1.push_back(b);
			else{
				input2.push_back(b);
				string a1, b1;
				for (int i = 0; i<input1.size(); i++){
					string tmp = inttostr(input1[i]);
					a1 = a1 + tmp;
				}

				string temp = inttostr(b);
				if (a1.find(temp) != string::npos)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}

		}

	}
}






//#include<iostream>
//#include<vector>
//#include<math.h>
//
//using namespace std;
//
//int main()
//{
//	long n;
//	while (cin >> n){
//		vector<long> input(n, 0);
//		vector<long> output(n, 0);
//		long tmp;
//		long maxnum = 0;
//		for (long i = 0; i<n; i++){
//			cin >> tmp;
//			maxnum = tmp>maxnum ? tmp : maxnum;
//			input[i] = tmp;
//			output[i] = maxnum;
//		}
//		for (auto& e : output)
//			cout << e;
//		cout << endl;
//	}
//}