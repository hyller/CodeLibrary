#include <iostream.h>
class CComplex												//定义复数类
{	
	double m_fReal, m_fImag;//成员变量
public:
	CComplex(double r = 0, double i = 0): m_fReal(r), m_fImag(i){}			//构造函数
	double GetReal(){return m_fReal;}//成员函数，返回复数的实部
	double GetImag(){return m_fImag;}//成员函数，返回复数的虚部
	CComplex operator +(CComplex&);							//重载运算符＋
	CComplex operator +(double);								//重载运算符＋
}; 
CComplex CComplex::operator + (CComplex &c)				//重载运算符＋，实现两个复数的加法
{	
	CComplex temp;
	temp.m_fReal = m_fReal+c.m_fReal;
	temp.m_fImag = m_fImag+c.m_fImag;
	return temp;
}
CComplex CComplex::operator + (double d)				//重载运算符＋，实现复数与实数的加法
{	
	CComplex temp;
	temp.m_fReal = m_fReal+d;
	temp.m_fImag = m_fImag;
	return temp;
}

void main()//主函数
{
	CComplex c1(2.3,5.5),c2(3.6,6.8),c3;//复数类对象
	cout << "使用重载的+运算符实现复数与复数的相加" << endl;
	cout << "C1 = " << c1.GetReal() << "+j" << c1.GetImag() << endl;
	cout << "C2 = " << c2.GetReal() << "+j" << c2.GetImag() << endl;
	c3 = c1+c2;
	cout << "C3 = C1 + C2 =" << c3.GetReal() << "+j" << c3.GetImag() << endl;
	cout << "使用重载的+运算符实现复数与实数的相加" << endl;
	c3 = c3+6.5;
	cout << "C3 + 6.5 = " << c3.GetReal() << "+j" << c3.GetImag() << endl;
}
