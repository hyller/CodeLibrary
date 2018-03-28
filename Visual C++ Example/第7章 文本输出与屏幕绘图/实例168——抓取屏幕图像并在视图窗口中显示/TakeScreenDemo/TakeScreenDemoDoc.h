// TakeScreenDemoDoc.h : interface of the CTakeScreenDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TAKESCREENDEMODOC_H__366A0B36_ACD5_4B48_96D4_759F0F7D78A1__INCLUDED_)
#define AFX_TAKESCREENDEMODOC_H__366A0B36_ACD5_4B48_96D4_759F0F7D78A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTakeScreenDemoDoc : public CDocument
{
protected: // create from serialization only
	CTakeScreenDemoDoc();
	DECLARE_DYNCREATE(CTakeScreenDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTakeScreenDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTakeScreenDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTakeScreenDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAKESCREENDEMODOC_H__366A0B36_ACD5_4B48_96D4_759F0F7D78A1__INCLUDED_)
