// PrintRealDemo2Doc.h : interface of the CPrintRealDemo2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PrintRealDemo2DOC_H__520B3E56_7D50_48A4_8F42_30A6A2F3D98F__INCLUDED_)
#define AFX_PrintRealDemo2DOC_H__520B3E56_7D50_48A4_8F42_30A6A2F3D98F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPrintRealDemo2Doc : public CDocument
{
protected: // create from serialization only
	CPrintRealDemo2Doc();
	DECLARE_DYNCREATE(CPrintRealDemo2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintRealDemo2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintRealDemo2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrintRealDemo2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PrintRealDemo2DOC_H__520B3E56_7D50_48A4_8F42_30A6A2F3D98F__INCLUDED_)
