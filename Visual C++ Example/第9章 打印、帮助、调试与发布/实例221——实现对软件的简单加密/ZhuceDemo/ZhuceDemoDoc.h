// ZhuceDemoDoc.h : interface of the CZhuceDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZHUCEDEMODOC_H__2BF57508_3E00_44CC_973C_BB73C29D8C8C__INCLUDED_)
#define AFX_ZHUCEDEMODOC_H__2BF57508_3E00_44CC_973C_BB73C29D8C8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CZhuceDemoDoc : public CDocument
{
protected: // create from serialization only
	CZhuceDemoDoc();
	DECLARE_DYNCREATE(CZhuceDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZhuceDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CZhuceDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CZhuceDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHUCEDEMODOC_H__2BF57508_3E00_44CC_973C_BB73C29D8C8C__INCLUDED_)
