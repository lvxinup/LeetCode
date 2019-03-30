#define  _CRT_SECURE_NO_WARNINGS 1

class Solution{
public:
	void reOrderArray(vector<int> &array) {

		vector<int> array_temp;
		vector<int>::iterator ib1, ie1;
		ib1 = array.begin();


		for (; ib1 != array.end();){            //遇见偶数，就保存到新数组，同时从原数组中删除
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

		for (; ib2 != ie2; ib2++)             //将新数组的数添加到老数组
		{
			array.push_back(*ib2);
		}
	}
};
