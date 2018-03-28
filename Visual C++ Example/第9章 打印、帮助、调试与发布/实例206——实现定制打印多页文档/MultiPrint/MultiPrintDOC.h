// MultiPrintDoc.h : interface of the CMultiPrintDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MultiPrintDOC_H__F766CAE5_EB3A_4346_AE80_D3F26B8DB8DE__INCLUDED_)
#define AFX_MultiPrintDOC_H__F766CAE5_EB3A_4346_AE80_D3F26B8DB8DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiPrintDoc : public CDocument
{
protected: // create from serialization only
	CMultiPrintDoc();
	DECLARE_DYNCREATE(CMultiPrintDoc)

// Attributes
public:
	CStringArray m_stringArray;
	int m_LinePerPage;//每页打印的行数

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiPrintDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMultiPrintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiPrintDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MultiPrintDOC_H__F766CAE5_EB3A_4346_AE80_D3F26B8DB8DE__INCLUDED_)
