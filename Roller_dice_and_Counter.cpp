#include <Windows.h>
#include <CommCtrl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HMENU hMenu;



const int DICE_SIZE = 100;

void drawDice(HDC hdc, int x, int y)
{
    // Draw the outline of the dice
    Rectangle(hdc, x, y, x + DICE_SIZE, y + DICE_SIZE);

    // Draw the dots on the dice
    // You can use the Ellipse function to draw circles for the dots
    int dotRadius = DICE_SIZE / 10;
    Ellipse(hdc, x + DICE_SIZE / 3 - dotRadius, y + DICE_SIZE / 3 - dotRadius, x + DICE_SIZE / 3 + dotRadius, y + DICE_SIZE / 3 + dotRadius);
    Ellipse(hdc, x + 2 * DICE_SIZE / 3 - dotRadius, y + DICE_SIZE / 3 - dotRadius, x + 2 * DICE_SIZE / 3 + dotRadius, y + DICE_SIZE / 3 + dotRadius);
    Ellipse(hdc, x + DICE_SIZE / 3 - dotRadius, y + 2 * DICE_SIZE / 3 - dotRadius, x + DICE_SIZE / 3 + dotRadius, y + 2 * DICE_SIZE / 3 + dotRadius);
    Ellipse(hdc, x + 2 * DICE_SIZE / 3 - dotRadius, y + 2 * DICE_SIZE / 3 - dotRadius, x + 2 * DICE_SIZE / 3 + dotRadius, y + 2 * DICE_SIZE / 3 + dotRadius);
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("SHIV-SAN APP");
    static TCHAR szWindowName[] = TEXT("MY WINDOW"); 

    HWND hWnd = NULL;
    HBRUSH hBrush = NULL;
    HICON hIcon = NULL;
    HICON hIconSm = NULL; 
    HCURSOR hCursor = NULL;

    WNDCLASSEX wndEx;
    MSG msg;

    ZeroMemory(&wndEx, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
    assert(hBrush);

    hIcon = LoadIcon(NULL, IDI_APPLICATION);
    assert(hIcon);

    hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    assert(hIconSm);

    hCursor = LoadCursor(NULL, IDC_ARROW);
    assert(hCursor);

    wndEx.cbSize = sizeof(WNDCLASSEX);
    wndEx.cbClsExtra = 0;
    wndEx.hInstance = hInstance;
    wndEx.hbrBackground = hBrush;
    wndEx.hIcon = hIcon;
    wndEx.hIconSm = hIconSm;
    wndEx.hCursor = hCursor;
    wndEx.lpfnWndProc = WndProc;
    wndEx.lpszClassName = szClassName;
    wndEx.lpszMenuName = NULL;
    wndEx.style = CS_HREDRAW | CS_VREDRAW;

    ATOM bRet = RegisterClassEx(&wndEx);
    assert(bRet != NULL);

    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szWindowName,
                        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
                        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
                        NULL, NULL, hInstance, NULL);
    assert(hWnd);

    ShowWindow(hWnd, nShowCmd);
    UpdateWindow(hWnd);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch(uMsg)
    {
        case WM_CREATE:
         {
            // Create the button
            HWND hwndButton = CreateWindowEx(
                0, (LPCSTR)"BUTTON", (LPCSTR)"My Dice Roller", WS_CHILD | WS_VISIBLE,
                50, 50, 300, 50, hWnd, (HMENU)1, GetModuleHandle(NULL), NULL);

         }
            break;
            
         case WM_COMMAND:
            {
            // Check if the button was clicked
                if (LOWORD(wParam) == 1)
                    {
                        // Generate a random number between 1 and 6
                        int diceRoll = rand() % 6 + 1;

                        // Convert the number to a string
                        char buffer[10];
                       // _itow_s(diceRoll, buffer, 10);

                        // Set the window text to the number
                        sprintf(buffer,"%d", diceRoll);
                        SetWindowText(hWnd, LPCSTR(buffer));

                    }
            }
            break;

            case WM_PAINT:
                {
                    PAINTSTRUCT ps;
                    HDC hdc = BeginPaint(hWnd, &ps);

                        // Draw the dice at the center of the window
                    RECT rect;
                    GetClientRect(hWnd, &rect);
                    int x = (rect.right - rect.left - DICE_SIZE) / 2;
                    int y = (rect.bottom - rect.top - DICE_SIZE) / 2;

                    drawDice(hdc, x, y);

                    EndPaint(hWnd, &ps);
                    return 0;
                }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return(DefWindowProc(hWnd, uMsg, wParam, lParam));
}
