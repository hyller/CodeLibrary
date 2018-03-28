// BaseDocViewDemo3Doc.h : interface of the CBaseDocViewDemo3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BaseDocViewDemo3DOC_H__68B5D037_AA49_4EC1_8300_1331BB89C19D__INCLUDED_)
#define AFX_BaseDocViewDemo3DOC_H__68B5D037_AA49_4EC1_8300_1331BB89C19D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DrawLine.h"
class CBaseDocViewDemo3Doc : public CDocument
{
protected: // create from serialization only
	CBaseDocViewDemo3Doc();
	DECLARE_DYNCREATE(CBaseDocViewDemo3Doc)
	CObArray m_lineArray;									//数组对象
// Attributes
public:
	void AddLine(CPoint pStar,CPoint pEnd);				//添加线条
	CDrawLine *GetLine(int index);								//获取线条对象
	int GetTotalLine();										//获取线条数目

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDocViewDemo3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBaseDocViewDemo3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseDocViewDemo3Doc)
	afx_msg void OnMenuUndo();
	afx_msg void OnMenuClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BaseDocViewDemo3DOC_H__68B5D037_AA49_4EC1_8300_1331BB89C19D__INCLUDED_)
