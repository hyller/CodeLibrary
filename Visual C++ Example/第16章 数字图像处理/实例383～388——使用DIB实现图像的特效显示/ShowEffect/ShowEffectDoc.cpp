// ShowEffectDoc.cpp : implementation of the CShowEffectDoc class
//

#include "stdafx.h"
#include "ShowEffect.h"

#include "ShowEffectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowEffectDoc

IMPLEMENT_DYNCREATE(CShowEffectDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowEffectDoc, CDocument)
	//{{AFX_MSG_MAP(CShowEffectDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowEffectDoc construction/destruction

CShowEffectDoc::CShowEffectDoc()
{
	// TODO: add one-time construction code here
	m_hDIB = NULL;								// 初始化变量
	m_palDIB = NULL;
	m_sizeDoc = CSize(1,1);

}

CShowEffectDoc::~CShowEffectDoc()
{
	if (m_hDIB != NULL)								// 判断是否有DIB对象
	{		
		::GlobalFree((HGLOBAL) m_hDIB);
	}
	if (m_palDIB != NULL)							// 判断调色板是否存在
	{
		delete m_palDIB;
	}

}

BOOL CShowEffectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowEffectDoc serialization

void CShowEffectDoc::Serialize(CArchive& ar)
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
// CShowEffectDoc diagnostics

#ifdef _DEBUG
void CShowEffectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowEffectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowEffectDoc commands

BOOL CShowEffectDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	CFile file;
	if (!file.Open(lpszPathName, CFile::modeRead | CFile::shareDenyWrite))	// 打开文件
	{
		return FALSE;	
	}	
	DeleteContents();
	m_hDIB=m_dib.LoadFile(file);					//调用ReadDIBFile()读取图像
	if(m_hDIB==NULL)
	{	
		AfxMessageBox("图像格式不正确！");			// 提示出错	
		return FALSE;
	}		
	SetDib();									// 初始化DIB
	if (m_hDIB == NULL)							// 判断读取文件是否成功
	{		
		AfxMessageBox("读取图像时出错");				// 提示出错				
		return FALSE;								// 返回FALSE
	}		
	SetPathName(lpszPathName);					// 设置文件名称		
	return TRUE;								// 返回TRUE

}
void CShowEffectDoc::SetDib()
{	
	LPSTR lpDIB = (LPSTR) ::GlobalLock((HGLOBAL) m_hDIB);	
	// 判断图像是否过大
	if (m_dib.GetWidth(lpDIB) > INT_MAX ||m_dib.GetHeight(lpDIB) > INT_MAX){
		::GlobalUnlock((HGLOBAL) m_hDIB);				
		::GlobalFree((HGLOBAL) m_hDIB);					// 释放DIB对象	
		m_hDIB = NULL;								// 设置DIB为空		
		AfxMessageBox("初始化失败");		
		return;
	}
	// 设置文档大小	
	m_sizeDoc = CSize((int)m_dib.GetWidth(lpDIB), (int)m_dib.GetHeight(lpDIB)); 
	::GlobalUnlock((HGLOBAL) m_hDIB);	
	m_palDIB = new CPalette;							// 创建新调色板		
	if (m_palDIB == NULL)							// 判断是否创建成功
	{		
		::GlobalFree((HGLOBAL) m_hDIB);					// 失败		
		m_hDIB = NULL;								// 设置DIB对象为空
		return;
	}	
	// 调用ConstructPalette来创建调色板
	if (m_dib.ConstructPalette(m_hDIB, m_palDIB) == NULL)
	{				
		delete m_palDIB;								// 删除
		m_palDIB = NULL;								// 设置为空	
		return;										// 返回空
	}
}
