// User.cpp: implementation of the CUser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MedicAdmin.h"
#include "User.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUser::CUser()
{

}

CUser::~CUser()
{

}


BOOL CUser::LogIn(CUserSet* theSet)
{
	theSet->m_strFilter="UserAccount='"+m_userAccount+"' and UserPassword='"
		+m_userPassword+"' and UserClassification='"+m_userType+"'";
	theSet->Requery();
	if(theSet->GetRecordCount())
	{
		return TRUE;
	}
	return FALSE;
}

void CUser::SetAllMember(CString account, CString password, CString type, CString name)
{
	m_userAccount=account;
	m_userPassword=password;
	m_userType=type;
	m_userName=name;
}

BOOL CUser::AddNewUser(CUser *newUser, CUserSet *theSet)
{
	theSet->m_strFilter="UserAccount='"+newUser->GetAccount()+"'";
	theSet->Requery();
	if(theSet->GetRecordCount())
	{
		AfxMessageBox("该账号已经存在!");
		return FALSE;
	}
	theSet->AddNew();
	theSet->m_UserAccount=newUser->m_userAccount;
	theSet->m_UserPassword=newUser->m_userPassword;
	theSet->m_UserClassification=newUser->m_userType;
	theSet->m_UserName=newUser->m_userName;
	if(theSet->CanUpdate())
	{
		theSet->Update();
	}
	if(!theSet->IsEOF())
	{
		theSet->MoveLast();
	}
	theSet->Requery();
	return TRUE;
}

void CUser::DeleteUser(CUser* user, CUserSet *userSet)
{
	userSet->m_strFilter = "UserAccount='"+user->m_userAccount+"'";
	userSet->Requery();
	if(!userSet->GetRecordCount())
	{
		AfxMessageBox("您要删除的用户不存在!");
	}
	else
	{
		userSet->Delete();
	}
}

void CUser::SetAccount(CString account)
{
	m_userAccount=account;
}

void CUser::SeekUserInfo(int typeRadio,CString str, CUserSet *theSet)
{
	if(typeRadio==0)
	{
		if(str=="")
		{
			AfxMessageBox("请输入用户类别!");
		}
		else if(str=="所有类型")
		{
			theSet->m_strFilter="";
		}
		else
		{
			theSet->m_strFilter="UserClassification='"+str+"'";
		}
	}
	else if(typeRadio==1)
	{
		if(str=="")
		{
			AfxMessageBox("请输入用户账号!");
		}
		else
		{
			theSet->m_strFilter="UserAccount='"+str+"'";
		}
	}
	theSet->Requery();
}

CString CUser::GetType()
{
	return m_userType;
}

void CUser::SetPassword(CString password)
{
	m_userPassword=password;
}

CString CUser::GetAccount()
{
	return m_userAccount;
}

CString CUser::GetPassword()
{
	return m_userPassword;
}

void CUser::ModifyPassword(CUserSet *theSet)
{
	theSet->Edit();
	theSet->m_UserPassword=m_userPassword;
	if(theSet->CanUpdate())
	{
		theSet->Update();
	}
	//theSet->Requery();
}
