#define  _CRT_SECURE_NO_WARNINGS 1

class temp
{
public:
	static void reset(){ i = 0; sum = 0; }
	static unsigned int GetSum(){ return sum; }
	temp()
	{
		++i;
		sum += i;
	}
private:
	static int sum;
	static int i;
};

int temp::sum = 0;
int temp::i = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		temp::reset();
		temp* p = new temp[n];
		delete[]p;
		p = NULL;

		return temp::GetSum();
	}
};