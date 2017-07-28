// BaseToolbarDoc.h : interface of the CBaseToolbarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASETOOLBARDOC_H__11712290_9CEC_4217_8549_46006C160922__INCLUDED_)
#define AFX_BASETOOLBARDOC_H__11712290_9CEC_4217_8549_46006C160922__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseToolbarDoc : public CDocument
{
protected: // create from serialization only
	CBaseToolbarDoc();
	DECLARE_DYNCREATE(CBaseToolbarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseToolbarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBaseToolbarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseToolbarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASETOOLBARDOC_H__11712290_9CEC_4217_8549_46006C160922__INCLUDED_)
