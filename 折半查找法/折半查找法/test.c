//折半查找法
#include<stdio.h>

int serch(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			if (arr[mid]<key)
				left = mid + 1;
			else
			{
				return mid;
			}
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int key = 7;
	int ret = 0;
	ret = serch(arr, 2, 8, key);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%d\n", ret);
	}
	system("pause");
	return 0;
}