#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;


//������ʱ�临�ӶȽϸ�
//class Solution {
//public:
//	int maxArea(vector<int>& height) {
//		int final_max = 0;
//		if (height.empty())
//			return 0;
//		for (int i = 0; i<height.size(); i++){
//			int max = 0;
//			for (int j = i+1; j<height.size(); j++){
//				max = ((j - i)*min(height[i], height[j]))>max ? ((j - i)*min(height[i], height[j])) : max;
//			}
//			final_max = max>final_max ? max : final_max;
//		}
//		return final_max;
//	}
//};


//˫ָ�뷨
class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxarea = 0;
		int i = 0, j = height.size() - 1;
		//˫ָ�뷨
		while (i<j){
			maxarea = max(maxarea, min(height[i], height[j])*(j - i));
			if (height[i]>height[j])
				j--;
			else
				i++;
		}
		return maxarea;
	}
};

int main()
{
	Solution s;
	vector<int> tmp{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	s.maxArea(tmp);
	system("pause");
	return 0;
}
