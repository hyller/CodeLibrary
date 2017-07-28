// BaseMouseDemoDoc.h : interface of the CBaseMouseDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEMOUSEDEMODOC_H__9A490005_F527_4DC6_B711_15AFB4C74F95__INCLUDED_)
#define AFX_BASEMOUSEDEMODOC_H__9A490005_F527_4DC6_B711_15AFB4C74F95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseMouseDemoDoc : public CDocument
{
protected: // create from serialization only
	CBaseMouseDemoDoc();
	DECLARE_DYNCREATE(CBaseMouseDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseMouseDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBaseMouseDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseMouseDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEMOUSEDEMODOC_H__9A490005_F527_4DC6_B711_15AFB4C74F95__INCLUDED_)
