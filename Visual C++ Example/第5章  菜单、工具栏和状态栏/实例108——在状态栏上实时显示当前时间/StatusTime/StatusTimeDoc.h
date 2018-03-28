// StatusTimeDoc.h : interface of the CStatusTimeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATUSTIMEDOC_H__F184AACD_217D_4E04_B39A_204A259D0486__INCLUDED_)
#define AFX_STATUSTIMEDOC_H__F184AACD_217D_4E04_B39A_204A259D0486__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStatusTimeDoc : public CDocument
{
protected: // create from serialization only
	CStatusTimeDoc();
	DECLARE_DYNCREATE(CStatusTimeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusTimeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStatusTimeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStatusTimeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSTIMEDOC_H__F184AACD_217D_4E04_B39A_204A259D0486__INCLUDED_)
