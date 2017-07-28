// TimerDemoDoc.h : interface of the CTimerDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMERDEMODOC_H__B5421D03_6BE7_43F7_9DC8_BBDD2E4093B5__INCLUDED_)
#define AFX_TIMERDEMODOC_H__B5421D03_6BE7_43F7_9DC8_BBDD2E4093B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTimerDemoDoc : public CDocument
{
protected: // create from serialization only
	CTimerDemoDoc();
	DECLARE_DYNCREATE(CTimerDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTimerDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTimerDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERDEMODOC_H__B5421D03_6BE7_43F7_9DC8_BBDD2E4093B5__INCLUDED_)
