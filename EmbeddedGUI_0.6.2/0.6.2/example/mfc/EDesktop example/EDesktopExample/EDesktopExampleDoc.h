// EDesktopExampleDoc.h : interface of the CEDesktopExampleDoc class
//


#pragma once


class CEDesktopExampleDoc : public CDocument
{
protected: // create from serialization only
	CEDesktopExampleDoc();
	DECLARE_DYNCREATE(CEDesktopExampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CEDesktopExampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void SetTitle(LPCTSTR lpszTitle);
};


