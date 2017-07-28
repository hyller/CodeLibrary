// CaptureMouseDoc.h : interface of the CCaptureMouseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAPTUREMOUSEDOC_H__754CA51B_F237_453E_8339_FD9B7501091F__INCLUDED_)
#define AFX_CAPTUREMOUSEDOC_H__754CA51B_F237_453E_8339_FD9B7501091F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCaptureMouseDoc : public CDocument
{
protected: // create from serialization only
	CCaptureMouseDoc();
	DECLARE_DYNCREATE(CCaptureMouseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptureMouseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCaptureMouseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCaptureMouseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTUREMOUSEDOC_H__754CA51B_F237_453E_8339_FD9B7501091F__INCLUDED_)
