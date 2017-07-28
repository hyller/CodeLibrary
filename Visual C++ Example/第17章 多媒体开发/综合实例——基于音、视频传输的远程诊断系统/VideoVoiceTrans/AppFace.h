/*
  File:	appface.h
  Description:	AppFace UI SDK export functions.
  Version  0.4
 
  Compatible with:
       Microsoft Windows 9x, NT, 2000, XP ,2003
       Microsoft Visual C++ 5-7
  uses no MFC
 
 *==========================================================
 * Cpyright MatinSoft Inc. 2004.11.22
 *
 * COVERED CODE IS PROVIDED UNDER THIS LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTY
 * OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, WITHOUT LIMITATION, WARRANTIES
 * THAT THE COVERED CODE IS FREE OF DEFECTS, MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE
 * OR NON-INFRINGING. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE COVERED
 * CODE IS WITH YOU. SHOULD ANY COVERED CODE PROVE DEFECTIVE IN ANY RESPECT, YOU (NOT
 * THE INITIAL DEVELOPER OR ANY OTHER CONTRIBUTOR) ASSUME THE COST OF ANY NECESSARY
 * SERVICING, REPAIR OR CORRECTION. THIS DISCLAIMER OF WARRANTY CONSTITUTES AN ESSENTIAL
 * PART OF THIS LICENSE. NO USE OF ANY COVERED CODE IS AUTHORIZED HEREUNDER EXCEPT UNDER
 * THIS DISCLAIMER.
 *
 * Use at your own risk!
 * ==========================================================
What is AppFace ?
   AppFace For VC is a windows library which is designed to develop software
User Interface easily and quickly, or you can name it as "Windows application skin tool".It
make you beautify your software easily with calling several functions . With AppFace you could
 save a mass of time and energy for the design of software UI , and you can create the 
 characterful and creative "application face" for your software quickly .
  
How to use it ?
   AppFace.dll is a standard windows dynamic library,you can load it staticly or dynmaicly.

  Call it staticly:
  1.Copy appface.h and appface.lib to your project folder,and add them to your project ; copy appface.dll
to your application export folder,remark "#define LOAD_APPFACE_DYNAMIC" statement in appface.h 
  2.Load appface before the first window created  by call :                 SkinStart(char* UiResourceFile,0,GTP_LOAD_FILE,0,0);
  3.Before exit the process to release resource call this :                 SkinRemove();

  Call it dynamicly:
  The class CAppFace help you to load appface.dll easily .
  1.Include this file in your project,and copy "AppFace.dll" to the project EXE file output folder.
  2.Declare a global variable in your project:                              CAppFace g_af ;
  3.Load appface before the first window created  by call :                 g_af.Start(char* UiResourceFile);
  4.Before exit the process to release resource call this :                 g_af.Remove();

Bugs reported:   
 
  appface@matinsoft.com

  http://www.matinsoft.com
  http://www.appface.com

------------------------------------------------------------
简介:
    AppFace For VC 是一个Windows界面开发库,它能够使您更轻松，更快捷的开发
软件界面。您也可以把它称做"应用程序皮肤工具"。使用AppFace界面开发包,只需
调用几个函数，添加几行代码就能使您的软件拥有漂亮的外观。它能最大限度的降低您
在软件界面上所花费的时间和精力,使您能够将工作重心完全放在软件的核心价值的
开发上.

使用方法:
  AppFace.dll 是一个标准的Windows 动态链接库，您可以静态或动态的调用它的输
出函数 。

  静态调用:
  1.将 "appface.h" 已及 "appface.lib" 拷贝到您的工程目录下,并将其添加到您的
工程中;将"AppFace.dll"拷贝到EXE文件的输出目录,去掉 "appface.h"中的如下语句: 
"#define LOAD_APPFACE_DYNAMIC"
  2. 在创建第一个窗口前调用  SkinStart (char * UiResourceFile,0,GTP_LOAD_FILE,0,0)    ;
  3. 在程序退出前调用                    SkinRemove()    ;

  动态调用:
  CAppFace这个类包装了对AppFace.dll 中输出函数的调用,帮助您更容易的
使用 AppFace 界面开发包. 
  1. 将这个文件添加进您的工程,将"AppFace.dll"拷贝到EXE文件的输出目录
  2. 在您的工程中声明一个全局变量          CAppFace g_af ;
  3. 在创建第一个窗口前调用                g_af.Start(char * UiResourceFile)    ;
  4. 在程序退出前调用                      g_af.Remove()    ;
 
Bug reported:
  support_cn@matinsoft.com

  http://www.matinsoft.com
  http://www.appface.com

-------------------------------------------------------------
History:
AppFace.h 0.4    2004.12.20
   Added an  export function : SkinThread
   Supported loading appface.dll static linked .
   Modified the paramerers order  for CAppFace::Start  function
   Modified the description for this file .

AppFace.h 0.3    2004.12.08
   Modified "Release" member function to prevert from throwing an exception
for debug version under Win XP
   Modified the function prototype
   Added a member function : BOOL SkinWindow(HWND hWnd,BOOL bSkin) ; We can decide which Window we need skin or not skin
   Modified the description for class CAppFace .

AppFace.h 0.2    2004.11.25
   Modified "Start" member fucntion to load urf file from resource or memory.
   Modified the description for class CAppFace .
   Supported UNICODE
   Added a help function,  void T2C(IN LPCTSTR src,OUT char* dst,IN int dstlen) 
        which used to convert a TCHAR string to char string
  
AppFace.h 0.1    2004.09.25
   Can work. 
*/

