#define  _CRT_SECURE_NO_WARNINGS 1

//思路：满二叉树的子节点与父节点之间的关系为root = child / 2
//利用这个关系，如果a ！= b，就让其中的较大数除以2， 如此循环知道a == b，
//即是原来两个数的最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a>b)
				a = a / 2;
			else
				b = b / 2;
		}
		return b;
	}
};