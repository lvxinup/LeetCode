#define  _CRT_SECURE_NO_WARNINGS 1

class Solution{
public:
	void reOrderArray(vector<int> &array) {

		vector<int> array_temp;
		vector<int>::iterator ib1, ie1;
		ib1 = array.begin();


		for (; ib1 != array.end();){            //����ż�����ͱ��浽�����飬ͬʱ��ԭ������ɾ��
			if (*ib1 % 2 == 0) {
				array_temp.push_back(*ib1);
				ib1 = array.erase(ib1);
			}
			else{
				ib1++;
			}

		}
		vector<int>::iterator ib2, ie2;
		ib2 = array_temp.begin();
		ie2 = array_temp.end();

		for (; ib2 != ie2; ib2++)             //�������������ӵ�������
		{
			array.push_back(*ib2);
		}
	}
};
