#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		/*size_t i = 0;//行
		size_t j = 0;//列
		if (array.empty())return false;
		for(i=0;i<array.size();i++)
		{
		if (array[i].empty())
		return false;
		else if(target >= array[i][0])
		{
		if(target <= array[i][array[i].size()-1])
		{
		for(j = array[i].size() - 1; j >= 0; j--)
		{
		if(target == array[i][j])
		return true;
		else if (target > array[i][j])
		break;
		}
		}
		else
		continue;
		}
		else
		return false;
		}

		return false;*/
		bool flag = false;
		int row = 0;	//行
		int col = array[0].size() - 1;	//列
		while (col >= 0 && row < array.size())
		{
			if (target == array[row][col])
			{
				flag = true;
				break;
			}
			else if (target > array[row][col])
			{
				row++;
			}
			else
			{
				col--;
			}
		}
		return flag;
	}
};