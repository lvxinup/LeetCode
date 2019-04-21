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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> tmp;
		stack<TreeNode*> cur;
		TreeNode* p = root;
		while (cur.size() || p)
		{
			if (p)
			{
				cur.push(p);
				tmp.push_back(p->val);
				p = p->left;
			}
			else
			{
				TreeNode *t = cur.top();
				cur.pop();
				p = t->right;
			}
		}
		return tmp;
	}
};