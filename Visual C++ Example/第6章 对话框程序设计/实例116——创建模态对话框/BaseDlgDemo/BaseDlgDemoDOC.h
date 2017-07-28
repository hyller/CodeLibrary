// BaseDlgDemoDoc.h : interface of the CBaseDlgDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BaseDlgDemoDOC_H__77D9C42E_71BF_4B59_B637_5B97DAD4CA0F__INCLUDED_)
#define AFX_BaseDlgDemoDOC_H__77D9C42E_71BF_4B59_B637_5B97DAD4CA0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseDlgDemoDoc : public CDocument
{
protected: // create from serialization only
	CBaseDlgDemoDoc();
	DECLARE_DYNCREATE(CBaseDlgDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDlgDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBaseDlgDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseDlgDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BaseDlgDemoDOC_H__77D9C42E_71BF_4B59_B637_5B97DAD4CA0F__INCLUDED_)
