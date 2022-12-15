#include <Windows.h> 
#include <assert.h> 
#include <objidl.h>
#include <gdiplus.h>
#include <gdiplusgraphics.h>

using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "gdi32.lib") 
#pragma comment(lib, "user32.lib")


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

static RECT rcTarget;


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 




VOID OnPaint(HDC hdc)
{
    Graphics graphics(hdc);

    //Snake Body
    
    Point points[] = { Point(100, 57),
                  Point(200, 100),
                  Point(300, 55),
                  Point(400, 120),
                  Point(500, 85),
                  Point(580, 150)
    };
    

    Point points1[] = {Point(105, 35),
                 Point(210, 90),
                 Point(310, 45),
                 Point(410, 105),
                 Point(510, 75),
                 Point(580, 150)
    };


    //snake eye
    Point points2[] = { Point(100, 60),
               Point(100, 60),
               Point(100, 60),
               Point(100, 60),
               Point(100, 60)
    };

  

    Point points3[] = { Point(360, 160),
                        Point(400, 200),
                        Point(400, 280),
                        Point(460, 340),
                        Point(530, 390)

    };

    Point points4[] = { Point(610, 192),
                        Point(730, 190),
                        Point(410, 270),
                        Point(470, 330),
                        Point(530, 390)

    };
 

    Pen pen(Color(255, 0, 0, 255));
    graphics.DrawCurve(&pen, points, 5, 0.0f); 
    graphics.DrawCurve(&pen, points1, 5, 0.06);
    graphics.DrawCurve(&pen, points2, 5, 0.06);

    //Snake Body
    graphics.DrawCurve(&pen, points3, 5, 0.5f);
    graphics.DrawCurve(&pen, points4, 5, 1.0f);

    //Snake Eye
    graphics.DrawLine(&pen, 100, 40, 101, 44);

    graphics.DrawLine(&pen, 70, 50, 50, 55);
    graphics.DrawLine(&pen, 70, 50, 50, 40);

    //graphics.DrawLine(&pen, 100, 39, 101, 44);

    //graphics.DrawLine(&pen, points2, 6, 0.5f);
}



VOID DrawArc(HDC hdc)
{
    Graphics graphics(hdc);

    // Set up the arc.
    Pen pen(Color(255, 0, 0, 255));
    REAL x = 65;
    REAL y = 37;
    REAL width = 80.0f;
    REAL height = 20.0f;
    REAL startAngle = 115.0f;
    REAL sweepAngle = 190.0f;

    // Draw the arc.
    graphics.DrawArc(&pen, x, y, width, height, startAngle, sweepAngle);
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window"); 
    static TCHAR szWindowName[] = TEXT("Sangameshwar window!");    

    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;

    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);


    HWND hWnd = NULL; 
    HBRUSH hBrush = NULL; 
    HCURSOR hCursor = NULL; 
    HICON hIcon = NULL; 
    HICON hIconSm = NULL; 

    WNDCLASSEX wndEx; 
    MSG msg; 

    ZeroMemory(&wndEx, sizeof(WNDCLASSEX)); 
    ZeroMemory(&msg, sizeof(MSG)); 

    hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    assert(hBrush); 

    hCursor = LoadCursor(NULL, IDC_ARROW); 
    assert(hCursor); 
 
    hIcon = LoadIcon(NULL, IDI_APPLICATION); 
    assert(hIcon); 

    hIconSm = LoadIcon(NULL, IDI_APPLICATION); 
    assert(hIconSm); 

    wndEx.cbSize = sizeof(WNDCLASSEX); 
    wndEx.cbClsExtra = 0; 
    wndEx.cbWndExtra = 0; 
    wndEx.hbrBackground = hBrush; 
    wndEx.hCursor = hCursor; 
    wndEx.hIcon = hIcon; 
    wndEx.hIconSm = hIconSm; 
    wndEx.hInstance = hInstance; 
    wndEx.lpfnWndProc = WndProc; 
    wndEx.lpszClassName = szClassName; 
    wndEx.lpszMenuName = NULL; 
    wndEx.style = CS_HREDRAW | CS_VREDRAW; 

    ATOM bRet = RegisterClassEx(&wndEx); 
    assert(bRet); 
    
    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szWindowName, 
                            WS_OVERLAPPED | WS_THICKFRAME | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 
                            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                            NULL, NULL, hInstance, NULL); 
    assert(hWnd != NULL); 

    ShowWindow(hWnd, nShowCmd); 
    UpdateWindow(hWnd);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
        // -> Operating. wndEx.lpfnWndProc(lpMsg->hWnd, lpMsg->uMsg, lpMsg->wParam, lpMsg->lParam); 
    }

    return (msg.wParam); 
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case 104:
            DialogBox(hInst, MAKEINTRESOURCE(103), hWnd, About);
            break;
        case 105:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        OnPaint(hdc);
        DrawArc(hdc);
        Ellipse(ps.hdc, rcTarget.left, rcTarget.top,
            rcTarget.right, rcTarget.bottom);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}



