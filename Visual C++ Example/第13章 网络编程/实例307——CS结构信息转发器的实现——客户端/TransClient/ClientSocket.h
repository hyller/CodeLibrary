#if !defined(AFX_CLIENTSOCKET_H__C5A48EF4_C5B6_4D8D_9BDA_D0953814B5B9__INCLUDED_)
#define AFX_CLIENTSOCKET_H__C5A48EF4_C5B6_4D8D_9BDA_D0953814B5B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CAsyncSocket
{
// Attributes
public:
	BOOL m_bConnected;	 //是否连接
    UINT m_nLength;	     //消息长度
    char m_szBuffer[4096];  //消息缓冲区


// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
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

#endif // !defined(AFX_CLIENTSOCKET_H__C5A48EF4_C5B6_4D8D_9BDA_D0953814B5B9__INCLUDED_)
