// RegistDemoDoc.h : interface of the CRegistDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGISTDEMODOC_H__571E90CF_7411_4BBB_AB90_FB1ADCC93861__INCLUDED_)
#define AFX_REGISTDEMODOC_H__571E90CF_7411_4BBB_AB90_FB1ADCC93861__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRegistDemoDoc : public CDocument
{
protected: // create from serialization only
	CRegistDemoDoc();
	DECLARE_DYNCREATE(CRegistDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegistDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRegistDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRegistDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTDEMODOC_H__571E90CF_7411_4BBB_AB90_FB1ADCC93861__INCLUDED_)
