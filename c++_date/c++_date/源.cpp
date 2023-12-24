#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date 
{
public:
	int getday(int year, int month)
	{
		int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return 29;
		return months[month];
	}
	//构造函数
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//运算符重载
	bool operator==(const Date& d)const
	{
	  return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;
		if (_year == d._year && _month > d._month)
			return true;
		if (_year == d._year && _month == d._month && _day > d._day)
			return true;
		else
			return false;
	}
	bool operator<(const Date& d)const
	{
		return !(*this >d);
	}
	bool operator>=(const Date& d)const
	{
		return *this > d || *this == d;
	}
	bool operator<=(const Date& d)const
	{
		return *this < d || *this == d;
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
	Date& operator+=(int day)
	{
		if (day < 0)
			return *this -= -day;
		_day += day;
		while (_day > getday(_year, _month))
		{
			_day -= getday(_year, _month);
			_month++;
			if (_month >= 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	Date operator+(int day)//不使用Date&，是因为ret出了作用域便销毁了
	{
		Date ret(*this);
		ret += day;
		return ret;
	}
	Date& operator-=(int day)
	{
		if (day < 0)
			return *this += -day;
		_day -= day;
		while (day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += getday(_year, _month);
		}
		return *this;
	}
	Date operator-(int day)
	{
		Date ret(*this);//==Date ret = *this;
		ret -= day;
		return ret;
	}
	Date& operator++()
	{
		return *this += 1;//前置++
	}
	Date operator++(int)//后置++
	{
		Date tmp(*this);
		*this += 1;
		return tmp ;
	}
	Date& operator--()//前置--
	{
		return *this -=1;
	}
	Date operator--(int)//后置--
	{
		Date tmp(*this);
		*this -= 1;
		return tmp ;
	}
	//日期-日期
	int operator-(const Date& d) const
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		int n = 0;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		while (max != min)
		{
			n++;
			++min;
		}
		return n * flag;
	}
	void Print()const
	{
		cout << _year <<"-"  << _month <<"-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	int year, month, day;
	Date d1(2023, 12, 24);
	Date d2(d1-=5);//Date d2(d1-5)不可以是因为d1-5返回的是一个临时变量，而临时变量具有常性而构造函数
	               //的参数是Date& d，会将权限扩大，加const就可以
	d2.Print();
	Date d3(d1 - 5);
	d3.Print();
	cin >> year>>month>>day;
	Date d4(year, month, day);
	d4.Print();
	cout <<d3-d1<< endl<<d2-d1;
	return 0;

}