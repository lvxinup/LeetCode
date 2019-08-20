#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

class Person
{
public:
	string _name; // 姓名
};
class Student : virtual public Person
{
protected: 
	int _num; //学号
};
class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : virtual public Student, virtual public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
void Test()
{
	// 这样会有二义性无法明确知道访问的是哪一个
	Assistant a;
	cout << sizeof(a) << endl;
	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	//a.Student::_name = "xxx";
	//a.Teacher::_name = "yyy";
}


int main()
{
	Test();

	system("pause");
	return 0;
}