#pragma once


// CTextDialog dialog

class CTextDialog : public CDialog
{
	DECLARE_DYNAMIC(CTextDialog)

public:
	CTextDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTextDialog();

// Dialog Data
	enum { IDD = IDD_TEXT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  // Stores the text string that is entered
  CString m_TextString;
};
