// ShowSaveBMPDoc.h : interface of the CShowSaveBMPDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ShowSaveBMPDOC_H__BF72AFB4_5E99_4289_9F49_88397C73DD20__INCLUDED_)
#define AFX_ShowSaveBMPDOC_H__BF72AFB4_5E99_4289_9F49_88397C73DD20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Dib.h"
extern  m_dib;									//声明一个可用的外部成员变量


class CShowSaveBMPDoc : public CDocument
{
protected: // create from serialization only
	CShowSaveBMPDoc();
	DECLARE_DYNCREATE(CShowSaveBMPDoc)

// Attributes
public:
	CDib m_dib;		//声明一个Dib对象
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
	//{{AFX_VIRTUAL(CShowSaveBMPDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowSaveBMPDoc();
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
	//{{AFX_MSG(CShowSaveBMPDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ShowSaveBMPDOC_H__BF72AFB4_5E99_4289_9F49_88397C73DD20__INCLUDED_)
