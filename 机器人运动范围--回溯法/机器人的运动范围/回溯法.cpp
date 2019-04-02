#define  _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool* flag = new bool[rows*cols];
		for (int i = 0; i<rows*cols; i++)
			flag[i] = false;
		int count = moving(threshold, rows, cols, 0, 0, flag);//从（0,0）坐标开始访问;
		delete[] flag;
		return count;
	}
	//计算最大移动位置
	int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		int count = 0;
		if (check(threshold, rows, cols, i, j, flag))
		{
			flag[i*cols + j] = true;
			//标记访问过，这个标志flag不需要回溯，因为只要被访问过即可。
			//因为如果能访问，访问过会加1.不能访问，也会标记下访问过。
			count = 1 + moving(threshold, rows, cols, i - 1, j, flag)
				+ moving(threshold, rows, cols, i, j - 1, flag)
				+ moving(threshold, rows, cols, i + 1, j, flag)
				+ moving(threshold, rows, cols, i, j + 1, flag);
		}
		return count;
	}
	//检查当前位置是否可以访问
	bool check(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		if (i >= 0 && i<rows && j >= 0 && j<cols
			&& getSum(i) + getSum(j) <= threshold
			&& flag[i*cols + j] == false)
			return true;
		return false;
	}
	//计算位置的数值
	int getSum(int number)
	{
		int sum = 0;
		while (number>0)
		{
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
};

class Func {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<bool> flag;
		for (int i = 0; i < rows * cols; i++)
			flag.push_back(false);
		int num = Count(threshold, rows, cols, 0, 0, flag);
		return num;
	}
	int Count(int threshold, int rows, int cols, int i, int j, vector<bool>& flag)
	{
		int count = 0;
		if (isOK(threshold, rows, cols, i, j, flag))
		{
			flag[i * cols + j] = true;
			count = 1 + Count(threshold, rows, cols, i + 1, j, flag)
				+ Count(threshold, rows, cols, i - 1, j, flag)
				+ Count(threshold, rows, cols, i, j + 1, flag)
				+ Count(threshold, rows, cols, i, j - 1, flag);
		}
		return count;
	}

	bool isOK(int threshold, int rows, int cols, int i, int j, vector<bool>& flag)
	{
		if (i < rows && i >= 0 && j < cols && j >= 0
			&& flag[i * cols + j] == false
			&& getNum(i) + getNum(j) <= threshold)
			return true;
		return false;
	}
	int getNum(int n)
	{
		int sum = 0;
		while (n > 0)
		{
			sum += n % 10;
			n = n / 10;
		}
		return sum;
	}
};


int main()
{
	Func a;
	Solution b;
	cout << b.movingCount(9, 2, 2) << endl;
	cout << a.movingCount(9, 2, 2) << endl;
	system("pause");
	return 0;
}