#define  _CRT_SECURE_NO_WARNINGS 1

//˼·�������������ӽڵ��븸�ڵ�֮��Ĺ�ϵΪroot = child / 2
//���������ϵ�����a ��= b���������еĽϴ�������2�� ���ѭ��֪��a == b��
//����ԭ���������������������
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