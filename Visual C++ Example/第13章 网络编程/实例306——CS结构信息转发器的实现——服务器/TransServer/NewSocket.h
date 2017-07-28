#if !defined(AFX_NEWSOCKET_H__156A76A7_0C2B_4DC3_89D2_C3BB85238B89__INCLUDED_)
#define AFX_NEWSOCKET_H__156A76A7_0C2B_4DC3_89D2_C3BB85238B89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CNewSocket command target

class CNewSocket : public CAsyncSocket
{
// Attributes
public:
	UINT m_nLength;	     //消息长度
    char m_szBuffer[4096];  //消息缓冲区


// Operations
public:
	CNewSocket();
	virtual ~CNewSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CNewSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWSOCKET_H__156A76A7_0C2B_4DC3_89D2_C3BB85238B89__INCLUDED_)
