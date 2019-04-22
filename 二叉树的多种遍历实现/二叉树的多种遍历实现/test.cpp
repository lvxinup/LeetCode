#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<queue>
#include<Windows.h>
using namespace std;

//�������ڵ�ṹ
struct TreeNode
{
	int val;
	TreeNode* left;	//������
	TreeNode* right;	//������
	TreeNode(int x) :val(x), left(nullptr), right(nullptr)
	{}
};

//�������Ĵ���
void CreateTree(TreeNode* &root)
{
	int val;
	//�������������������нڵ��ֵ��'-1'��ʾ����
	cin >> val;
	//�սڵ�
	if (val == -1)
	{
		root = nullptr;
		return;
	}
	root = new TreeNode(val);
	//����������
	CreateTree(root->left);
	//����������
	CreateTree(root->right);
}

//������������	15 11 20 8 14 -1 -1 -1 -1 13 -1
TreeNode* CreateTreeLevel(vector<int> num)
{
	int len = num.size();
	if (len == 0)
	{
		return NULL;
	}
	queue<TreeNode*> queue;
	int index = 0;
	//�������ڵ�
	TreeNode* root = new TreeNode(num[index++]);
	//�����
	queue.push(root);
	TreeNode* p = NULL;
	while (!queue.empty() && index < len)
	{
		//���ڵ������
		p = queue.front();
		queue.pop();
		
		//��ڵ������
		if (index < len && num[index] != -1)
		{
			//������գ�����һ���ڵ�
			TreeNode* leftNode = new TreeNode(num[index]);
			p->left = leftNode;
			queue.push(leftNode);
		}
		index++;

		//�ҽڵ������
		if (index < len && num[index] != -1)
		{
			//������գ�����һ���ڵ�
			TreeNode* rightNode = new TreeNode(num[index]);
			p->right = rightNode;
			queue.push(rightNode);
		}
		index++;
	}
	return root;
}

//�������  �ǵݹ�
//��˼·��������T->data�󣬽�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ�����������T����������
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
		//�ҽڵ㲻Ϊ�գ�ѹ��ջ��
		//��Ϊջ���Ƚ�������ԣ�����Ҫ����ѹ�ҽڵ���ѹ����ڵ㣬��֤ջ����Ϊ��ڵ㡢��Ϊ�ҽڵ㡣
		if (p->right)
		{
			s.push(p->right);
		}
		//��ڵ㲻Ϊ�գ�ѹ��ջ��
		if (p->left)
		{
			s.push(p->left);
		}
	}
}

//����������ݹ鷨
void PrevOrderR(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
		return;
	//�ȸ��ڵ�
	result.push_back(root->val);
	//����ڵ�
	PrevOrderR(root->left,result);
	//����ҽڵ�
	PrevOrderR(root->right,result);
}

//����������ǵݹ鷨
//��˼·����T��Ҫ�������ĸ�ָ�룬�������Ҫ���ڱ������������󣬷��ʸ����ٱ�����������	
void InOrder(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
		return;
	stack<TreeNode*> s;
	//p�Ǳ���ָ��
	TreeNode* p = root;
	while (p != nullptr || !s.empty())
	{
		//�ڵ㲻Ϊ��ʱ�������������
		if (p != nullptr)
		{	
			//����ջ��
			s.push(p);
			//����������
			p = p->left;
		}
		else	//�ڵ�Ϊ��ʱ����ջ���ȷ��ʸ��ڵ㣬�����ҷ��ʡ�
		{
			//��ջ�����ʸ��ڵ�
			p = s.top();
			s.pop();
			result.push_back(p->val);
			//����������
			p = p->right;
		}
	}
}

//�������	�ݹ鷨
void InOrderR(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
	{
		return;
	}
	//������
	InOrderR(root->left, result);
	//���ڵ�
	result.push_back(root->val);
	//������
	InOrderR(root->right, result);
}

//�������	�ǵݹ鷨
//��˼·����T��Ҫ�������ĸ�ָ�룬�������Ҫ���ڱ����������������ٷ��ʸ�����Ҫ�жϸ��������������Ƿ����������
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

//�������  �ݹ鷨
void PostOrderR(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
		return;
	PostOrderR(root->left,result);
	PostOrderR(root->right,result);
	result.push_back(root->val);
}

//�������	�ǵݹ鷨
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

//�������	�ݹ鷨
void LevelOrderR(TreeNode* root,vector<int>& tmp,int i)
{
	if (root->left)
		LevelOrderR(root->left, tmp, 2*i);
	if (root->right)
		LevelOrderR(root->right, tmp, 2*i+1);
	tmp[i] = root->val;
}

// ������
void Print(vector<int> result){
	int size = result.size();
	for (int i = 0; i < size; ++i){
		cout << result[i] << " ";
	}//for
	cout << endl;
}
//����������������
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
	// ����������
	cout << "1. ���򴴽�������" << endl;
	root = CreateTreeLevel(input);
	cout << "-----------------------------" << endl;

	cout << "2.1 �ݹ��������" << endl;
	PrevOrderR(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "2.2 �ǵݹ��������" << endl;
	PrevOrder(root,result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "3.1 �ݹ��������" << endl;
	InOrderR(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "3.2 �ǵݹ��������" << endl;
	InOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "4.1 �ݹ�������" << endl;
	PostOrderR(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "4.2 �ǵݹ�������" << endl;
	PostOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "5.1 �ݹ��α���" << endl;
	LevelOrderR(root, tmp,i);
	PrintLevel(tmp);
	result.clear();
	cout << "-----------------------------" << endl;

	cout << "5.2 �ǵݹ��α���" << endl;
	LevelOrder(root, result);
	Print(result);
	result.clear();
	cout << "-----------------------------" << endl;


	system("pause");
	return 0;
}
