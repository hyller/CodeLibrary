// GradientTextDemoDoc.h : interface of the CGradientTextDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRADIENTTEXTDEMODOC_H__212DE35A_507E_4FCA_BC2F_E1DD6458D0A5__INCLUDED_)
#define AFX_GRADIENTTEXTDEMODOC_H__212DE35A_507E_4FCA_BC2F_E1DD6458D0A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGradientTextDemoDoc : public CDocument
{
protected: // create from serialization only
	CGradientTextDemoDoc();
	DECLARE_DYNCREATE(CGradientTextDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGradientTextDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGradientTextDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGradientTextDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRADIENTTEXTDEMODOC_H__212DE35A_507E_4FCA_BC2F_E1DD6458D0A5__INCLUDED_)
