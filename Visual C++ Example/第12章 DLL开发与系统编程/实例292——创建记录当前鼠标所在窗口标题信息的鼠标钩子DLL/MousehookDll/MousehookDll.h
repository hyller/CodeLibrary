class AFX_EXT_CLASS CMouseHook:public CObject //AFX_EXT_CLASS宏声明类为导出类
{ 
public: 
	CMouseHook();//钩子类的构造函数
	~CMouseHook();//钩子类的析构函数 
	BOOL StartHook(HWND hWnd);//安装钩子函数 
	BOOL StopHook();//卸载钩子函数 
}; 
