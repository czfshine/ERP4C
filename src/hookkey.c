#include <windows.h>
#include <stdio.h>
// 全局变量
RECT rc; //记录滚屏的矩形区域
?
int xChar, yChar; //文本输入点坐标
WNDCLASSEX wnd; //窗口类结构变量
char szAppName[] = "键盘消息监视程序"; //窗口类名
//函数声明
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance,int iCmdShow);
//函数：WinMain
//作用：入口函数
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR szCmdLine,int iCmdShow)
{
　　MSG msg;
　　if(!MyRegisterClass(hInstance))
　　{
　　　　return FALSE;
　　}
　　
　　 if(!InitInstance(hInstance,iCmdShow))
　　{
　　　　return FALSE;
　　}
　　
　　while (GetMessage (&msg, NULL, 0, 0))
　　{
　　　　TranslateMessage (&msg);
　　　　DispatchMessage (&msg);
　　}
　　return msg.wParam;
}
//函数：ShowKey
//作用：实现在窗口中显示按键信息
void ShowKey (HWND hwnd, int iType,char *szMessage,WPARAM wParam,LPARAM lParam)
{
　　static char *szFormat[2] ={"%-14s %3d %c %6u %4d %5s %5s %6s %6s",
　　　　　　　　　　　　　 　　"%-14s %3d %c %6u %4d %5s %5s %6s %6s" };
　　char szBuffer[80];
　　HDC hdc;
　　ScrollWindowEx(hwnd, 0, -yChar, &rc,&rc,NULL,NULL,SW_INVALIDATE);
　　hdc = GetDC (hwnd);
　　SelectObject (hdc, GetStockObject (SYSTEM_FIXED_FONT));
　　TextOut (hdc,
　　　　　　 xChar,
　　　　　　 rc.bottom - yChar,
　　　　　　 szBuffer,
　　　　　　 wsprintf szBuffer,
　　　　　　 szFormat[iType],
　　　　　　 szMessage, //消息
　　　　　　 wParam, //虚拟键代码
　　　　　　 (BYTE) (iType ? wParam :‘ ’),//显示字符值
　　　　　　 LOWORD (lParam), // 重复次数
　　　　　　 HIWORD (lParam) & 0xFF, // OEM键盘扫描码
　　　　　　 //判断是否为增强键盘的扩展键
　　　　　　 (PSTR) (0x01000000 & lParam ? “是” : “否”),
　　　　　　 //判断是否同时使用了ALT键
　　　　　　 (PSTR) (0x20000000 & lParam ? “是” : “否”),
　　　　　　 (PSTR) (0x40000000 & lParam ? “按下” : “抬”),
　　　　　　 //判断前一次击键状
　　　　　　 (PSTR)(0x80000000 & lParam ? “按下” : “抬起”))
　　　　　　 //判断转换状态?
　　　　　　 );
　　ReleaseDC (hwnd, hdc); ?
　　ValidateRect (hwnd, NULL); ?
}
//函数：WndProc
//作用：处理主窗口的消息
LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
　　static char szTop[] ="消息键 字符 重复数 扫描码 扩展码 ALT 前一状态 转换状态";
　　static char szUnd[] ="_______ __ ____ _____ ______ ______ ___ _______ ______";
　　//在窗口中输出文字作为信息标题
　　HDC hdc;
　　PAINTSTRUCT ps;
　　TEXTMETRIC tm;
　　switch (iMsg)
　　{
　　　　case WM_CREATE://处理窗口创建的消息
　　　　hdc = GetDC (hwnd); //设定字体
　　　　SelectObject (hdc, GetStockObject (SYSTEM_FIXED_FONT)); //检取当前字体的度量数据
　　　　GetTextMetrics (hdc, &tm);
　　　　xChar = tm.tmAveCharWidth;//保存字体平均宽度
　　　　yChar = tm.tmHeight; //保存字体高度
　　　　ReleaseDC (hwnd, hdc);
　　　　rc.top = 3 * yChar / 2;
　　　　return 0;
　　　　case WM_SIZE://处理窗口大小改变的消息
　　　　//窗体改变后保存新的滚屏区域右下角坐标
　　　　rc.right = LOWORD (lParam);
　　　　rc.bottom = HIWORD (lParam);
　　　　UpdateWindow (hwnd);
　　　　return 0;
　　　　case WM_PAINT: //处理窗口重绘消息
　　　　InvalidateRect (hwnd, NULL, TRUE);
　　　　hdc = BeginPaint (hwnd, &ps);
　　　　SelectObject (hdc, GetStockObject (SYSTEM_FIXED_FONT)) ;
　　　　SetBkMode (hdc, TRANSPARENT) ;
　　　　TextOut (hdc, xChar, yChar / 2, szTop, (sizeof szTop) - 1) ;
　　　　TextOut (hdc, xChar, yChar / 2, szUnd, (sizeof szUnd) - 1) ;
　　　　EndPaint (hwnd, &ps);
　　　　return 0;
　　　　case WM_KEYDOWN:
　　　　//处理键盘上某一键按下的消息
　　　　ShowKey (hwnd, 0, "WM_KEYDOWN",wParam, lParam);
　　　　return 0;
　　　　case WM_KEYUP:
　　　　//处理键盘上某一按下键被释放的消息
　　　　ShowKey (hwnd, 0, "WM_KEYUP", wParam, lParam);
　　　　return 0;
　　　　case WM_CHAR:
　　　　//处理击键过程中产生的非系统键的可见字符消息
　　　　howKey (hwnd, 1, "WM_CHAR", wParam, lParam);
　　　　return 0;
　　　　case WM_DEADCHAR:
　　　　//处理击键过程中产生的非系统键"死字符"消息
　　　　ShowKey (hwnd, 1, "WM_DEADCHAR", wParam, lParam);
　　　　return 0;
　　　　case WM_SYSKEYDOWN:
　　　　//处理系统键按下的消息
　　　　ShowKey (hwnd, 0, "WM_SYSKEYDOWN",wParam, lParam);
　　　　break;
　　　　case WM_SYSKEYUP:
　　　　//处理系统键抬起的消息
　　　　ShowKey (hwnd, 0, "WM_SYSKEYUP", wParam, lParam);
　　　　break;
　　　　case WM_SYSCHAR://处理系统键可见字符消息
　　　　ShowKey (hwnd, 1, "WM_SYSCHAR", wParam, lParam);
　　　　break;
　　　　case WM_SYSDEADCHAR://处理系统键"死字符"消息
　　　　ShowKey (hwnd, 1, "WM_SYSDEADCHAR", wParam, lParam);
　　　　break;
　　　　case WM_DESTROY:
　　　　//处理结束应用程序的消息
　　　　PostQuitMessage (0);
　　　　return 0;
　　}
　　return DefWindowProc (hwnd, iMsg, wParam, lParam);
}
//函数：MyRegisterClass
//作用：注册窗口类
BOOL MyRegisterClass(HINSTANCE hInstance)
{
　　wnd.cbSize= sizeof (wnd);
　　wnd.style = CS_HREDRAW | CS_VREDRAW;
　　wnd.lpfnWndProc = WndProc;
　　wnd.cbClsExtra = 0;
　　wnd.cbWndExtra = 0;
　　wnd.hInstance = hInstance;
　　wnd.hIcon = LoadIcon (NULL, IDI_APPLICATION);?
　　wnd.hCursor = LoadCursor (NULL, IDC_ARROW);
　　wnd.hbrBackground = (HBRUSH)
　　GetStockObject (WHITE_BRUSH);
　　wnd.lpszMenuName = NULL;
　　wnd.lpszClassName = szAppName;
　　wnd.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
　　return RegisterClassEx (&wnd);
}
//函数：InitInstance
//作用：创建主窗口
BOOL InitInstance(HINSTANCE hInstance,int iCmdShow)
{
　　HWND hwnd;
　　hwnd = CreateWindow (szAppName,
　　　　　　　　　　　　 "键盘消息监视程序",
　　　　　　　　　　　　 WS_OVERLAPPEDWINDOW,
　　　　　　　　　　　　 CW_USEDEFAULT,CW_USEDEFAULT,
　　　　　　　　　　　　 CW_USEDEFAULT,CW_USEDEFAULT,
　　　　　　　　　　　　 NULL,NULL,hInstance,NULL
　　　　　　　　　　　　 );
　　if(!hwnd)
　　{
　　　　return FALSE;
　　}
　　ShowWindow (hwnd, iCmdShow);
　　UpdateWindow (hwnd);
　　return TRUE;
}