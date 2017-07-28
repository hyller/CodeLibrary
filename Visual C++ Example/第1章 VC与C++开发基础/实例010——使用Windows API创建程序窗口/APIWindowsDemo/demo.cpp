#include <windows.h>										//头文件
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);		//窗口函数声明
char szClassName[]="windowclass";								//窗口结构体的名称
char szAppTitle[]="使用API创建窗口";							//窗口的标题
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam , INT nCmdShow)													//WinMain()函数的定义
{
	HWND hMainWnd;										//窗口句柄
	MSG msg;												//消息结构体
	WNDCLASS winclass;									//窗口结构体
if(!hPrevInstance)
//判断是否已有应用程序的实例在运行，给窗口结构体的数据成员赋值来规定所要建立的窗口的特征
	{
		winclass.style=CS_HREDRAW|CS_VREDRAW;				//窗口风格
		winclass.lpfnWndProc=WndProc;							//窗口的消息处理函数
		winclass.cbClsExtra=0; 								//窗口类无扩展
		winclass.cbWndExtra=0; 								//窗口实例无扩展
		winclass.hInstance=hInstance;							//当前应用程序实例句柄
		winclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);	//窗口的最小化图标为缺省图标
		winclass.hCursor=LoadCursor(NULL,IDC_ARROW);			//窗口采用箭头光标
		winclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);//窗口背景色为白色
		winclass.lpszMenuName=NULL;//无窗口菜单
		winclass.lpszClassName=szClassName; 					//给窗口结构体命名	
		RegisterClass(&winclass);								//注册窗口
	}
//下面用CreateWindow()函数来建立窗口，并返回所建立窗口的句柄
	hMainWnd=CreateWindow(
		szClassName,										//窗口结构体的名称
		 szAppTitle,										//窗口的标题
		 WS_OVERLAPPEDWINDOW,							//窗口风格为可重叠窗口
//下面四个参数代表窗口左上角x，y坐标和窗口的宽度与高度，都使用缺省值
CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
//下面参数分别为父窗口句柄、窗口菜单句柄、应用程序实例句柄和附加参数
NULL,NULL,hInstance,NULL);
	ShowWindow(hMainWnd,SW_SHOWNORMAL);						//显示窗口
	UpdateWindow(hMainWnd);									//更新窗口
//下面用While()循环来建立消息循环
	while(GetMessage(&msg,NULL,0,0))						//获取消息，填充msg结构体
	{
		TranslateMessage(&msg);							//翻译键盘消息
		DispatchMessage(&msg);					//向窗口函数发送消息，让窗口函数处理
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hMainwnd, UINT message, WPARAM wParam, LPARAM lParam)  															//窗口函数的定义
{
	HDC hdc;													//设备描述表
	PAINTSTRUCT ps;											//刷新区域
	RECT rect;													//矩形结构
	char messageleft[]="按下了鼠标左键！";		//单击鼠标左键，消息框将显示的提示内容
	   switch(message)											//判断消息标识符
	   {
	   case WM_PAINT:											//窗口重绘
		   {
		   hdc=BeginPaint(hMainwnd,&ps);
		   GetClientRect(hMainwnd,&rect);							//获取客户区区域
		   rect.bottom=rect.top+50;
		   DrawText(hdc,TEXT("使用Windows API创建Windows窗口程序！"),-1,&rect,DT_SINGLELINE| DT_CENTER|DT_VCENTER);										//在客户区中央输出文字
		   EndPaint(hMainwnd,&ps);
		   break;
		   }
	   case WM_LBUTTONDOWN:
		{
			MessageBox(GetFocus(),messageleft,"使用API创建窗口",MB_OK|MB_ICONINFORMATION);
			break;
		}
	   case WM_DESTROY://关闭应用程序窗口时发出的消息
		{
		PostQuitMessage(0);						//发出WM_QUIT消息，结束应用程序
		return 0;
		}
	   default :
		break;
	}
return DefWindowProc(hMainwnd,message,wParam,lParam);		//其它消息交给Windows做默认处理
}
