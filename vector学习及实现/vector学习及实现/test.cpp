#define  _CRT_SECURE_NO_WARNINGS 1

//#include<vector>
//#include<iostream>
//#include<Windows.h>
//
//using namespace std;
//
//int main()
//{
//	vector<int> first;
//	vector<int> second(4, 100);
//	vector<int> third(second.begin(), second.end());
//	vector<int> fourth(third);
//
//	//��������ʼ��
//	int myints[] = { 1, 2, 3, 4 };
//	vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
//
//	for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it){
//		cout << ' ' << *it;
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

//#include<vector>
//#include<iostream>
//#include<Windows.h>
//	
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	size_t sz;
//	sz = v.capacity();
//	cout << "making v grow:" << endl;
//	for (int i = 0; i < 100; i++){
//		v.push_back(i);
//		if (sz != v.capacity()){
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << endl;
//		}
//	}
//	
//
//	system("pause");
//	return 0;
//}

//#include<vector>
//#include<iostream>
//#include<Windows.h>
//
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	size_t sz;
//	sz = v.capacity();
//	for (int i = 0; i < 10; i++){
//		v.push_back(i);
//	}
//	v.resize(15, 3);
//	vector<int>::iterator it = v.begin();
//	/*for (auto & e : v){*/
//	for (it = v.begin(); it != v.end();it++){
//		cout << *it << " ";
//	}
//	cout << endl;
//	v.resize(18);
//	for (it = v.begin(); it != v.end(); it++){
//		cout << *it << " ";
//	}
//	cout << endl;
//	v.resize(5);
//	for (it = v.begin(); it != v.end(); it++){
//		cout << *it << " ";
//	}
//	cout << endl;
//	cout << "v capacity is " << v.capacity() << endl;
//
//	v.reserve(30);
//	for (it = v.begin(); it != v.end(); it++){
//		cout << *it << " ";
//	}
//	cout << endl;
//	cout << "v capacity is " << v.capacity() << endl;
//	cout << "v size is " << v.size() << endl;
//	cout << endl;
//
//	system("pause");
//	return 0;
//}


//#include<vector>
//#include<iostream>
//#include<Windows.h>
//
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++){
//		v.push_back(i);
//	}
//	vector<int>::iterator it = v.begin();
//	for (it = v.begin(); it != v.end(); it++){
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	v.pop_back();
//	v.pop_back();
//	for (it = v.begin(); it != v.end(); it++){
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
//	v.insert(pos, 15);
//	for (it = v.begin(); it != v.end(); it++){
//		cout << *it << " ";
//	}
//	cout << endl;
//
//
//	pos = find(v.begin(), v.end(), 5);
//	v.erase(pos);
//	for (it = v.begin(); it != v.end(); it++){
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}




#include<vector>
#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{
	vector<int> v(4,0);
	for (int i = 0; i < 4; i++){
		v[i] = i;
	}
	vector<int>::iterator it = v.begin();
	for (it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//ʹ��find����3����λ�õ�iterator
	//ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	//erase�᷵��ɾ��λ�õ���һ��λ��
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	cout << *pos << endl;	//�˴��ᵼ�·Ƿ����ʡ�


	// ��posλ�ò������ݣ�����pos������ʧЧ��
	// insert�ᵼ�µ�����ʧЧ������Ϊinsert���ܻᵼ�����ݣ�
	//���ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ�
	vector<int>::iterator tmp = find(v.begin(), v.end(), 5);
	v.insert(tmp, 15);
	cout <<*tmp<< endl;

	system("pause");
	return 0;
}
