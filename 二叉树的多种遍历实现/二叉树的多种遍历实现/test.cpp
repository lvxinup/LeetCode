#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<queue>
#include<Windows.h>
using namespace std;

//二叉树节点结构
struct TreeNode
{
	int val;
	TreeNode* left;	//左子树
	TreeNode* right;	//右子树
	TreeNode(int x) :val(x), left(nullptr), right(nullptr)
	{}
};

//二叉树的创建
void CreateTree(TreeNode* &root)
{
	int val;
	//按先序次序输入二叉树中节点的值，'-1'表示空树
	cin >> val;
	//空节点
	if (val == -1)
	{
		root = nullptr;
		return;
	}
	root = new TreeNode(val);
	//构造左子树
	CreateTree(root->left);
	//构造右子树
	CreateTree(root->right);
}

//层序建立二叉树	15 11 20 8 14 -1 -1 -1 -1 13 -1
TreeNode* CreateTreeLevel(vector<int> num)
{
	int len = num.size();
	if (len == 0)
	{
		return NULL;
	}
	queue<TreeNode*> queue;
	int index = 0;
	//创建根节点
	TreeNode* root = new TreeNode(num[index++]);
	//入队列
	queue.push(root);
	TreeNode* p = NULL;
	while (!queue.empty() && index < len)
	{
		//根节点出队列
		p = queue.front();
		queue.pop();
		
		//左节点入队列
		if (index < len && num[index] != -1)
		{
			//如果不空，创建一个节点
			TreeNode* leftNode = new TreeNode(num[index]);
			p->left = leftNode;
			queue.push(leftNode);
		}
		index++;

		//右节点入队列
		if (index < len && num[index] != -1)
		{
			//如果不空，创建一个节点
			TreeNode* rightNode = new TreeNode(num[index]);
			p->right = rightNode;
			queue.push(rightNode);
		}
		index++;
	}
	return root;
}

//先序遍历  非递归
//【思路】：访问T->data后，将T入栈，遍历左子树；遍历完左子树返回时，栈顶元素应为T，出栈，再先序遍历T的右子树。
void PrevOrder(TreeNode* root,vector<int>& result)
{
	if (root == nullptr)
		return;
	stack<TreeNode*> s;
	s.push(root);
	TreeNode *p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		result.push_back(p->val);
		//右节点不为空，压入栈中
		//因为栈的先进后出特性，所以要先入压右节点在压入左节点，保证栈顶先为左节点、再为右节点。
		if (p->right)
		{
			s.push(p->right);
		}
		//左节点不为空，压入栈中
		if (p->left)
		{
			s.push(p->left);
		}
	}
}

//先序遍历，递归法
void PrevOrderR(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
		return;
	//先根节点
	result.push_back(root->val);
	//再左节点
	PrevOrderR(root->left,result);
	//最后右节点
	PrevOrderR(root->right,result);
}

//中序遍历，非递归法
//【思路】：T是要遍历树的根指针，中序遍历要求在遍历完左子树后，访问根，再遍历右子树。	
void InOrder(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
		return;
	stack<TreeNode*> s;
	//p是遍历指针
	TreeNode* p = root;
	while (p != nullptr || !s.empty())
	{
		//节点不为空时，继续向左访问
		if (p != nullptr)
		{	
			//存入栈中
			s.push(p);
			//访问左子树
			p = p->left;
		}
		else	//节点为空时，退栈，先访问根节点，再向右访问。
		{
			//退栈，访问根节点
			p = s.top();
			s.pop();
			result.push_back(p->val);
			//访问右子树
			p = p->right;
		}
	}
}

//中序遍历	递归法
void InOrderR(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
	{
		return;
	}
	//左子树
	InOrderR(root->left, result);
	//根节点
	result.push_back(root->val);
	//右子树
	InOrderR(root->right, result);
}

//后序遍历	非递归法
//【思路】：T是要遍历树的根指针，后序遍历要求在遍历完左右子树后，再访问根。需要判断根结点的左右子树是否均遍历过。
void PostOrder(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
		return;
	stack<TreeNode*> s;
	s.push(root);
	TreeNode* p;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		result.insert(result.begin(),p->val);
		if (p->left)
			s.push(p->left);
		if (p->right)
			s.push(p->right);
	}
}

//后序遍历  递归法
void PostOrderR(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
		return;
	PostOrderR(root->left,result);
	PostOrderR(root->right,result);
	result.push_back(root->val);
}

//层序遍历	非递归法
void LevelOrder(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
		return;
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* p;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		result.push_back(p->val);
		if (p->left)
			q.push(p->left);
		if (p->right)
			q.push(p->right);
	}
}

//层序遍历	递归法
void LevelOrderR(TreeNode* root,vector<int>& tmp,int i)
{
	if (root->left)
		LevelOrderR(root->left, tmp, 2*i);
	if (root->right)
		LevelOrderR(root->right, tmp, 2*i+1);
	tmp[i] = root->val;
}

// 输出结果
void Print(vector<int> result){
	int size = result.size();
	for (int i = 0; i < size; ++i){
		cout << result[i] << " ";
	}//for
	cout << endl;
}
//层序遍历的输出函数
void PrintLevel(vector<int> result)
{
	int size = result.size();
	for (int i = 1; i < size; ++i){
		if (result[i] != 0)
			cout << result[i] << " ";
	}//for
	cout << endl;
}

int main(){
	TreeNode* root = nullptr;
	vector<int> input = { 15, 11, 20 ,8 ,14 ,-1 ,-1 ,-1 ,-1 ,13 ,-1 };
	vector<int> result;
	vector<int> tmp = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i = 1;
	// 创建二叉树
	cout << "1. 层序创建二叉树" << endl;
	root = CreateTreeLevel(input);
	cout << "-----------------------------" << endl;

	cout << "2.1 递归先序遍历" << endl;
	PrevOrderR(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "2.2 非递归先序遍历" << endl;
	PrevOrder(root,result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "3.1 递归中序遍历" << endl;
	InOrderR(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "3.2 非递归中序遍历" << endl;
	InOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "4.1 递归后序遍历" << endl;
	PostOrderR(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "4.2 非递归后序遍历" << endl;
	PostOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "5.1 递归层次遍历" << endl;
	LevelOrderR(root, tmp,i);
	PrintLevel(tmp);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "5.2 非递归层次遍历" << endl;
	LevelOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;


	system("pause");
	return 0;
}
