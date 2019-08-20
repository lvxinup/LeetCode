#define  _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<string.h>
#include<Windows.h>
#include<iostream>
#include<assert.h>

using namespace std;

namespace mystring
{
	class String{
	public:
		typedef char* Iterator;
	public:
		String(const char* str = ""){
			//构造string类对象时，如果传递nullptr指针，认为程序非法，断言
			if (nullptr == str){
				assert(false);
				return;
			}

			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		String(const String& s)
			:_str(new char[s._capacity+1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}


	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}

int main()
{


	system("pause");
	return 0;
}