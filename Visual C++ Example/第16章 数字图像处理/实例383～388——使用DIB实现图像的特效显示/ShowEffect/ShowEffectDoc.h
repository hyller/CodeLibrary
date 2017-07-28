// ShowEffectDoc.h : interface of the CShowEffectDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWEFFECTDOC_H__E592659D_4D62_4C1F_B391_E6602C31BD0C__INCLUDED_)
#define AFX_SHOWEFFECTDOC_H__E592659D_4D62_4C1F_B391_E6602C31BD0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Dib.h"
extern  m_dib;									//声明一个可用的外部成员变量


class CShowEffectDoc : public CDocument
{
protected: // create from serialization only
	CShowEffectDoc();
	DECLARE_DYNCREATE(CShowEffectDoc)

// Attributes
public:
	CDib m_dib;								//声明一个Dib对象
// Operations
public:
	HGLOBAL GetHObject() const					//获取Dib对象的句柄
		{ return m_hDIB; }
	CPalette* GetDocPal() const						//获取调色板指针
		{ return m_palDIB; }
	void UpdateObject(HGLOBAL hDIB);				//更新dib对象
	void SetDib();								//初始化dib对象

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowEffectDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowEffectDoc();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	HGLOBAL m_hDIB;							//定义指向DIB的句柄变量
	CPalette* m_palDIB;							//定义指向逻辑调色板的指针
	CSize m_sizeDoc;							//文档大小的变量


// Generated message map functions
protected:
	//{{AFX_MSG(CShowEffectDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWEFFECTDOC_H__E592659D_4D62_4C1F_B391_E6602C31BD0C__INCLUDED_)
