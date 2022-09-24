#include <windows.h>
#include <assert.h>

#pragma comment(lib, "kernel32.lib");
#pragma comment(lib, "user32.lib");
#pragma comment(lib, "gdi32.lib");

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPCSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName = TEXT("My first app");
    static TCHAR szWindowName = TEXT("We Are Rocking Win32");

    WNDCLASSEX wndEx;

    HBRUSH hbrBackGround;
    HICON hIcon;
    HICON hIconSm;
    HCURSOR hCursor;

    hbrBackGround = 

}
