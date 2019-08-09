#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;


class Date
{
public:
	//构造函数
	Date(int year = 1900, int month = 1, int day = 1){
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	//拷贝构造
	Date(const Date& d){
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}

	//赋值运算符重载
	Date& operator=(const Date& d){
		if (this != &d){
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}

	//+运算符重载
	Date operator+(int days){
		Date tmp(*this);
		tmp._day += days;
		while (tmp._day > GetMonthDay(tmp._year, tmp._day)){
			tmp._day -= GetMonthDay(tmp._year, tmp._day);
			if (tmp._month == 12){
				tmp._year++;
				tmp._month = 1;
			}
			else{
				tmp._month++;
			}
		}
		return tmp;
	}

	//-运算符重载
	Date operator-(int days){
		Date tmp(*this);
		if (days < 0){
			return tmp + (-days);
		}
		tmp._day -= days;
		while (tmp._day < 1){
			if (tmp._month == 1){
				tmp._year--;
				tmp._month = 12;
			}
			else{
				tmp._month--;
			}
			tmp._day += GetMonthDay(tmp._year, tmp._month);
		}
		return tmp;
	}

	//两个日期相减
	int operator-(const Date& d){
		Date Min(d);
		Date Max(*this);
		int flag = 1;
		if (*this < d){
			Max = d;
			Min = *this;
			flag = -1;
		}
		int day = 0;
		while (Max != Min){
			++Min;
			++day;
		}
		return day*flag;
	}

	//++运算符重载,前置++
	Date& operator++(){
		this->_day += 1;
		while (this->_day > GetMonthDay(this->_year, this->_month)){
			this->_day -= GetMonthDay(this->_year, this->_month);
			if (this->_month == 12){
				this->_year++;
				this->_month = 1;
			}
			else{
				this->_month++;
			}
		}
		return *this;
	}

	//后置++，返回创建的
	Date operator++(int){
		Date tmp(*this);
		this->_day += 1;
		while (this->_day > GetMonthDay(this->_year, this->_month)){
			this->_day -= GetMonthDay(this->_year, this->_month);
			if (this->_month == 12){
				this->_year++;
				this->_month = 1;
			}
			else{
				this->_month++;
			}
		}
		return tmp;
	}

	//前置--，--之后返回
	Date& operator--(){
		this->_day--;
		while (this->_day < 1){
			if (this->_month == 1){
				this->_year--;
				this->_month = 12;
			}
			else{
				this->_month--;
			}
			this->_day += GetMonthDay(this->_year, this->_month);
		}
		return *this;
	}
	
	//后置--，返回原来的
	Date operator--(int){
		Date tmp(*this);
		this->_day--;
		while (this->_day < 1){
			if (this->_month == 1){
				this->_year--;
				this->_month = 12;
			}
			else{
				this->_month--;
			}
			this->_day += GetMonthDay(this->_year, this->_month);
		}
		return tmp;
	}

	bool operator>(const Date& d)const{
		return (_year >= d._year) || (_year >= d._year &&_month >= d._month) || _year >= d._year &&_month >= d._month &&_day>d._day;
	}

	bool operator>=(const Date& d)const{
		return (*this > d) || (*this == d);
	}

	bool operator<(const Date& d)const{
		return (_year <= d._year) || (_year <= d._year &&_month <= d._month) || _year <= d._year &&_month <= d._month &&_day<d._day;
	}

	bool operator<=(const Date& d)const{
		return (*this < d) || (*this == d);
	}

	bool operator==(const Date& d)const{
		return (this->_day == d._day && this->_month == d._month && this->_year == d._year);
	}

	bool operator!=(const Date& d)const {
		return !(*this == d);
	}

	//判断闰年
	bool IsLeapYear(int year){
		assert(year >= 1900);
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
			return true;
		}
		return false;
	}

	//获得月的天数
	int GetMonthDay(int year, int month){
		assert(month>0 && month <= 12);
		int day;
		vector<int> monthday = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeapYear(year)){
			monthday[1] = 29;
		}
		return monthday[month - 1];
	}


	//查看日期是否合法
	bool IsInvalid(){
		if (this->_year>1900 && (this->_month >= 1 && this->_month <= 12) && this->_day <= GetMonthDay(this->_year, this->_month)){
			return true;
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2018, 3, 30);
	Date d1(2018, 9, 1);
	Date d4;
	Date m(d);//拷贝函数

	system("pause");
}