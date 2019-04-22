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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == nullptr)
			return result;
		stack<TreeNode*> s;
		TreeNode* p = root;
		s.push(root);
		while (!s.empty())
		{
			p = s.top();
			s.pop();
			result.insert(result.begin(), p->val);
			if (p->left)
				s.push(p->left);
			if (p->right)
				s.push(p->right);
		}
		return result;
	}
};