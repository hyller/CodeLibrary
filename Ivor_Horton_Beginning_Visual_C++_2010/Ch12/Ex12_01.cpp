// Ex12_01.cpp   Native windows program to display text in a window
#include <windows.h>

LRESULT WINAPI WindowProc(HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam);

   // Insert code for WinMain() here (Listing OFWIN_1)
// Listing OFWIN_1
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
  WNDCLASSEX WindowClass;     // Structure to hold our window's attributes

  static LPCTSTR szAppName = L"OFWin";       // Define window class name
  HWND hWnd;                                // Window handle
  MSG msg;                                  // Windows message structure

  WindowClass.cbSize = sizeof(WNDCLASSEX);  // Set structure size

  // Redraw the window if the size changes
  WindowClass.style   = CS_HREDRAW | CS_VREDRAW;

  // Define the message handling function
  WindowClass.lpfnWndProc = WindowProc;

  WindowClass.cbClsExtra = 0;     // No extra bytes after the window class
  WindowClass.cbWndExtra = 0;     // structure or the window instance

  WindowClass.hInstance = hInstance;        // Application instance handle

  // Set default application icon
  WindowClass.hIcon = LoadIcon(0, IDI_APPLICATION);

  // Set window cursor to be the standard arrow
  WindowClass.hCursor = LoadCursor(0, IDC_ARROW);

  // Set gray brush for background color
  WindowClass.hbrBackground = 
                          static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));

  WindowClass.lpszMenuName = 0;             // No menu
  WindowClass.lpszClassName = szAppName;    // Set class name
  WindowClass.hIconSm = 0;                  // Default small icon

  // Now register our window class
  RegisterClassEx(&WindowClass);

  // Now we can create the window
  hWnd = CreateWindow(
          szAppName,                       // the window class name
          L"A Basic Window the Hard Way",   // The window title
          WS_OVERLAPPEDWINDOW,             // Window style as overlapped
          CW_USEDEFAULT,          // Default screen position of  upper left
          CW_USEDEFAULT,          // corner of our window as x,y...
          CW_USEDEFAULT,          // Default window size
          CW_USEDEFAULT,          // .... 
          0,                      // No parent window
          0,                      // No menu
          hInstance,              // Program Instance handle
          0                       // No window creation data
        );

  ShowWindow(hWnd, nCmdShow);     // Display the window
  UpdateWindow(hWnd);             // Cause window client area to be drawn

  // The message loop
  while(GetMessage(&msg, 0, 0, 0) == TRUE)  // Get any messages
  {
    TranslateMessage(&msg);                 // Translate the message
    DispatchMessage(&msg);                  // Dispatch the message
  }

  return static_cast<int>(msg.wParam);      // End, so return to Windows
}

   // Insert code for WindowProc() here (Listing OFWIN_2)
// Listing OFWIN_2
LRESULT WINAPI WindowProc(HWND hWnd, UINT message, 
                          WPARAM wParam, LPARAM lParam)
{
  HDC hDC;                       // Display context handle
  PAINTSTRUCT PaintSt;           // Structure defining area to be drawn
  RECT aRect;                    // A working rectangle

  switch(message)                // Process selected messages
  {
    case WM_PAINT:                     // Message is to redraw the window
      hDC = BeginPaint(hWnd, &PaintSt);// Prepare to draw the window

      // Get upper left and lower right of client area
      GetClientRect(hWnd, &aRect);

      SetBkMode(hDC, TRANSPARENT);     // Set text background mode

      // Now draw the text in the window client area
      DrawText(
             hDC,                 // Device context handle
             L"But, soft! What light through yonder window breaks?",
             -1,                  // Indicate null terminated string
             &aRect,              // Rectangle in which text is to be drawn
             DT_SINGLELINE|       // Text format - single line
             DT_CENTER|           //             - centered in the line
             DT_VCENTER);         //             - line centered in aRect

      EndPaint(hWnd, &PaintSt);   // Terminate window redraw operation
      return 0;

    case WM_DESTROY:              // Window is being destroyed
      PostQuitMessage(0);
      return 0;

    default:                      // Any other message - we don't
                                  // want to know, so call
                                  // default message processing
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
}
