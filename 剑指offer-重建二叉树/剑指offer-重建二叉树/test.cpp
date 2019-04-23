#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())
			return NULL;
		size_t index = 0;
		//找到根节点的位置
		for (index = 0; index<pre.size(); index++)
		{
			if (pre[0] == vin[index])
				break;
		}

		//创建根节点
		TreeNode* root = new TreeNode(pre[0]);
		vector<int> left_pre, left_vin;//左子树的前序遍历和中序遍历
		vector<int> right_pre, right_vin;//右子树的前序遍历和中序遍历
		for (size_t i = 0; i<index; i++)
		{
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}
		for (size_t j = index + 1; j<pre.size(); j++)
		{
			right_pre.push_back(pre[j]);
			right_vin.push_back(vin[j]);
		}
		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);
		return root;
	}
};

int main()
{
	Solution s;
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	s.reConstructBinaryTree(pre, vin);

	return 0;
}