#ifndef __APPFACE_H__
#define __APPFACE_H__


#define GTP_LOAD_FILE     1
#define GTP_LOAD_MEMORY   2
#define GTP_LOAD_RESOURCE 3


//////////////////////////////////////////////
/*Uncomments the below statement to load appface.dll dynamicly
*/
//#define LOAD_APPFACE_DYNAMIC 
//////////////////////////////////////////////

//#ifdef  LOAD_APPFACE_DYNAMIC   //Load appface dynamic from "appface.dll"

class CAppFace
{
public:

typedef BOOL  (__stdcall *APPFACE_START)(char*,char*,int,DWORD,char*) ;
typedef void  (__stdcall *APPFACE_REMOVE)();
typedef BOOL  (__stdcall *APPFACE_SKINWINDOW)(HWND,BOOL);
typedef void  (__stdcall *APPFACE_THREAD)();

	CAppFace(LPCTSTR DllPath = _T("AppFace.dll"))
	{
		pfnStart    = NULL ;
		pfnRemove   = NULL ;
		pfnThread     = NULL ;
		pfnSkinWindow = NULL ;
		m_bValid    = FALSE; 
		m_hDll      = NULL ;
		Init(DllPath) ;
	};
	~CAppFace(){Release(); };

	BOOL Init(LPCTSTR DllPath)
	{
		if(m_hDll && m_bValid)	
			return TRUE;
		m_hDll = ::LoadLibrary(DllPath);
		if(m_hDll == NULL)
			return FALSE ;
		
		pfnStart = (APPFACE_START) GetProcAddress(m_hDll, "SkinStart"); 
		if(!pfnStart)	    return FALSE; 
		pfnRemove= (APPFACE_REMOVE)GetProcAddress(m_hDll, "SkinRemove"); 
		if(!pfnRemove)	    return FALSE; 
		pfnSkinWindow= (APPFACE_SKINWINDOW)GetProcAddress(m_hDll, "SkinWindowSet"); 
		if(!pfnSkinWindow)	    return FALSE; 
		pfnThread= (APPFACE_THREAD)GetProcAddress(m_hDll, "SkinThread"); 
		if(!pfnThread)	    return FALSE; 

		m_bValid = TRUE ;
		return TRUE ;
	};

