// SinglePrintDoc.h : interface of the CSinglePrintDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEPRINTDOC_H__F766CAE5_EB3A_4346_AE80_D3F26B8DB8DE__INCLUDED_)
#define AFX_SINGLEPRINTDOC_H__F766CAE5_EB3A_4346_AE80_D3F26B8DB8DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSinglePrintDoc : public CDocument
{
protected: // create from serialization only
	CSinglePrintDoc();
	DECLARE_DYNCREATE(CSinglePrintDoc)

// Attributes
public:
	CStringArray m_stringArray;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinglePrintDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSinglePrintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinglePrintDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEPRINTDOC_H__F766CAE5_EB3A_4346_AE80_D3F26B8DB8DE__INCLUDED_)
