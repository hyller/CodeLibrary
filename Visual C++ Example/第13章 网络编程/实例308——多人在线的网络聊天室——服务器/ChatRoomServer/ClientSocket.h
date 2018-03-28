#if !defined(AFX_CLIENTSOCKET_H__5B707F31_3AD5_4F47_B58E_ECFC99EB60F0__INCLUDED_)
#define AFX_CLIENTSOCKET_H__5B707F31_3AD5_4F47_B58E_ECFC99EB60F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target
class CClientSocketList;
class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket(CClientSocketList *);
	virtual ~CClientSocket();

// Overrides
public:
	CClientSocketList *List;
	CClientSocket * Front;
	CClientSocket * Next;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__5B707F31_3AD5_4F47_B58E_ECFC99EB60F0__INCLUDED_)
