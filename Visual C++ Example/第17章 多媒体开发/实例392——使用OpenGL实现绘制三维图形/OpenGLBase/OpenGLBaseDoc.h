// OpenGLBaseDoc.h : interface of the COpenGLBaseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLBASEDOC_H__77C8279B_8D07_42F7_B6A3_FF166A5CBDB3__INCLUDED_)
#define AFX_OPENGLBASEDOC_H__77C8279B_8D07_42F7_B6A3_FF166A5CBDB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COpenGLBaseDoc : public CDocument
{
protected: // create from serialization only
	COpenGLBaseDoc();
	DECLARE_DYNCREATE(COpenGLBaseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLBaseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COpenGLBaseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGLBaseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLBASEDOC_H__77C8279B_8D07_42F7_B6A3_FF166A5CBDB3__INCLUDED_)
