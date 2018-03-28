// FaceControl3Doc.h : interface of the CFaceControl3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FaceControl3DOC_H__1362BDBE_319B_458F_A72D_4E38DCD95C26__INCLUDED_)
#define AFX_FaceControl3DOC_H__1362BDBE_319B_458F_A72D_4E38DCD95C26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFaceControl3Doc : public CDocument
{
protected: // create from serialization only
	CFaceControl3Doc();
	DECLARE_DYNCREATE(CFaceControl3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceControl3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFaceControl3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFaceControl3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FaceControl3DOC_H__1362BDBE_319B_458F_A72D_4E38DCD95C26__INCLUDED_)
