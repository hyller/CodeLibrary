// AreaVolumnClass.cpp: implementation of the AreaVolumnClass class.
//
//////////////////////////////////////////////////////////////////////

#include "AreaVolumnClass.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AreaVolumnClass::AreaVolumnClass()
{
	height=lenth=width=0.0;//初始化
}

AreaVolumnClass::~AreaVolumnClass()
{

}
double AreaVolumnClass::GetArea()										//计算表面积
{
	return 2*(height*lenth+height*width+width*lenth);
}
double AreaVolumnClass::GetVolumn()									//计算体积
{
	return height*lenth*width;
}
void AreaVolumnClass::SetLenth(double a)								//设置长
{
	lenth=a;
}
void AreaVolumnClass::SetHeight(double c)								//设置高
{
	height=c;
}
void AreaVolumnClass::SetWidth(double b)								//设置宽
{
	width=b;
}
