// ReBarDemoDoc.h : interface of the CReBarDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REBARDEMODOC_H__AE1E5568_8ADD_4284_A04C_C60457DF400B__INCLUDED_)
#define AFX_REBARDEMODOC_H__AE1E5568_8ADD_4284_A04C_C60457DF400B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CReBarDemoDoc : public CDocument
{
protected: // create from serialization only
	CReBarDemoDoc();
	DECLARE_DYNCREATE(CReBarDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReBarDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CReBarDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CReBarDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REBARDEMODOC_H__AE1E5568_8ADD_4284_A04C_C60457DF400B__INCLUDED_)
