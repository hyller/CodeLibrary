#include <windows.h>
#include <vfw.h>
#include <commdlg.h>
#include "CapPicture.h"

LRESULT WINAPI MainWndProc( HWND, UINT, WPARAM, LPARAM ); 
LRESULT WINAPI SelCapDrvProc( HWND, UINT, WPARAM, LPARAM );
int EnumCapDrv();
DWORD WINAPI videoThreadProc(LPVOID lParam);
HANDLE ghInstance;
HWND hwndMain;
HWND hwndVideo;
HWND hwndSelCapDrvDlg;
HWND hwndSelCapDrvDlg_LBox;
HWND hwndRecord;
HANDLE hVideoThread;

CAPDRIVERCAPS CapDrVideoCaptures;
bool isRecordFileOpen = false;
char recordFile[260];
bool isPicFileOpen = false;
char pictureFile[260];
bool isRecording = false;
bool threadEnd = false;

int PASCAL WinMain( HINSTANCE hInstance,HINSTANCE hPrevInstance,
    LPSTR lpszCmdLine,int nCmdShow )
{
   WNDCLASS wc;
   MSG msg;
   if( !hPrevInstance )
   {
      wc.lpszClassName = "GenericAppClass";
      wc.lpfnWndProc = MainWndProc;
      wc.style = CS_HREDRAW|CS_VREDRAW;//窗口风格//CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
      wc.hInstance = hInstance;//当前应用程序实例句柄
      wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );//窗口图标
      wc.hCursor = LoadCursor( NULL, IDC_ARROW );//窗口光标
      wc.hbrBackground=(HBRUSH)GetStockObject(LTGRAY_BRUSH);//窗口背景色为浅灰色
	  wc.lpszMenuName=NULL;//窗口菜单
      wc.cbClsExtra = 0;
      wc.cbWndExtra = 0;
      RegisterClass( &wc );//注册窗口
   }
   ghInstance = hInstance;
   hwndMain = CreateWindow( "GenericAppClass","视频捕捉",WS_OVERLAPPEDWINDOW,
				200,200,460,400,NULL,NULL,hInstance,NULL);
   	ShowWindow(hwndMain,SW_SHOWNORMAL);
//显示最大化窗口
	UpdateWindow(hwndMain);//更新窗口

   while( GetMessage( &msg, NULL, 0, 0 ) ) 
   {
      TranslateMessage( &msg );
      DispatchMessage( &msg );
   }
   return msg.wParam;
}

