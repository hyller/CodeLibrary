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


// ExecImageVersion.cpp: implementation of the CExecImageVersion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ExecImageVersion.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExecImageVersion::CExecImageVersion()
{
	m_strImage = AfxGetAppName();
	m_strImage += ".exe";
	m_lpszImageName = m_strImage.GetBuffer(sizeof(m_strImage));

	InitVer();
}

CExecImageVersion::CExecImageVersion(LPTSTR lpszImageName)
{
	m_lpszImageName = lpszImageName;
	InitVer();
}

CExecImageVersion::~CExecImageVersion()
{
	free(m_lpBuffer);
}
//产品名称
CString CExecImageVersion::GetProductName()
{
	CString	strProduct;
	
	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\ProductName"),
					&m_lpData,
					&m_uiDataSize);
	strProduct.Format("%s", m_lpData);

	return strProduct;
}
//产品版本信息
CString CExecImageVersion::GetProductVersion()
{
	CString	strProductVer;
	
	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\ProductVersion"),
					&m_lpData,
					&m_uiDataSize);
	strProductVer.Format("%s", m_lpData);
	return strProductVer;
}
//公司名称
CString CExecImageVersion::GetCompanyName()
{
	CString	strCompany;
	
	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\CompanyName"),
					&m_lpData,
					&m_uiDataSize);
	strCompany.Format("%s", m_lpData);
	return strCompany;
}
//合法版权
CString CExecImageVersion::GetCopyright()
{
	CString	strCopy;

	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\LegalCopyright"),
					&m_lpData,
					&m_uiDataSize);
	strCopy.Format("%s", m_lpData);
	return strCopy;
}

CString CExecImageVersion::GetComments()
{
	CString	strComments;
	
	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\Comments"),
					&m_lpData,
					&m_uiDataSize);
	strComments.Format("%s", m_lpData);
	return strComments;
}
//文件描述
CString CExecImageVersion::GetFileDescription()
{
	CString	strFileDescr;
	
	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\FileDescription"),
					&m_lpData,
					&m_uiDataSize);
	strFileDescr.Format("%s", m_lpData);
	return strFileDescr;
}
//版本号
CString CExecImageVersion::GetFileVersion()
{
	CString	strFileVer;

	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\FileVersion"),
					&m_lpData,
					&m_uiDataSize);
	strFileVer.Format("%s", m_lpData);
	return strFileVer;
}
//内部名称
CString CExecImageVersion::GetInternalName()
{
	CString	strIN;
	
	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\InternalName"),
					&m_lpData,
					&m_uiDataSize);
	strIN.Format("%s", m_lpData);
	return strIN;
}

CString CExecImageVersion::GetLegalTrademarks()
{
	CString	strLegTrade;
	
	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\LegalTrademarks"),
					&m_lpData,
					&m_uiDataSize);
	strLegTrade.Format("%s", m_lpData);
	return strLegTrade;
}

CString CExecImageVersion::GetPrivateBuild()
{
	CString	strPrivBuild;
	
	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\PrivateBuild"),
					&m_lpData,
					&m_uiDataSize);
	strPrivBuild.Format("%s", m_lpData);
	return strPrivBuild;
}

CString CExecImageVersion::GetSpecialBuild()
{
	CString	strSpecBuild;
	
	//Use the version information block to obtain the product name.
	::VerQueryValue(m_lpBuffer,
		            TEXT("\\StringFileInfo\\040904B0\\SpecialBuild"),
					&m_lpData,
					&m_uiDataSize);
	strSpecBuild.Format("%s", m_lpData);
	return strSpecBuild;
}

void CExecImageVersion::InitVer()
{
	m_dwHandle = 0;
	m_uiDataSize = 80;

	m_lpData = malloc(m_uiDataSize);
	// Get the version information block size,
	// then use it to allocate a storage buffer.
	m_dwSize = ::GetFileVersionInfoSize(m_lpszImageName, &m_dwHandle);
	m_lpBuffer = malloc(m_dwSize);

	// Get the versioninformation block
	::GetFileVersionInfo(m_lpszImageName, 0, m_dwSize, m_lpBuffer);
}
