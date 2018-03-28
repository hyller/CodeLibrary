#include <iostream>
#include <iomanip>
using namespace std;
void main()
{
	char bookname[100];double price;int counts;
	cout << "请输入书名:"<< endl;
	cin>>bookname;
	cout << "请输入单价:"<< endl;
	cin>>price;
	cout << "请输入销售数量:"<< endl;
	cin>>counts;
	cout<<"使用状态标志和成员函数进行格式化输出"<<endl;
	cout<<"《"<<bookname<<"》：";
	cout.width(5);        								//单价显示宽度为5个字符
	cout.fill('*');          								//宽度不满用*字符填充
	cout<<price<<"(单价)  ";  									//按照上面的格式设置输出
	cout.setf(ios::scientific);   								//用科学记数法输出销售额
	cout.precision(3);   									//保留3位精度
	cout<<price*counts<<"(销售额)  ";  
	//显示销售数量，带有正负号、左对齐
	cout.setf(ios::showpos|ios::left);
	cout<<counts<<"(销售数量)"<<endl;


/*cout<<"使用流操作符进行格式输出"<<endl;
	cout<<"《"<<bookname<<"》："
	<<setw(5)<<setfill('*')<<price<<"(单价)  " 
	<<scientific<<setprecision(3)<<price*counts<<"(销售额)  "
	<<showpos<<left<<counts<<"(销售数量)"<<endl;*/
}