	BOOL IsValid(){return m_bValid;};

	//----------------------------
	//We'll call these functions.
	void SkinThread(){if(pfnThread) pfnThread() ;}; 

	BOOL Start(void* SkinFile=NULL,  //Source buffer
		       LPCTSTR szCheckSum= NULL , //Checksum string,not used for the free version
			   int Type = GTP_LOAD_FILE, //Loading type
			   DWORD hInst= NULL,   //The HINSTANCE for the loaded module or the size of the memory block
			   LPCTSTR szResType =NULL  //Resource type ,only used when Type is GTP_LOAD_RESOURCE
			)
	{
		if(pfnStart)
		{
			if(!SkinFile)
			{
				return pfnStart(NULL,NULL,NULL,NULL,NULL);
			}
			else
			{
				char  checksum[256] ;
				if(Type == GTP_LOAD_MEMORY)
				{
					T2C(szCheckSum,checksum,256) ;
					return pfnStart((char*)SkinFile,checksum,Type,hInst,NULL);
				}
				else
				{
					char  skinfile[256] ;
					char  type[256] ;
					T2C((LPCTSTR)SkinFile,skinfile,256) ;
					T2C(szResType,type,256) ;
					T2C(szCheckSum,checksum,256) ;
                    return pfnStart(skinfile,checksum,Type,hInst,type);
				}
			}
		}
		return FALSE;
	};
	void Remove() { if(pfnRemove) pfnRemove() ;};

	BOOL SkinWindow(HWND hWnd,BOOL bSkin){if(pfnSkinWindow) return pfnSkinWindow(hWnd,bSkin);return FALSE;} ;
	//----------------------------

private:
	BOOL m_bValid  ;  
	HMODULE m_hDll ;

	APPFACE_START       pfnStart       ;
	APPFACE_REMOVE      pfnRemove      ;
	APPFACE_SKINWINDOW  pfnSkinWindow  ;
	APPFACE_THREAD      pfnThread      ;

	//Convert a TCHAR string to char string
	void T2C(IN LPCTSTR src,OUT char* dst,IN int dstlen)
	{
		memset(dst,0,dstlen);
		if(!src || !dst) return ;		
	//----------------------------
#ifdef UNICODE
		BOOL bRes= FALSE ;
		WideCharToMultiByte(CP_ACP,
			0,
			src,
			wcslen(src),
			dst,
			dstlen,
			NULL,
			&bRes);
#else
		strncpy(dst,src,dstlen-1)   ;
#endif
	} ;

protected:
	void Release()
	{
		/*
		If the m_hDll is not available,it will throw an exception for debug version,
		so we need "try{...} catch(...)"
		*/
		try{  
			if(m_hDll)
			{
				FreeLibrary(m_hDll) ;
				m_hDll = NULL       ;
				m_bValid = false    ;
				pfnStart = NULL     ;
				pfnRemove= NULL     ;
				pfnSkinWindow = NULL;
			}
		}catch(...)
		{
		}
	};
};

#else  //LOAD_APPFACE_DYNAMIC

