#include <windows.h>
#include <gdiplus.h>
#include <gdiplusbrush.h>
#include <assert.h>
using namespace Gdiplus;

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "gdiplus.lib")

void draw(HDC hdc)
{
    Gdiplus::Graphics gf(hdc);
    Gdiplus::Pen pen(Gdiplus::Color(100, 100, 0, 0));
    Gdiplus::SolidBrush brush(Gdiplus::Color(255, 0, 255, 0));

    gf.DrawLine(&pen, 87, 67, 253, 355);

   //Gdiplus::Bitmap bmp(L"xyz.png");
    //gf.DrawImage(&bmp, 10, 50);
}

LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam);
void draw(HDC hdc);

int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, PSTR cmdLine, INT cmdCount) {
	// Initialize GDI+
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

	// Register the window class
    static TCHAR szClassName[] = TEXT("SHIV-SAN APP");
    static TCHAR szWindowName[] = TEXT("Snake And Ladder Game");


	WNDCLASS wc{};
	wc.hInstance = currentInstance;
	wc.lpszClassName = szClassName;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProcessMessages;
	RegisterClass(&wc);

	// Create the window
	CreateWindow(szClassName, szWindowName,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,            // Window style
		CW_USEDEFAULT, CW_USEDEFAULT,                // Window initial position
		1100, 1100,                                    // Window size
		nullptr, nullptr, nullptr, nullptr);

	// Window loop
	MSG msg{};
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Gdiplus::GdiplusShutdown(gdiplusToken);
	return 0;
}

LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam) {
	HDC hdc;
	PAINTSTRUCT ps;
	
    HBRUSH hBrush = NULL;
    hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);

    char* char_arr[10] = {"100", "99", "98", "97", "96", "95", "94", "93", "92", "91"};

    LPCSTR display_char = NULL;

	switch (msg) {
	case WM_PAINT:
    {
            int i, x = 0, y = 0, x2 = 75, y2 = 75;
            hdc = BeginPaint(hwnd, &ps);
            //draw(hdc);
            RECT rs;
            rs.bottom = 75;
            rs.left = 0;
            rs.right = 75;
            rs.top = 0;
         
            for(i = 0; i < 10; ++i)
            {  
           
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr[i], 3);

                //FillRect(hdc, &rs, hBrush);
               // DrawText(hdc, (LPCTSTR)char_arr[i], 3, &rs, 0);
                
                x += 75;
                x2 += 75;

            }
            
            char* char_arr1[10] = {"81", "82", "83", "84", "85", "86", "87", "88", "89", "90"};
            x = 0, y = 75, x2= 75, y2 = 150;

            for(i = 0; i < 10; ++i)
            {
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr1[i], 3);

                x += 75;
                x2 += 75;
            }


            char* char_arr2[10] = {"80", "79", "78", "77", "76", "75", "74", "73", "72", "71"};
            x = 0, y = 150, x2= 75, y2 = 225;
            for(i = 0; i < 10; ++i)
            {
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr2[i], 3);
                
                x += 75;
                x2 += 75;
            }

            char* char_arr3[10] = {"61", "62", "63", "64", "65", "66", "67", "68", "69", "70"};
            x = 0, y = 225, x2= 75, y2 = 300;
            for(i = 0; i < 10; ++i)
            {
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr3[i], 3);
                
                x += 75;
                x2 += 75;
            }

            char* char_arr4[10] = {"60", "59", "58", "57", "56", "55", "54", "53", "52", "51"};
            x = 0, y = 300, x2= 75, y2 = 375;
            for(i = 0; i < 10; ++i)
            {
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr4[i], 3);
                
                x += 75;
                x2 += 75;
            }

            char* char_arr5[10] = {"41", "42", "43", "44", "45", "46", "47", "48", "49", "50"};
            x = 0, y = 375, x2= 75, y2 = 450;
            for(i = 0; i < 10; ++i)
            {
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr5[i], 3);
                
                x += 75;
                x2 += 75;
            }

            char* char_arr6[10] = {"40", "39", "38", "37", "36", "35", "34", "33", "32", "31"};
            x = 0, y = 450, x2= 75, y2 = 525;
            for(i = 0; i < 10; ++i)
            {
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr6[i], 3);
                
                x += 75;
                x2 += 75;
            }

            char* char_arr7[10] = {"21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
            x = 0, y = 525, x2= 75, y2 = 600;
            for(i = 0; i < 10; ++i)
            {
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr7[i], 3);
                
                x += 75;
                x2 += 75;
            }

            char* char_arr8[10] = {"20", "19", "18", "17", "16", "15", "14", "13", "12", "11"};
            x = 0, y = 600, x2= 75, y2 = 675;
            for(i = 0; i < 10; ++i)
            {
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr8[i], 3);
                
                x += 75;
                x2 += 75;
            }

            char* char_arr9[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
            x = 0, y = 675, x2= 75, y2 = 750;
            for(i = 0; i < 10; ++i)
            {
                Rectangle(hdc, x, y, x2, y2);
                TextOut(hdc, x+10, y+10, (LPCSTR)char_arr9[i], 3);
                
                
                x += 75;
                x2 += 75;
            }
            draw(hdc);
            EndPaint(hwnd, &ps);
            return 0;
  
    }

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, param, lparam);
	}
 }


// void draw(HDC hdc) {
// 	Gdiplus::Graphics gf(hdc);
// 	Gdiplus::Pen pen(Gdiplus::Color(255, 255, 0, 0));               // For lines, rectangles and curves
// 	Gdiplus::SolidBrush brush(Gdiplus::Color(255, 0, 255, 0));      // For filled shapes

// 	gf.DrawLine(&pen, 0, 0, 500, 500);
// 	gf.FillRectangle(&brush, 320, 200, 100, 100);
// 	gf.DrawRectangle(&pen, 600, 400, 100, 150);

// 	Rectangle(hdc, 450, 500,  550, 450);

// 	Gdiplus::Bitmap bmp(L"water_small.png");
// 	gf.DrawImage(&bmp, 430, 10);

// 	gf.FillEllipse(&brush, 50, 400, 200, 100);`
// }

