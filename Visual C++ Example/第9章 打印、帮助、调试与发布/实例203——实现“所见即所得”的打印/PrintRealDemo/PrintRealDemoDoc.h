// PrintRealDemoDoc.h : interface of the CPrintRealDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRINTREALDEMODOC_H__520B3E56_7D50_48A4_8F42_30A6A2F3D98F__INCLUDED_)
#define AFX_PRINTREALDEMODOC_H__520B3E56_7D50_48A4_8F42_30A6A2F3D98F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPrintRealDemoDoc : public CDocument
{
protected: // create from serialization only
	CPrintRealDemoDoc();
	DECLARE_DYNCREATE(CPrintRealDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintRealDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintRealDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrintRealDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTREALDEMODOC_H__520B3E56_7D50_48A4_8F42_30A6A2F3D98F__INCLUDED_)
