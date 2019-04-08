#define  _CRT_SECURE_NO_WARNINGS 1

// write your code here cpp
#include <iostream>
#include<math.h>
using namespace std;
int main(){
	int n, k, i;
	while (cin >> n){
		k = 0;
		for (i = 2; i <= sqrt(n); i++)
		{
			if (n%i == 0)
			{
				while (n%i == 0)
					n = n / i;
				k++;
			}
		}
		if (n != 1)k++;
		cout << k << endl;
	}
	return 0;
}