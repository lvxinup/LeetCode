#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int begin = 0;
		int end = array.size() - 1;
		while (begin < end)
		{
			while (begin < end && (array[begin] % 2 != 0))    //��ǰ�벿����ż��
			{
				begin++;
			}
			while (begin < end && (array[end] % 2 == 0))    //�ں�벿��������
			{
				end--;
			}
			//��������ҵ��ˣ�������ż������
			if (begin < end)
			{
				int temp = array[begin];
				array[begin] = array[end];
				array[end] = temp;
			}
		}

	}
};