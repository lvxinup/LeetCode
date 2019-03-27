#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include<algorithm>

using namespace std;
int main()
{
	int n;
	while (cin >> n){
		long long sum = 0;
		vector<int> a(3 * n);
		for (int i = 0; i < (3 * n); i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2){
			sum += a[i];
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}