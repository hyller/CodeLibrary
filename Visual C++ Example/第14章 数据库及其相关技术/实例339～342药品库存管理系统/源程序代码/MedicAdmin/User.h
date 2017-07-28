// User.h: interface for the CUser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USER_H__BA485565_5FF5_4E8E_A6EF_21BADF0E3D2F__INCLUDED_)
#define AFX_USER_H__BA485565_5FF5_4E8E_A6EF_21BADF0E3D2F__INCLUDED_

#include "userSet.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUser  
{
public:
	void ModifyPassword(CUserSet* theSet);//修改用户密码，调用CUserSet类的成员变量和成员函数
	CString GetPassword();								//得到用户密码
	CString GetAccount();									//得到用户账号
	void SetPassword(CString password);						//设置用户密码
	CString GetType();									//得到用户类别
	void SeekUserInfo(int typeRadio,CString str,CUserSet* theSet);	//查询用户信息
	void SetAccount(CString account);						//设置用户账号
	void DeleteUser(CUser* user,CUserSet* userSet);				//删除指定用户
	BOOL AddNewUser(CUser* newUser,CUserSet* theSet);		//新增用户
	void SetAllMember(CString account,CString password,CString type,CString name);//初始化用户
	BOOL LogIn(CUserSet*);	//用户登录，将输入的信息与数据库中的信息比较，若一致则允许进入该系统，否则不能进入该系统
	CUser();
	virtual ~CUser();
protected:
	CString m_userAccount;								//用户帐号
	CString m_userPassword;								//用户密码
	CString m_userName;									//用户姓名
	CString m_userType;									//用户类别
};


#endif // !defined(AFX_USER_H__BA485565_5FF5_4E8E_A6EF_21BADF0E3D2F__INCLUDED_)
