#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		//int begin=0;    //找偶数
		//int end=0;    
		int size = array.size();
		int temp = 0;
		for (int i = 0; i<size; i++)
		{
			if (array[i] % 2 == 0)    //找到偶数
			{
				for (int j = i; j<size; j++)
				{
					if (array[j] % 2 == 1)    //找到奇数
					{
						int temp = array[j];
						while (j>i)
						{
							array[j] = array[j - 1];
							j--;
						}
						array[j] = temp;
						i++;
					}
				}
				break;
			}

		}
	}

};

