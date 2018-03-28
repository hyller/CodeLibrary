// CopyBmpDemoDoc.h : interface of the CCopyBmpDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COPYBMPDEMODOC_H__42C5110A_8143_4B42_AD56_5F156ADC9187__INCLUDED_)
#define AFX_COPYBMPDEMODOC_H__42C5110A_8143_4B42_AD56_5F156ADC9187__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCopyBmpDemoDoc : public CDocument
{
protected: // create from serialization only
	CCopyBmpDemoDoc();
	DECLARE_DYNCREATE(CCopyBmpDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCopyBmpDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCopyBmpDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCopyBmpDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPYBMPDEMODOC_H__42C5110A_8143_4B42_AD56_5F156ADC9187__INCLUDED_)
