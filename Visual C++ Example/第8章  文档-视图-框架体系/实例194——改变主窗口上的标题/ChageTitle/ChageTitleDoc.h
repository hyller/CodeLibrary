// ChageTitleDoc.h : interface of the CChageTitleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHAGETITLEDOC_H__03F208FC_1C32_4932_BA3F_4B8509B47862__INCLUDED_)
#define AFX_CHAGETITLEDOC_H__03F208FC_1C32_4932_BA3F_4B8509B47862__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChageTitleDoc : public CDocument
{
protected: // create from serialization only
	CChageTitleDoc();
	DECLARE_DYNCREATE(CChageTitleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChageTitleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChageTitleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChageTitleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAGETITLEDOC_H__03F208FC_1C32_4932_BA3F_4B8509B47862__INCLUDED_)
