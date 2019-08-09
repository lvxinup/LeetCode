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
		//vector的迭代器是一个原生指针
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

		// 这里如果使用Iterator做迭代器，就会导致初始化的迭代器区间[first,last]只能是Vector的迭代器
		// 这里重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器区间。
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
			//1.n小于当前size
			if (n <= Size()){
				_finish = _start + n;
				return;
			}

			//2.空间不够则扩容
			if (n > Size()){
				Reserve(n);
			}

			//3.将size扩大到n
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
			
			//空间不够先增容
			if (_finish == _endOfStorage){
				size_t size = Size();
				size_t newcapacity = Capacity() == 0 ? 1 : Capacity() * 2;

				Reserve(newcapacity);
				//增容之后，pos位置改变
				pos = _start + size;
			}

			//插入位置之后的元素后移一位
			Iterator end = _finish - 1;
			while (end >= pos){
				*(end + 1) = *end;
				--end;
			}
			//插入元素
			*pos = x;
			++_finish;
			return pos;
		}

		//erase返回删除数据的下一个位置
		//方便解决：一边遍历一边删除的迭代器失效的问题
		Iterator Erase(Iterator pos)
		{
			//挪动数据进行删除
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
		Iterator _start;	//指向数据块的开始
		Iterator _finish;	//指向数据块的末尾
		Iterator _endOfStorage;	//指向存储容量的尾
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
	// 测试T是string时，拷贝问题
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

//vector iterator的使用
void PrintVector(const myvector::Vector<int>& v)
{
	// 使用const迭代器进行遍历打印
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
	// 使用push_back插入4个数据
	myvector::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	// 使用迭代器进行遍历打印
	myvector::Vector<int>::Iterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// 使用迭代器进行修改
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
	// 使用find查找3所在位置的iterator
	myvector::Vector<int>::Iterator pos = find(v.Begin(), v.End(), 3);
	// 在pos位置之前插入30
	v.Insert(pos, 30);
	myvector::Vector<int>::Iterator it = v.Begin();
	while (it != v.End()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.Begin(), v.End(), 3);
	// 删除pos位置的数据
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
	// 通过[]读写第0个位置。
	v[0] = 10;
	cout << v[0] << endl;
	// 通过[i]的方式遍历vector
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
// iterator失效问题
void TestVector7()
{
	int a[] = { 1, 2, 3, 4 };
	myvector::Vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	myvector::Vector<int>::Iterator pos = find(v.Begin(), v.End(), 3);
	// 删除pos位置的数据，导致pos迭代器失效。
	v.Erase(pos);
	cout << *pos << endl; // 此处会导致非法访问
	// 在pos位置插入数据，导致pos迭代器失效。
	// insert会导致迭代器失效，是因为insert可
	// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
	pos = find(v.Begin(), v.End(), 3);
	v.Insert(pos, 30);
	cout << *pos << endl; // 此处会导致非法访问
	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
	// 对失效的迭代器进行++it，会导致程序崩溃
	myvector::Vector<int>::Iterator it = v.Begin();
	//while (it != v.End())
	//{
	//	if (*it % 2 == 0)
	//		v.Erase(it);
	//	++it;
	//}
	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置
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
