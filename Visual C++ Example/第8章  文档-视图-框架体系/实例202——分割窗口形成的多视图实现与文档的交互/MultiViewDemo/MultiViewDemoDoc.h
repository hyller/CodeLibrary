// MultiViewDemoDoc.h : interface of the CMultiViewDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIVIEWDEMODOC_H__54C682CD_815B_4FEA_BABD_E00C4057AB43__INCLUDED_)
#define AFX_MULTIVIEWDEMODOC_H__54C682CD_815B_4FEA_BABD_E00C4057AB43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiViewDemoDoc : public CDocument
{
protected: // create from serialization only
	CMultiViewDemoDoc();
	DECLARE_DYNCREATE(CMultiViewDemoDoc)

// Attributes
public:
	CStringArray infoArray[4];//列表数组
	bool add;//添加标志

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiViewDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMultiViewDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiViewDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIVIEWDEMODOC_H__54C682CD_815B_4FEA_BABD_E00C4057AB43__INCLUDED_)
