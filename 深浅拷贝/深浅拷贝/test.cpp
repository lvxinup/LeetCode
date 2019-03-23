#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<Windows.h>
#include<string.h>

using namespace std;

// 1.现代写法 
// 2.传统写法 
// 3.字符串增删查改 

class String
{
public:
	String(const char* str = "")//缺省构造函数
		:_str(new char[strlen(str) + 1])//深拷贝，先开大小相同的空间
	{
		strcpy(_str, str);
	}
		// s1.Swap(s2); 
		void Swap(String& s)
	{
		String tmp(s._str);
		s._str = _str;
		_str = tmp._str;
	}

	// String s2(s1) 拷贝构造
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	// s1 = s2 运算符重载
	String& operator=(String s)
	{
		if (this != &s)
		{
			String tmp(s._str);
			strcpy(_str, tmp._str);
		}
	}
	size_t Size()	//计算字符串长度
	{
		return strlen(_str);
	}
	char& operator[](size_t pos)	//operator[]可以像数组一样的访问元素 
	{
		assert(pos < Size());
		return _str[pos];	//出了作用域还存在，用&返回
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}

	char* c_str()
	{
		return _str;
	}
	void Expand(size_t n)
	{
		if (n > _capacity)
		{
			char *tmp = new char[n + 1];//存储'\0';
			strcpy(tmp, _str);//原数据拷贝到新开的空间中去
			delete[]_str;
			_str = tmp;
			_capacity = n;//capacity不包括\0
		}
	}
	void PushBack(char ch)
	{
	/*	if (_size==_capacity)
		{
			Expand(_capacity * 2);
		}
		_str[_size] = ch;
		_size++;
		_str[_size + 1] = '\0';*/
		Insert(_size, ch);//直接用插入在最后一个位置插入
	}
	void PushBack(const char* str)
	{
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			Expand(_size + len);
		}
		for (int i = 0; i < len; i++)
		{
			_str[_size++] = str[i];
		}
		_size += len;
	}
	void PopBack()
	{
		_str[_size - 1] = _str[_size];
		_size--;
	}
	void Insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{	//需要增容
			Expand(_capacity * 2);
		}
		int end = _size;
		while (end >= (int)pos)//用int对pos进行类型提升，当pos=0,end不会小于0，陷入死循环
		{	//将插入位置后的数据都后移
			_str[end + 1] = _str[end];
			end--;
		}
		_str[pos] = ch;
		_size++;
	}
	void Insert(size_t pos, const char* str)
	{
		assert(pos < _size);//pos大于或等于_size时是在字符串后面拼接字符串；
		int len = strlen(str);
		if (_size + len>_capacity)//需要扩容
		{
			Expand(_size + len);
		}
		int end = _size;
		while (end >= (int)pos)
		{	//插入位置之后所有的数据往后移动len的单位长度
			_str[end + len] = _str[end];
			end--;
		}
		for (size_t i = 0; i < len; i++)
		{
			_str[pos++] = str[i];
		}
		_size += len;
	}
	void Erase(size_t pos, size_t n = 1)
	{
		assert(pos < _size);
		int cur = pos;
		while (_str[cur + n])
		{	//pos后面n个位置的数据移动到pos位置，依次覆盖之前的数据，达到删除的作用
			_str[cur] = _str[cur + n];
			cur++;
		}
		_str[cur] = '\0';
		_size -= n;
	}


	int Find(char ch)//查找字符出现的位置
	{
		for (size_t i = 0; i <= _size; i++)
		{
			if (ch == _str[i])
				return i;
		}
		return -1;
	}
	int Find(const char* str)//查找字符串出现的位置
	{
		int cur = 0;
		int len = strlen(str);
		while (cur < _size)
		{
			int _strindex = cur;
			int strindex = 0;
			while (strindex < len)
			{
				if (_str[_strindex] == str[strindex])
				{
					_strindex++;
					strindex++;
				}
				else
					break;
			}
			if (strindex == len)
			{
				return cur;
			}
			else
				cur++;
		}
		return -1;//没有找到
	}

	// s1 + 'a' 
	String operator+(char ch)
	{
		Insert(_size, ch);
	}
	String& operator+=(char ch)
	{
		Insert(_size, ch);
		return *this;
	}
	String operator+(const char* str)
	{
		String tmp(*this);
		tmp.PushBack(str);
		return tmp;
	}
	String& operator+=(const char* str)
	{
		PushBack(str);
		return *this;
	}

	bool operator>(const String& s)
	{
		return !(*this <= s);
	}
	bool operator>=(const String& s)
	{
		return !(*this < s);
	}
	bool operator<(const String& s)
	{
		const char *str1 =this-> _str;
		const char *str2 = s._str;
		while (*str1 && *str2)
		{
			if (*str1 < *str2)
				return true;
			else if (*str1 > *str2)
				return false;
			else
			{
				str1++;
				str2++;
			}
			if (*str2)//这时 *st为'\0'
			{
				return true;
			}
			else//*str2='\0'
				return false;
		}
	}
	bool operator<=(const String& s)
	{
		return ((*this < s) || (*this == s));
	}
	bool operator==(const String& s)
	{
		const char *str1 = this->_str;
		const char *str2 = s._str;
		while (*str1 && *str2)
		{
			if (*str1 == *str2)
			{
				str1++;
				str2++;
			}
			else
				return false;
		}
		if (*str1 == '\0' && *str2 == '\0')
			return true;
		else
			return false;
	}
	bool operator!=(const String& s)
	{
		return !(*this == s);
	}

private:
	char *_str;
	size_t _size;
	size_t _capacity;
};

void TestString()
{
	String s1("change world");
	String s2(s1);
	cout << s1.Find('g') << endl;
	cout << s1.Find("world") << endl;
	//	s2.PushBack("I am Coming");
	//cout<
	//	s1 += "I am Coming";
	//cout< s1 += '!';
	//cout<
}
int main()
{
	TestString();
	system("pause");
	return 0;
}