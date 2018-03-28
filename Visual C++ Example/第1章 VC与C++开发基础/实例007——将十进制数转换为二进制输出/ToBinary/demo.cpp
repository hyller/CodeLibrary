#include <iostream.h>
void binary(int number) //转换为二进制输出
{
   int remainder;//余数
   if(number <= 1) 
   {
      cout << number;
      return;
   }
   remainder = number%2;//求余数
   binary(number >> 1);    //递归调用
   cout << remainder;
}
void main(void) //主函数
{
   int number;
   cout << "请输入一个正整数: ";
   cin >> number;
   if (number < 0) 
      cout << "输入错误！\n";
   else 
   {
      cout << number << "转换为二进制为: ";
      binary(number);//转换为二进制输出
      cout << endl;
   }
}

