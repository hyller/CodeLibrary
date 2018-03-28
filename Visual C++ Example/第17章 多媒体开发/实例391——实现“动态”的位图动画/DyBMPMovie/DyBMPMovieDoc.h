// DyBMPMovieDoc.h : interface of the CDyBMPMovieDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYBMPMOVIEDOC_H__A2B062FC_2683_4515_9073_0838962C977F__INCLUDED_)
#define AFX_DYBMPMOVIEDOC_H__A2B062FC_2683_4515_9073_0838962C977F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDyBMPMovieDoc : public CDocument
{
protected: // create from serialization only
	CDyBMPMovieDoc();
	DECLARE_DYNCREATE(CDyBMPMovieDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDyBMPMovieDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDyBMPMovieDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDyBMPMovieDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYBMPMOVIEDOC_H__A2B062FC_2683_4515_9073_0838962C977F__INCLUDED_)
