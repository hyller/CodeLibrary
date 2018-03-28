// FaceControl4Doc.h : interface of the CFaceControl4Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FaceControl4DOC_H__1362BDBE_319B_458F_A72D_4E38DCD95C26__INCLUDED_)
#define AFX_FaceControl4DOC_H__1362BDBE_319B_458F_A72D_4E38DCD95C26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFaceControl4Doc : public CDocument
{
protected: // create from serialization only
	CFaceControl4Doc();
	DECLARE_DYNCREATE(CFaceControl4Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceControl4Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFaceControl4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFaceControl4Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FaceControl4DOC_H__1362BDBE_319B_458F_A72D_4E38DCD95C26__INCLUDED_)
