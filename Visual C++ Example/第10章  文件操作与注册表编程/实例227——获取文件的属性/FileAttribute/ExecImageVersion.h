/*
 Written by Steve Bryndin (fishbed@tezcat.com, steveb@gvsi.com).

 This code may be used in compiled form in any way you wish. This
 file may be redistributed unmodified by any means PROVIDING it is 
 not sold for profit without the authors written consent, and 
 providing that this notice and the authors name is included. 
 An email letting me know that you are using it would be 
 nice as well. 

 This software is provided "as is" without express or implied warranty. 
 Use it at you own risk! The author accepts no liability for any damages 
 to your computer or data these products may cause.
*/


// ExecImageVersion.h: interface for the CExecImageVersion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXECIMAGEVERSION_H__75CAB01F_DD4B_11D2_84FE_00801E035520__INCLUDED_)
#define AFX_EXECIMAGEVERSION_H__75CAB01F_DD4B_11D2_84FE_00801E035520__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma comment (lib, "version.lib")

class CExecImageVersion  
{
public:
	CString GetSpecialBuild();
	CString GetPrivateBuild();
	CString GetLegalTrademarks();
	CString GetInternalName();
	CString GetFileVersion();
	CString GetFileDescription();
	CString GetComments();
	CString GetCopyright();
	CString GetCompanyName();
	CString GetProductVersion();
	CString GetProductName();
	CExecImageVersion();
	CExecImageVersion(LPTSTR lpszImageName);
	virtual ~CExecImageVersion();

private:
	void InitVer();
	LPTSTR m_lpszImageName;
	CString m_strImage;
	DWORD	m_dwHandle;
	DWORD	m_dwSize;
	LPVOID	m_lpBuffer;
	LPVOID	m_lpData;
	UINT	m_uiDataSize;
};

#endif // !defined(AFX_EXECIMAGEVERSION_H__75CAB01F_DD4B_11D2_84FE_00801E035520__INCLUDED_)
