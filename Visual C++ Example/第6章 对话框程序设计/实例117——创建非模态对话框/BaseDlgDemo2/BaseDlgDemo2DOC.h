// BaseDlgDemo2Doc.h : interface of the CBaseDlgDemo2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BaseDlgDemo2DOC_H__77D9C42E_71BF_4B59_B637_5B97DAD4CA0F__INCLUDED_)
#define AFX_BaseDlgDemo2DOC_H__77D9C42E_71BF_4B59_B637_5B97DAD4CA0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseDlgDemo2Doc : public CDocument
{
protected: // create from serialization only
	CBaseDlgDemo2Doc();
	DECLARE_DYNCREATE(CBaseDlgDemo2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDlgDemo2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBaseDlgDemo2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseDlgDemo2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BaseDlgDemo2DOC_H__77D9C42E_71BF_4B59_B637_5B97DAD4CA0F__INCLUDED_)
