// LimitUseTimersDoc.h : interface of the CLimitUseTimersDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIMITUSETIMERSDOC_H__3E2AE6F8_6A83_466D_B883_E31FE1F09151__INCLUDED_)
#define AFX_LIMITUSETIMERSDOC_H__3E2AE6F8_6A83_466D_B883_E31FE1F09151__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLimitUseTimersDoc : public CDocument
{
protected: // create from serialization only
	CLimitUseTimersDoc();
	DECLARE_DYNCREATE(CLimitUseTimersDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLimitUseTimersDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLimitUseTimersDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLimitUseTimersDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIMITUSETIMERSDOC_H__3E2AE6F8_6A83_466D_B883_E31FE1F09151__INCLUDED_)
