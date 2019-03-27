#include<iostream>
using namespace std;

int gcd(int a, int b) // greatest common divisor
{
	while (a%b){
		int tmp = a;
		a = b;
		b = tmp%b;
	}
	return b;

}
int main()
{
	int a, b;
	while (cin >> a >> b){
		cout << a*b / gcd(a, b) << endl;
	}
	return 0;
}
