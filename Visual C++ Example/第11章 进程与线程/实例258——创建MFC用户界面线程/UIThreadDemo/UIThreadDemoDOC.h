// UIThreadDemoDoc.h : interface of the CUIThreadDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UIThreadDemoDOC_H__140FCBED_F506_4731_A961_BB1BFF767BB5__INCLUDED_)
#define AFX_UIThreadDemoDOC_H__140FCBED_F506_4731_A961_BB1BFF767BB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUIThreadDemoDoc : public CDocument
{
protected: // create from serialization only
	CUIThreadDemoDoc();
	DECLARE_DYNCREATE(CUIThreadDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUIThreadDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUIThreadDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUIThreadDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UIThreadDemoDOC_H__140FCBED_F506_4731_A961_BB1BFF767BB5__INCLUDED_)
