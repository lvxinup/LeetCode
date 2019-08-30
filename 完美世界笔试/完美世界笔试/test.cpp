#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//2->1    3->3    4->8    5->45
int dp(int n){
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return (n - 1)*(dp(n - 1) + dp(n - 2));
}
int main()
{
	int n = 0;
	while (cin >> n){
		if (n == 0 || n == 1)
			cout << '0'<<endl;
		else if (n == 2)
			cout << '1' << endl;
		else if (n == 3)
			cout << '3' << endl;
		else if (n == 4)
			cout << '8' << endl;
		else if (n == 5)
			cout << '45' << endl;
		else
			cout << dp(n) << endl;
	}
}