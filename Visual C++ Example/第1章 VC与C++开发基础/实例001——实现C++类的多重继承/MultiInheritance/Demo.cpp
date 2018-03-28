#include<iostream>
using namespace std;
class CTimeType//定义时间类
{
	int hour,minute,second;              							//成员变量
public:
	CTimeType(int h=12,int m=0,int s=0)								//构造函数
	{
		hour=h;
		minute=m;
		second=s;
	}
	void display()												//成员函数，输出时间
	{
		cout<<hour<<":"<<minute<<":"<<second<<endl;
	}
	void SetTime(int h,int m,int s)								//成员函数，设置时间
	{
		hour=h;
		minute=m;
		second=s;
	}
};
class CDateType//日期类
{
	int month,day,year;                							//成员变量
public:
	CDateType(int mon=1,int d=1,int y=2008)							//构造函数
	{
		month=mon;
		day=d;
		year=y;
	}
	void display()											//成员函数，输出日期
	{
		cout<<month<<"/"<<day<<"/"<<year<<endl;
	}
	void SetDate(int mon,int d,int y)								//成员函数，设置日期
	{
		month=mon;
		day=d;
		year=y;
	}
};
class CDateTimeType:public CDateType,public CTimeType//时间日期类
{
public:
	CDateTimeType(int mon=1,int d=1,int y=2000,int h=0,int m=0,int s=0):CDateType(mon,d,y),CTimeType(h,m,s){}								//构造函数
	void display()//成员函数，显示时间、日期
	{
		CDateType::display();						//调用CDateType类的display函数
		CTimeType::display();						//调用CTimeType类的display函数
	}
}; 

int main()
{
	cout<<"类的多重继承演示"<<endl;
	CDateTimeType dt(1,1,2008,11,12,12);		//直接使用DateTimeType构造函数设置日期时间
	cout<<"调用CDateTimeType类构造函数设定的初始日期、时间为："<<endl;
	dt.display();//显示时间日期
	dt.SetDate(8,8,2008);						//调用基类的成员函数修改日期
	dt.SetTime(20,8,8);						//调用基类的成员函数修改时间
	cout<<"调用基类成员函数修改后的日期、时间为："<<endl;
	dt.display();
	return 0;
}
