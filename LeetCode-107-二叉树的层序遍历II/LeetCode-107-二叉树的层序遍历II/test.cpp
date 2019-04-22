#define  _CRT_SECURE_NO_WARNINGS 1

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		queue<TreeNode*> queue;
		vector<vector<int>> v;
		stack<vector<int>> s;
		TreeNode* p = root;
		if (root == nullptr)
			return v;
		queue.push(p);
		while (!queue.empty())   //��û�нڵ�������ʱ������ѭ��
		{
			int count = queue.size();
			vector<int> tmp;
			while (count != 0)
			{
				//���ڵ������
				p = queue.front();
				queue.pop();
				tmp.push_back(p->val);

				//��ڵ������
				if (p->left != nullptr)
				{
					queue.push(p->left);
				}
				//�ҽ�������
				if (p->right != nullptr)
				{
					queue.push(p->right);
				}
				--count;
			}
			s.push(tmp);
		}
		while (!s.empty())
		{
			v.push_back(s.top());
			s.pop();
		}
		return v;
	}
};