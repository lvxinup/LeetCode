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
		while (!queue.empty())   //当没有节点放入队列时，结束循环
		{
			int count = queue.size();
			vector<int> tmp;
			while (count != 0)
			{
				//根节点出队列
				p = queue.front();
				queue.pop();
				tmp.push_back(p->val);

				//左节点入队列
				if (p->left != nullptr)
				{
					queue.push(p->left);
				}
				//右结点入队列
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