LRESULT CALLBACK MainWndProc( HWND hwndMain, UINT msg, WPARAM wParam,LPARAM lParam )
{
   RECT rect;
   HDC hDC = GetDC(hwndMain);
   switch( msg ) 
   {
      case WM_PAINT:
  		 BringWindowToTop(hwndSelCapDrvDlg);//摄像头设备列表对话框
		 GetClientRect(hwndMain,&rect);
		 rect.top+=20;
		 DrawText(hDC,TEXT("使用VFW实现视频捕捉"),-1,&rect,DT_SINGLELINE|DT_CENTER);
         return( DefWindowProc( hwndMain, msg, wParam, lParam ));
	  case WM_COMMAND:
	  	 switch( wParam ) 
		 {
            case RECORDVIDEO://录像
            if(HIWORD(wParam) == BN_CLICKED && (HWND) lParam == hwndRecord)
            {
			   if (!isRecordFileOpen)
			   {
			   		OPENFILENAME ofn;
			   		ZeroMemory(&ofn, sizeof(OPENFILENAME));
					ofn.lStructSize = sizeof(OPENFILENAME);
					ofn.hwndOwner = hwndMain;
					ofn.lpstrFile = recordFile;
					ofn.nMaxFile = sizeof(recordFile);
					ofn.lpstrFilter = "Video\0*.avi";
					ofn.nFilterIndex = 1;
					ofn.lpstrFileTitle = NULL;
					ofn.nMaxFileTitle = 0;
					ofn.lpstrInitialDir = NULL;
					ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
					if(GetSaveFileName(&ofn) == TRUE)
					{
						strcpy(recordFile, ofn.lpstrFile);
						strcat(recordFile, ".avi");
						isRecordFileOpen = true; 
						DWORD id;
						SECURITY_ATTRIBUTES sa;
						sa.nLength = sizeof(SECURITY_ATTRIBUTES);
						sa.lpSecurityDescriptor = NULL;
						sa.bInheritHandle = TRUE;
						//开始录像线程
						hVideoThread = CreateThread(&sa, (ULONG)0, videoThreadProc, (LPVOID)(ULONG)0, (ULONG)0, &id);		
						if(hVideoThread == NULL)
							MessageBox(NULL, "线程创建失败!", "Thread", MB_OK | MB_ICONEXCLAMATION);
						
						break;
					}
				}
				if (isRecordFileOpen) //如果文件已经打开
				{
					if(isRecording)//正在录像
					{
						threadEnd = true;//停止录像
						capFileSaveAs(hwndVideo, recordFile);//保存文件
						SetWindowText(hwndRecord, "录像");
						isRecording = false;
						break;
					}	
					if(!isRecording )
					{
						int falg = 0;	
						MessageBox(hwndMain, "要覆盖文件吗?","File warning", MB_YESNO | MB_ICONWARNING);
						if (falg!= IDYES)
						{
							isRecordFileOpen = false;
							SendMessage(hwndMain, WM_COMMAND, MAKEWPARAM(RECORDVIDEO, BN_CLICKED), (LPARAM) hwndRecord);
						}
						if (falg== IDYES)
						{
							capCaptureSequence(hwndVideo);
							isRecording = true;
						}	
					break;
					}
				}
			}	
         	break;
         }
      break;
     case WM_CREATE:
	  	//创建视频窗口
		hwndVideo = capCreateCaptureWindow((LPSTR) "Capture Window",
	  					WS_CHILD | WS_VISIBLE,80, 50, 300, 240,(HWND) hwndMain,(int)1);
		//创建录像按钮
		hwndRecord = CreateWindow ("button", "录像", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 
				180, 314, 90, 28,hwndMain, (HMENU) RECORDVIDEO,(HINSTANCE)ghInstance,(LPVOID)NULL);			  		  			
		//创建设备列表对话框
		hwndSelCapDrvDlg = CreateDialog((HINSTANCE)ghInstance, 
						MAKEINTRESOURCE(SELCAPDRVDLG), 0, (DLGPROC)SelCapDrvProc);
		//在对话框中创建列表框									
		hwndSelCapDrvDlg_LBox = GetDlgItem(hwndSelCapDrvDlg, 
										   SELCAPDRVDLG_LSTBOX);
	    EnumCapDrv();//枚举系统摄像头设备
      break;
      case WM_DESTROY://退出窗口
      	 capPreview(hwndVideo, FALSE);
      	 capDriverDisconnect(hwndVideo);
         PostQuitMessage( 0 );
         break;
      default:
         return(DefWindowProc( hwndMain, msg, wParam, lParam ));
   }
   return 0;
}

LRESULT CALLBACK SelCapDrvProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch(msg)
	{
		case WM_INITDIALOG:
		    return TRUE;
		case WM_COMMAND:
			switch ( wParam )
			{
				case SELCAPDRVDLG_BUTTON:
					int sel = 0;
					SendMessage( hwndSelCapDrvDlg_LBox, LB_GETSELITEMS, 1, sel);
					SendMessage( hwndVideo, WM_CAP_DRIVER_CONNECT, sel, 0L); 
					SendMessage( hwndSelCapDrvDlg, WM_CLOSE, 0, 0);
					SendMessage( hwndVideo, WM_CAP_DRIVER_GET_CAPS,
								 sizeof(CAPDRIVERCAPS), (LONG) (LPVOID) &CapDrVideoCaptures);
					capPreviewRate( hwndVideo, 66 );
					capPreview( hwndVideo, TRUE );
			}
			return TRUE;
		case WM_CLOSE:
			DestroyWindow(hwndSelCapDrvDlg);
			return TRUE;
	}
	return( 0L );
}

int EnumCapDrv()//枚举摄像头设备
{
	char szDeviceName[80];
	char szDeviceVersion[80];
	char item[160];
	int i;
	for (i=0; i<10; i++)
	{
		if ( capGetDriverDescription(i, szDeviceName, sizeof(szDeviceName),
									szDeviceVersion, sizeof(szDeviceVersion)) )
		{
			strcpy(item, szDeviceName);
			strcat(item, " ");
			strcat(item, szDeviceVersion);
			SendMessage(hwndSelCapDrvDlg_LBox, LB_ADDSTRING, 0, (LPARAM) item);
            SendMessage(hwndSelCapDrvDlg_LBox, LB_SETITEMDATA, i, (LPARAM) i);
        }
    }
    return 0;
}


DWORD WINAPI videoThreadProc(LPVOID lParam)//录像线程
{
	SetWindowText(hwndRecord, "停止录像");
	capCaptureSequence(hwndVideo);//开始捕捉视频
	isRecording = true;
	while (!threadEnd)//直到单击“停止录像”按钮，结束线程
	MessageBox(NULL, "录像完毕", "thread", NULL);
	return 0;
}