#ifdef __cplusplus  
extern "C"
{
#endif

/*
Function: BOOL SkinStart(char* SkinFile,
			   char* CheckSum          ,
			   int   Type              ,
			   DWORD hInstance         ,
			   char* szResType )
Description  : The SkinStart function  perform the most work for appface UI library
Parameters   :   
      SkinFile 
        [ IN ]  Depands on the value of parameter Type
		        If the value of Type equal to GTP_LOAD_FILE , SkinFile means the string which 
			contained the disk file path .
				If the value of Type equal to GTP_LOAD_MEMORY , SkinFile means the address of the
			memory block.
				If the value of Type equal to GTP_LOAD_RESOURCE , SkinFile means the string 
			which contained the resource name .
			      
				If this value is NULL ,it will restore to the Windows default UI .
	  
	  CheckSum
	    [ IN ]  Only use for our regitered users.Input the valid checksum value(License Code),users can open the extra
	    	    characterful and creative URF which Matinsoft afforded .Otherwise leave this param NULL ,
				and you can only use the public URF .
	  
	  Type
	    [ IN ]  This value indicate where the URF we will load .It can be one of the bellow:
		        
				GTP_LOAD_FILE     : Means the URF we will load is a disk file
				GTP_LOAD_MEMORY   : Means the URF we will load is a memory block
				GTP_LOAD_RESOURCE : Means the URF we will load is from resource
	  hInstance
	    [ IN ]  Depands on the value of parameter Type
		        for GTP_LOAD_FILE     , hInstance can be any value .
				for GTP_LOAD_MEMORY   , hInstance means the memory block size .
				for GTP_LOAD_RESOURCE , hInstance means the HINSTANCE which the resource is from .
	  szResType
	    [ IN ]  Only used when Type equal to GTP_LOAD_RESOURCE ,means the resource type

Return Values: Return nor-zero if do this operation successfully
Remarks:
         For multithreaded applications ,you should call SkinStart at the main UI thread ,and call
	   SkinThread() in the other UI threads .
         
Example:
1.Load URF(UI Resource File) from disk file:   SkinStart(_T("c:\\Yourpath\\yoururf.urf"),"Your License Code",GTP_LOAD_FILE,NULL,NULL) ;
2.Load URF(UI Resource File) from Resource :   SkinStart(_T("IDR_URFNAME_YOURDEFINED"),"Your License Code",GTP_LOAD_RESOURCE,(DWORD)::GetModuleHandle(NULL),_T("RESOURCETYPE")) ;
3.Load URF(UI Resource File) from Memory   :   SkinStart((char*)pBuf,"Your License Code",GTP_LOAD_MEMORY,nBufLen,NULL)
4.Change the application UI                :   SkinStart(_T("c:\\Yourpath\\yourotherurf.urf"),"Your License Code",GTP_LOAD_FILE,NULL,NULL) ;
5.Return to windows default UI             :   SkinStart(0,0,0,0,0) ;
*/
BOOL __stdcall SkinStart(char* SkinFile  ,
			   char* CheckSum          ,
			   int   Type              ,
			   DWORD hInstance         ,
			   char* szResType ) ;


/*
Function: void SkinThread()

Description  : Init AppFace in another UI thread.
Parameters   :   
Return Values:
Remarks:
		  For multithreaded applications ,you should call SkinStart at the main UI thread ,and call
	   SkinThread in the other UI threads .
*/
void __stdcall SkinThread() ;



/*
Function: BOOL SkinWindowSet(HWND hWnd,BOOL bSkin)

Description  : The SkinWindowSet function skin or unskin the special window
Parameters   :   
      hWnd 
        [ IN ]  Handle to the window which will be skinned or unskinned. 
	  bSkin
	    [ IN ]  Specifies whether a window is skinned

Return Values: Return nor-zero if do this operation successfully
Remarks:
         Call SkinWindowSet function should be after call SkinStart function,otherwise it will 
	 return FALSE immediately .
		 This function afford an ability for users to draw the window by themself after loaded 
	 appface library.
*/
BOOL __stdcall SkinWindowSet(HWND hWnd,BOOL bSkin) ;


											
/*
Function: void SkinRemove()

Description  : The SkinRemove function removes AppFace skin from the process,and releases all
     the allocated resource .
Parameters   :   
Return Values:
Remarks:
        Once call SkinStart in a process ,you must call SkinRemove before terminating this
	 process ,otherwise it may be cause memory leaking .
	    You need do this function only once ,even you had call SkinStart or SkinThread times without number
	 for multithreaded applications .
*/
void __stdcall SkinRemove() ;         

#ifdef __cplusplus
}
#endif  //__cplusplus

//#endif  //LOAD_APPFACE_DYNAMIC
#endif  //__APPFACE_H__
