// OpenGLTextureDoc.h : interface of the COpenGLTextureDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OpenGLTextureDOC_H__77C8279B_8D07_42F7_B6A3_FF166A5CBDB3__INCLUDED_)
#define AFX_OpenGLTextureDOC_H__77C8279B_8D07_42F7_B6A3_FF166A5CBDB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COpenGLTextureDoc : public CDocument
{
protected: // create from serialization only
	COpenGLTextureDoc();
	DECLARE_DYNCREATE(COpenGLTextureDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLTextureDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COpenGLTextureDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGLTextureDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OpenGLTextureDOC_H__77C8279B_8D07_42F7_B6A3_FF166A5CBDB3__INCLUDED_)
