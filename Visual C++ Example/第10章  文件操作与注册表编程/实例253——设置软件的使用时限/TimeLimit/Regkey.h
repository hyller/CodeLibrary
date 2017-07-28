#ifndef REGKEY_INCLUDE_
#define REGKEY_INCLUDE_
#include "winreg.h"

class CRegKey
{
public:
	CRegKey();
	virtual ~CRegKey();

public:
    LONG Open (HKEY hKeyRoot, LPCTSTR pszPath);
    void Close();

	LONG Write (LPCTSTR pszKey, DWORD dwVal);
	LONG Write (LPCTSTR pszKey, LPCTSTR pszVal);
	LONG Write (LPCTSTR pszKey, const BYTE* pData, DWORD dwLength);

	LONG Read (LPCTSTR pszKey, DWORD& dwVal);
	LONG Read (LPCTSTR pszKey, CString& sVal);
	LONG Read (LPCTSTR pszKey, BYTE* pData, DWORD& dwLength);

    LONG GetEnumKeys(HKEY hKeyRoot, LPCTSTR pszPath, CStringArray &strArray);
    LONG GetEnumValues(HKEY hKeyRoot, LPCTSTR pszPath, CStringArray &strArray);

protected:
	HKEY 	m_hKey;
	CString m_strPath;
};

#endif  //-REGKEY_INCLUDE_