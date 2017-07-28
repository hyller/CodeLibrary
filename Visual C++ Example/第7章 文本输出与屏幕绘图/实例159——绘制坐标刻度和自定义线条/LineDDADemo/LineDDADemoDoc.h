// LineDDADemoDoc.h : interface of the CLineDDADemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEDDADEMODOC_H__D52E136C_91B4_4786_B0CD_AA56FDCA4E12__INCLUDED_)
#define AFX_LINEDDADEMODOC_H__D52E136C_91B4_4786_B0CD_AA56FDCA4E12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLineDDADemoDoc : public CDocument
{
protected: // create from serialization only
	CLineDDADemoDoc();
	DECLARE_DYNCREATE(CLineDDADemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineDDADemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLineDDADemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLineDDADemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEDDADEMODOC_H__D52E136C_91B4_4786_B0CD_AA56FDCA4E12__INCLUDED_)
