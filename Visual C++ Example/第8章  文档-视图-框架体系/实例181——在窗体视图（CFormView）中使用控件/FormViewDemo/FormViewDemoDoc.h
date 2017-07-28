// FormViewDemoDoc.h : interface of the CFormViewDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMVIEWDEMODOC_H__B96A06D8_2587_466E_872F_E660297B17FB__INCLUDED_)
#define AFX_FORMVIEWDEMODOC_H__B96A06D8_2587_466E_872F_E660297B17FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFormViewDemoDoc : public CDocument
{
protected: // create from serialization only
	CFormViewDemoDoc();
	DECLARE_DYNCREATE(CFormViewDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormViewDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFormViewDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFormViewDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMVIEWDEMODOC_H__B96A06D8_2587_466E_872F_E660297B17FB__INCLUDED_)
