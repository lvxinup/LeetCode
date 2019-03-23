#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<Windows.h>
#include<string.h>

using namespace std;

// 1.�ִ�д�� 
// 2.��ͳд�� 
// 3.�ַ�����ɾ��� 

class String
{
public:
	String(const char* str = "")//ȱʡ���캯��
		:_str(new char[strlen(str) + 1])//������ȿ���С��ͬ�Ŀռ�
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

	// String s2(s1) ��������
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	// s1 = s2 ���������
	String& operator=(String s)
	{
		if (this != &s)
		{
			String tmp(s._str);
			strcpy(_str, tmp._str);
		}
	}
	size_t Size()	//�����ַ�������
	{
		return strlen(_str);
	}
	char& operator[](size_t pos)	//operator[]����������һ���ķ���Ԫ�� 
	{
		assert(pos < Size());
		return _str[pos];	//���������򻹴��ڣ���&����
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
			char *tmp = new char[n + 1];//�洢'\0';
			strcpy(tmp, _str);//ԭ���ݿ������¿��Ŀռ���ȥ
			delete[]_str;
			_str = tmp;
			_capacity = n;//capacity������\0
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
		Insert(_size, ch);//ֱ���ò��������һ��λ�ò���
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
		{	//��Ҫ����
			Expand(_capacity * 2);
		}
		int end = _size;
		while (end >= (int)pos)//��int��pos����������������pos=0,end����С��0��������ѭ��
		{	//������λ�ú�����ݶ�����
			_str[end + 1] = _str[end];
			end--;
		}
		_str[pos] = ch;
		_size++;
	}
	void Insert(size_t pos, const char* str)
	{
		assert(pos < _size);//pos���ڻ����_sizeʱ�����ַ�������ƴ���ַ�����
		int len = strlen(str);
		if (_size + len>_capacity)//��Ҫ����
		{
			Expand(_size + len);
		}
		int end = _size;
		while (end >= (int)pos)
		{	//����λ��֮�����е����������ƶ�len�ĵ�λ����
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
		{	//pos����n��λ�õ������ƶ���posλ�ã����θ���֮ǰ�����ݣ��ﵽɾ��������
			_str[cur] = _str[cur + n];
			cur++;
		}
		_str[cur] = '\0';
		_size -= n;
	}


	int Find(char ch)//�����ַ����ֵ�λ��
	{
		for (size_t i = 0; i <= _size; i++)
		{
			if (ch == _str[i])
				return i;
		}
		return -1;
	}
	int Find(const char* str)//�����ַ������ֵ�λ��
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
		return -1;//û���ҵ�
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
			if (*str2)//��ʱ *stΪ'\0'
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