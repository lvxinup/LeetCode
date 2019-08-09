#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<assert.h>
#include<Windows.h>
#include<string>

using namespace std;

namespace myvector
{
	template<class T>
	class Vector
	{
	public:
		//vector�ĵ�������һ��ԭ��ָ��
		typedef T* Iterator;
		typedef const T* ConstIterator;

		Iterator Begin() { return this->_start; }
		Iterator End() { return this->_finish; }

		ConstIterator CBegin() const{ return this->_start; }
		ConstIterator CEnd() const { return this->_finish; }

		size_t Size() const{ return this->_finish - this->_start; }
		size_t Capacity() const { return this->_endOfStorage - this->_start; }

		Vector()
			:_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{}

		Vector(int n, const T& value = T())
			:_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--){
				PushBack(value);
			}
		}

		// �������ʹ��Iterator�����������ͻᵼ�³�ʼ���ĵ���������[first,last]ֻ����Vector�ĵ�����
		// ������������������������������[first,last]���������������ĵ��������䡣
		template<class InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			Reserve(last - first);
			while (first != last){
				PushBack(*first);
				first++;
			}
		}

		Vector(const T& v)
			:_start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr)
		{
			Reserve(v.Capacity());

			Iterator it = Begin();
			Iterator cit = CBegin();
			while (it != v.CEnd()){
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}

		Vector<T>& operator=(Vector<T> v)
		{
			Swap(v);
			return *this;
		}

		~Vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		void Reserve(size_t n)
		{
			if (n > Capacity()){
				size_t size = Size();
				T* tmp = new T[n];

				if (_start){
					for (int i = 0; i < size; i++){
						tmp[i] = _start[i];
					}
				}

				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}


		void Resize(size_t n, const T& value = T())
		{
			//1.nС�ڵ�ǰsize
			if (n <= Size()){
				_finish = _start + n;
				return;
			}

			//2.�ռ䲻��������
			if (n > Size()){
				Reserve(n);
			}

			//3.��size����n
			Iterator it = _finish;
			Iterator _finish = _start + n;
			while (it != _finish){
				*it = value;
				++it;
			}
		}

		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		void PushBack(const T& x)
		{
			Insert(End(), x);
		}

		void PopBack()
		{
			Erase(--End());
		}


		Iterator Insert(Iterator pos, const T& x)
		{
			assert(pos <= _finish);
			
			//�ռ䲻��������
			if (_finish == _endOfStorage){
				size_t size = Size();
				size_t newcapacity = Capacity() == 0 ? 1 : Capacity() * 2;

				Reserve(newcapacity);
				//����֮��posλ�øı�
				pos = _start + size;
			}

			//����λ��֮���Ԫ�غ���һλ
			Iterator end = _finish - 1;
			while (end >= pos){
				*(end + 1) = *end;
				--end;
			}
			//����Ԫ��
			*pos = x;
			++_finish;
			return pos;
		}

		//erase����ɾ�����ݵ���һ��λ��
		//��������һ�߱���һ��ɾ���ĵ�����ʧЧ������
		Iterator Erase(Iterator pos)
		{
			//Ų�����ݽ���ɾ��
			Iterator begin = pos + 1;
			while (begin != _finish){
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;

			return pos;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

	private:
		Iterator _start;	//ָ�����ݿ�Ŀ�ʼ
		Iterator _finish;	//ָ�����ݿ��ĩβ
		Iterator _endOfStorage;	//ָ��洢������β
	};

}

// constructing vectors
void TestVector1()
{
	// constructors used in the same order as described above:
	myvector::Vector<int> first; // empty vector of ints
	myvector::Vector<int> second(4, 100); // four ints with value 100
	myvector::Vector<int> third(second.Begin(), second.End()); // iterating through second
	myvector::Vector<int> fourth(third); // a copy of third
	// the iterator constructor can also be used to construct from arrays:
	int myints[] = { 16, 2, 77, 29 };
	myvector::Vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << "The contents of fifth are:";
	for (myvector::Vector<int>::Iterator it = fifth.Begin(); it != fifth.End(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	// ����T��stringʱ����������
	myvector::Vector<string> strV;
	strV.PushBack("1111");
	strV.PushBack("2222");
	strV.PushBack("3333");
	strV.PushBack("4444");
	for (size_t i = 0; i < strV.Size(); ++i)
	{
		cout << strV[i] << " ";
	}
	cout << endl;
}

//vector iterator��ʹ��
void PrintVector(const myvector::Vector<int>& v)
{
	// ʹ��const���������б�����ӡ
	myvector::Vector<int>::ConstIterator it = v.CBegin();
	while (it != v.CEnd())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestVector2()
{
	// ʹ��push_back����4������
	myvector::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	// ʹ�õ��������б�����ӡ
	myvector::Vector<int>::Iterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// ʹ�õ����������޸�
	it = v.Begin();
	while (it != v.End())
	{
		*it *= 2;
		++it;
	}
	PrintVector(v);
}

// capacity/vector::reserve/resize
void TestVector4()
{
	size_t sz;
	myvector::Vector<int> foo;
	sz = foo.Capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.PushBack(i);
		if (sz != foo.Capacity()) {
			sz = foo.Capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	// resverse
	myvector::Vector<int> bar;
	sz = bar.Capacity();
	bar.Reserve(100); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i) {
		bar.PushBack(i);
		if (sz != bar.Capacity()) {
			sz = bar.Capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	// resize
	myvector::Vector<int> myvector;
	// set some initial content:
	for (int i = 1; i < 10; i++)
	myvector.PushBack(i);
	myvector.Resize(5);
	myvector.Resize(8, 100);
	myvector.Resize(12);
	std::cout << "myvector contains:";
	for (size_t i = 0; i < myvector.Size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}
// find / insert / erase
void TestVector5()
{
	int a[] = { 1, 2, 3, 4 };
	myvector::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʹ��find����3����λ�õ�iterator
	myvector::Vector<int>::Iterator pos = find(v.Begin(), v.End(), 3);
	// ��posλ��֮ǰ����30
	v.Insert(pos, 30);
	myvector::Vector<int>::Iterator it = v.Begin();
	while (it != v.End()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.Begin(), v.End(), 3);
	// ɾ��posλ�õ�����
	v.Erase(pos);
	it = v.Begin();
	while (it != v.End()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
// operator[]
void TestVector6()
{
	int a[] = { 1, 2, 3, 4 };
	myvector::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ͨ��[]��д��0��λ�á�
	v[0] = 10;
	cout << v[0] << endl;
	// ͨ��[i]�ķ�ʽ����vector
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	myvector::Vector<int> swapv;
	swapv.Swap(v);
	cout << "v data:";
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "swapv data:";
	for (size_t i = 0; i < swapv.Size(); ++i)
	{
		cout << swapv[i] << " ";
	}
	cout << endl;
}
// iteratorʧЧ����
void TestVector7()
{
	int a[] = { 1, 2, 3, 4 };
	myvector::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʹ��find����3����λ�õ�iterator
	myvector::Vector<int>::Iterator pos = find(v.Begin(), v.End(), 3);
	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	v.Erase(pos);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
	// ��posλ�ò������ݣ�����pos������ʧЧ��
	// insert�ᵼ�µ�����ʧЧ������Ϊinsert��
	// �ܻᵼ�����ݣ����ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ�
	pos = find(v.Begin(), v.End(), 3);
	v.Insert(pos, 30);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
	// ʵ��ɾ��v�е�����ż��
	// ����ĳ����������������ż����erase����itʧЧ
	// ��ʧЧ�ĵ���������++it���ᵼ�³������
	myvector::Vector<int>::Iterator it = v.Begin();
	//while (it != v.End())
	//{
	//	if (*it % 2 == 0)
	//		v.Erase(it);
	//	++it;
	//}
	// ���ϳ���Ҫ�ĳ�����������erase�᷵��ɾ��λ�õ���һ��λ��
	it = v.Begin();
	while (it != v.End())
	{
		if (*it % 2 == 0)
			it = v.Erase(it);
		else
			++it;
	}
}

int main()
{
	//TestVector1();
	TestVector2();
	//TestVector3();
	TestVector4();
	TestVector5();
	TestVector6();
	TestVector7();

	system("pause");
	return 0;
}
