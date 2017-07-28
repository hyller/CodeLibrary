// calculate.cpp: implementation of the calculate class.
//
//////////////////////////////////////////////////////////////////////

#include "calculate.h"
float floatcalculate(float x,float y, int type)
{
	switch (type)
	{
	case 0:											//加法运算
		{return x+y;}
	case 1:											//减法运算
		{return x-y;}
	case 2:											//乘法运算
		{return x*y;}
	case 3:											//除法运算
		{return x/y;}			
	}
}

