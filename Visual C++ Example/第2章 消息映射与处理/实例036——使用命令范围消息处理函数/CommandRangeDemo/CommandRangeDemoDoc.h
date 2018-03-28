// CommandRangeDemoDoc.h : interface of the CCommandRangeDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMANDRANGEDEMODOC_H__C5A5A966_DB98_4C57_AF76_513FDCB01E89__INCLUDED_)
#define AFX_COMMANDRANGEDEMODOC_H__C5A5A966_DB98_4C57_AF76_513FDCB01E89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCommandRangeDemoDoc : public CDocument
{
protected: // create from serialization only
	CCommandRangeDemoDoc();
	DECLARE_DYNCREATE(CCommandRangeDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommandRangeDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCommandRangeDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCommandRangeDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDRANGEDEMODOC_H__C5A5A966_DB98_4C57_AF76_513FDCB01E89__INCLUDED_)
