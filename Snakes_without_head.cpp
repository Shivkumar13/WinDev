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
 
    Point points[] = { Point(100, 50),
                  Point(150, 150),
                  Point(100, 250),
                  Point(150, 350),
                  Point(100, 450),
                  Point(150, 550)

    };

    Point points1[] = {Point(115, 50),
                 Point(165, 150),
                 Point(115, 250),
                 Point(165, 350),
                 Point(115, 450), 
                 Point(150, 550)
                 };

    //Snake Eye
    Point points2[] = { Point(100, 60),
               Point(100, 60),
               Point(100, 60),
               Point(100, 60),
               Point(100, 60)
    };
    
    
    Point points3[] = { Point(375, 175),
                        Point(400, 200),
                        Point(380, 280),
                        Point(450, 340),
                        Point(430, 420)

    };

    Point points4[] = { Point(385, 164),
                        Point(415, 200),
                        Point(395, 280),
                        Point(465, 340),
                        Point(430, 420)

    };
    

    Point points5[] = { Point(800, 120),
                        Point(750, 200),
                        Point(800, 280),
                        Point(750, 360),
                        Point(800, 440),
                        Point(750, 520),
                        Point(800, 600)
    };

    Point points6[] = { Point(815, 120),
                        Point(765, 200),
                        Point(810, 280),
                        Point(765, 360),
                        Point(810, 440),
                        Point(765, 520),
                        Point(800, 600)
    };
 
    Point points7[] = { Point(400, 400),
                        Point(350, 480),
                        Point(380, 500),
                        Point(290, 550),
                        Point(350, 600),
                        Point(270, 650),
    };

    Point points8[] = { Point(410, 400),
                        Point(360, 480),
                        Point(390, 500),
                        Point(300, 550),
                        Point(360, 600),
                        Point(270, 650),
    };

    
    Point points9[] = { Point(170, 300),
                        Point(220, 360),
                        Point(170, 390),
                        Point(220, 430),
                        Point(200, 450),
                        Point(270, 500),
    };

     Point points10[] = { Point(185, 300),
                        Point(235, 360),
                        Point(185, 390),
                        Point(235, 430),
                        Point(215, 450),
                        Point(270, 500),
    };

     Point points11[] = { Point(600, 350),
                        Point(540, 400),
                        Point(650, 450),
                        Point(540, 500),
                        Point(650, 550),
                        Point(500, 600),
    };

     Point points12[] = { Point(615, 350),
                        Point(555, 400),
                        Point(665, 450),
                        Point(555, 500),
                        Point(665, 550),
                        Point(500, 600),
    };



    Pen pen(Color(255, 0, 0, 255));
    // graphics.DrawCurve(&pen, points, 5, 0.0f); 
    // graphics.DrawCurve(&pen, points, 5, 0.06);
    // Snake Body
    graphics.DrawCurve(&pen, points, 6, 0.7f);
    graphics.DrawCurve(&pen, points1, 6, 0.7f);
    graphics.DrawCurve(&pen, points3, 5, 0.5f);
    graphics.DrawCurve(&pen, points4, 5, 0.8f);
    graphics.DrawCurve(&pen, points5, 7, 0.8f);
    graphics.DrawCurve(&pen, points6, 7, 0.8f);
    graphics.DrawCurve(&pen, points7, 6, 0.8f);
    graphics.DrawCurve(&pen, points8, 6, 0.8f);
    graphics.DrawCurve(&pen, points9, 6, 0.8f);
    graphics.DrawCurve(&pen, points10, 6, 0.8f);
    graphics.DrawCurve(&pen, points11, 6, 0.8f);
    graphics.DrawCurve(&pen, points12, 6, 0.8f);




    //Snake Eye
    graphics.DrawLine(&pen, 100, 40, 101, 44);

    graphics.DrawLine(&pen, 70, 50, 50, 55);
    graphics.DrawLine(&pen, 70, 50, 50, 40);
    graphics.DrawLine(&pen, 345, 176, 365, 168);
    graphics.DrawLine(&pen, 345, 168, 365, 168);
}

VOID DrawArc3(HDC hdc)
{
    Graphics graphics(hdc);

    // Set up the arc.
    Pen pen(Color(255, 0, 0, 255));
    REAL x = 750;
    REAL y = 120;
    REAL width = 30.0f;
    REAL height = 30.0f;
    REAL startAngle = 150.0f;
    REAL sweepAngle = 250.0f;

    // Draw the arc.
    graphics.DrawArc(&pen, x, y, width, height, startAngle, sweepAngle);

}


VOID DrawArc2(HDC hdc)
{
    Graphics graphics(hdc);

    // Set up the arc.
    Pen pen(Color(255, 0, 0, 255));
    REAL x = 360;
    REAL y = 162;
    REAL width = 38.0f;
    REAL height = 15.0f;
    REAL startAngle = 115.0f;
    REAL sweepAngle = 190.0f;

    // Draw the arc.
    graphics.DrawArc(&pen, x, y, width, height, startAngle, sweepAngle);

}



VOID DrawArc1(HDC hdc)
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
        // DrawArc1(hdc);
        DrawArc2(hdc);
        // DrawArc3(hdc);
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
