#include<iostream>
using namespace std;
class CFigure												//基类-图形类
{
protected:
	double x,y;												//成员变量
public:
	void SetDim(double i,double j=0.0)						//设置图形参数
	{
		x=i;
		y=j;
	}
	virtual void GetShowArea()								//虚函数计算显示面积
	{
		cout<<"无法计算面积\n";
	}
};
class CTriangle:public CFigure									//三角形类
{
public:
	void GetShowArea()												//覆盖虚函数
	{
		cout<<"三角形：底边长："<<x<<" 高："<<y<<" 面积："<<x*0.5*y<<endl;
	}
};
class CRect:public CFigure											//矩形类
{
public:
	void GetShowArea()												//覆盖虚函数
	{
		cout<<"矩形：长： "<<x<<" 宽： "<<y<<" 面积："<<x*y<<endl;
	}
};
class CCircle:public CFigure											//圆形类
{
public:
	void GetShowArea()												//覆盖虚函数
	{
		cout<<"圆形：半径："<<x<<" 面积："<<3.14159*x*x<<endl;
	}
};

int main()
{
	cout<<"使用虚函数实现运行时多态"<<endl;
	CFigure *figure;
	CTriangle triangle;													//三角形类对象
	CRect rect;													//矩形类对象
	CCircle circle;													//圆形类对象
	figure=&triangle;
	figure->SetDim(8.0,5.0);											//设置三角形的参数
	figure->GetShowArea();												//计算显示三角形的面积
	figure=&rect;
	figure->SetDim(10.0,5.0);											//设置矩形的参数
	figure->GetShowArea();												//计算显示矩形的面积
	figure=&circle;
	figure->SetDim(10.0);											//设置圆形的参数
	figure->GetShowArea();												//计算显示圆形的面积
	return 0;
}
