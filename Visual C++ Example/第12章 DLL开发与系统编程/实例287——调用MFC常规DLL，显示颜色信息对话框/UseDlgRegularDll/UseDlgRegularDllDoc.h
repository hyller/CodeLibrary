// UseDlgRegularDllDoc.h : interface of the CUseDlgRegularDllDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEDLGREGULARDLLDOC_H__0753E386_8FDC_483A_9ED7_B586B508D5EF__INCLUDED_)
#define AFX_USEDLGREGULARDLLDOC_H__0753E386_8FDC_483A_9ED7_B586B508D5EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUseDlgRegularDllDoc : public CDocument
{
protected: // create from serialization only
	CUseDlgRegularDllDoc();
	DECLARE_DYNCREATE(CUseDlgRegularDllDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseDlgRegularDllDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseDlgRegularDllDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseDlgRegularDllDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEDLGREGULARDLLDOC_H__0753E386_8FDC_483A_9ED7_B586B508D5EF__INCLUDED_)
