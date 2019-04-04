#define  _CRT_SECURE_NO_WARNINGS 1

// write your code here cpp
#include<stdio.h>
#include<math.h>

int main()
{
	unsigned long n, a, b;
	while (scanf("%lu", &n)){
		if (n == 0) break;

		a = (unsigned long)pow(5, (double)n);
		b = (unsigned long)pow(4, (double)n);

		printf("%lu %lu\n", a - 4, b - 4 + n);
	}
	return 0;
}