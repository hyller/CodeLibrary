// AreaVolumnClass.h: interface for the AreaVolumnClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AREAVOLUMNCLASS_H__753A6037_F26C_4720_9876_7F43A1A19E87__INCLUDED_)
#define AFX_AREAVOLUMNCLASS_H__753A6037_F26C_4720_9876_7F43A1A19E87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class _declspec(dllexport) AreaVolumnClass  //声明导出类
{
public:
	AreaVolumnClass();
	virtual ~AreaVolumnClass();
	double GetArea();										//计算长方体的表面积
	double GetVolumn();										//计算长方体的体积
	void SetLenth(double a);									//设置长方体的长
	void SetWidth(double b);									//设置长方体的宽
	void SetHeight(double c);									//设置长方体的高
private:
	double lenth;											//存储长方体的长
	double width;											//存储长方体的宽
	double height;											//存储长方体的高

};

#endif // !defined(AFX_AREAVOLUMNCLASS_H__753A6037_F26C_4720_9876_7F43A1A19E87__INCLUDED_)
