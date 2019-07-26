#define  _CRT_SECURE_NO_WARNINGS 1

// write your code here cpp
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d =", n);
		int i;
		for (i = 2; i <= sqrt(n); i++)
		{
			while (n != i)
			{
				if (n%i == 0)
				{
					printf(" %d *", i);
					n /= i;
				}
				else
					break;              //否则就陷入死循环了
			}
		}
		printf(" %d\n", n);
	}
	return 0;
}