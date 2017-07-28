// ShowSaveBMPDoc.cpp : implementation of the CShowSaveBMPDoc class
//

#include "stdafx.h"
#include "ShowSaveBMP.h"

#include "ShowSaveBMPDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPDoc

IMPLEMENT_DYNCREATE(CShowSaveBMPDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowSaveBMPDoc, CDocument)
	//{{AFX_MSG_MAP(CShowSaveBMPDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPDoc construction/destruction

CShowSaveBMPDoc::CShowSaveBMPDoc()
{
	// TODO: add one-time construction code here
	m_hDIB = NULL;							// 初始化变量
	m_palDIB = NULL;
	m_sizeDoc = CSize(1,1);
}

CShowSaveBMPDoc::~CShowSaveBMPDoc()
{
	if (m_hDIB != NULL)							// 判断是否有DIB对象
	{		
		::GlobalFree((HGLOBAL) m_hDIB);
	}
	if (m_palDIB != NULL)						// 判断调色板是否存在
	{
		delete m_palDIB;
	}
}

BOOL CShowSaveBMPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPDoc serialization

void CShowSaveBMPDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPDoc diagnostics

#ifdef _DEBUG
void CShowSaveBMPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowSaveBMPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPDoc commands

BOOL CShowSaveBMPDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized creation code here
	CFile file;
	if (!file.Open(lpszPathName, CFile::modeRead | 
		CFile::shareDenyWrite))					// 打开文件
	{					
		return FALSE;							// 返回FALSE
	}	
	DeleteContents();
	m_hDIB=m_dib.LoadFile(file);			//调用ReadDIBFile()读取图像
	if(m_hDIB==NULL)							
	{	
		AfxMessageBox("图像格式不正确！");			// 提示出错	
		return FALSE;
	}		
	SetDib();									// 初始化DIB
	if (m_hDIB == NULL)							// 判断读取文件是否成功
	{		
		AfxMessageBox("读取图像时出错");			// 提示出错				
		return FALSE;							// 返回FALSE
	}		
	SetPathName(lpszPathName);					// 设置文件名称		
	SetModifiedFlag(FALSE);						// 初始化脏标记为FALSE		
	return TRUE;								// 返回TRUE
}

void CShowSaveBMPDoc::SetDib()
{	
	LPSTR lpDIB = (LPSTR) ::GlobalLock((HGLOBAL) m_hDIB);	
// 判断图像是否过大
	if (m_dib.GetWidth(lpDIB) > INT_MAX ||m_dib.GetHeight(lpDIB) > INT_MAX){
		::GlobalUnlock((HGLOBAL) m_hDIB);				
		::GlobalFree((HGLOBAL) m_hDIB);			// 释放DIB对象			
		m_hDIB = NULL;						// 设置DIB为空		
		AfxMessageBox("初始化失败");		
		return;
	}
// 设置文档大小	
	m_sizeDoc = CSize((int)m_dib.GetWidth(lpDIB), (int)m_dib.GetHeight(lpDIB)); 
	::GlobalUnlock((HGLOBAL) m_hDIB);	
	m_palDIB = new CPalette;						// 创建新调色板		
	if (m_palDIB == NULL)						// 判断是否创建成功
	{		
		::GlobalFree((HGLOBAL) m_hDIB);			// 失败		
		m_hDIB = NULL;						// 设置DIB对象为空
		return;
	}	
	// 调用ConstructPalette来创建调色板
	if (m_dib.ConstructPalette(m_hDIB, m_palDIB) == NULL)
	{				
		delete m_palDIB;						// 删除
		m_palDIB = NULL;						// 设置为空	
		return;								// 返回空
	}
}
void CShowSaveBMPDoc::UpdateObject(HGLOBAL hDIB)
{		
	if (m_hDIB != NULL)               		// 判断DIB是否为空
		{		
		::GlobalFree((HGLOBAL) m_hDIB);		// 非空，则清除
		}	
	m_hDIB = hDIB;                     		// 替换成新的DIB对象	
}



BOOL CShowSaveBMPDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	CFile file;
	if(!file.Open(lpszPathName, CFile::modeCreate |		// 打开文件
	  CFile::modeReadWrite | CFile::shareExclusive))
	{
		return FALSE;							// 返回FALSE
	}
	BOOL bSuccess = FALSE;	
	bSuccess = m_dib.SaveFile(m_hDIB, file);			// 保存图像	
	file.Close();								// 关闭文件	
	SetModifiedFlag(FALSE);						// 重置胀标记为FALSE
	if (!bSuccess)
	{			
		AfxMessageBox("保存BMP图像时出错");		// 提示出错
	}	
	return bSuccess;
}
