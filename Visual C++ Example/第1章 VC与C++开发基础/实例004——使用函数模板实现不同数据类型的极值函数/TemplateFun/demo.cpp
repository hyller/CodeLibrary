#include <iostream>
#include <string>
using namespace std;
template <class T>											//定义函数模板
T Min(T a, T b,T c)
{
	if(a<b)													
		b=a;
	return b<c?b:c;											//返回b、c中的小值
}
int main()													//主函数
{	
	cout<<"使用模板函数求不同类型数据的最小值"<<endl<<endl;
	int i1 = 2, i2 = 6, i3 = 4;
	double d1 = 3.4, d2 = 7.2, d3 = 3.39;
	string  str1("one"), str2("two"),str3("three");
	cout << " int类型："<<i1<<", "<<i2<<", "<<i3  <<"    最小值: " << Min(i1, i2, i3) << endl<<endl;					//int型的最大值
	cout << " double类型：" <<d1<<", "<<d2<<", "<<d3 <<"    最小值:" << Min(d1, d2, d3) << endl<<endl;				//double型的最大值
	cout << " string类型：" <<str1<<", "<<str2<<", "<<str3 <<"    最小值:"<< Min(str1, str2, str3) << endl<<endl;			//string型的最大值
	return 0;
}
