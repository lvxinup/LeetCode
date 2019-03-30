#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int begin = 0;
		int end = array.size() - 1;
		while (begin < end)
		{
			while (begin < end && (array[begin] % 2 != 0))    //在前半部分找偶数
			{
				begin++;
			}
			while (begin < end && (array[end] % 2 == 0))    //在后半部分找奇数
			{
				end--;
			}
			//到这里就找到了，奇数和偶数交换
			if (begin < end)
			{
				int temp = array[begin];
				array[begin] = array[end];
				array[end] = temp;
			}
		}

	}
};