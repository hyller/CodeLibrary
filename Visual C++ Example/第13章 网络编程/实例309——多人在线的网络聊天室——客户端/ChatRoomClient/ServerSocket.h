#if !defined(AFX_SERVERSOCKET_H__2BEE7F15_EEC9_4B01_9226_146C47F84776__INCLUDED_)
#define AFX_SERVERSOCKET_H__2BEE7F15_EEC9_4B01_9226_146C47F84776__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CServerSocket command target
class CChatRoomClientDlg;
class CServerSocket : public CSocket
{
// Attributes
public:
	CChatRoomClientDlg * myDlg;//主对话框指针
	BOOL SetDlg(CChatRoomClientDlg *tmp);
	CString NikeName;//用户昵称

// Operations
public:
	CServerSocket();
	virtual ~CServerSocket();


// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CServerSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCKET_H__2BEE7F15_EEC9_4B01_9226_146C47F84776__INCLUDED_)
