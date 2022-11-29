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

// ladder 57 to 82
// left line of ladder 
    gf.DrawLine(&pen, 100, 90, 253, 355);
// right line of ladder
    gf.DrawLine(&pen, 135, 80, 289, 340);
// first upper step of ladder
    gf.DrawLine(&pen, 110, 110, 150, 100);
    gf.DrawLine(&pen, 125, 135, 164, 124);
    gf.DrawLine(&pen, 142, 162, 180, 152);
    gf.DrawLine(&pen, 157, 190, 195, 180);
    gf.DrawLine(&pen, 172, 215, 213, 206);
    gf.DrawLine(&pen, 190, 243, 230, 234);
    gf.DrawLine(&pen, 203, 270, 245, 259);
    gf.DrawLine(&pen, 216, 300, 260, 287);
    gf.DrawLine(&pen, 238, 333, 275, 320);

// ladder 8 to 11
// left line of ladder
    gf.DrawLine(&pen, 540, 715, 680, 633);
// right line of ladder
    gf.DrawLine(&pen, 563, 725, 717, 642);
// firtst upper step of ladder
    gf.DrawLine(&pen, 575, 720, 550, 710);
    gf.DrawLine(&pen, 593, 708, 570, 700);
    gf.DrawLine(&pen, 616, 695, 587, 687);
    gf.DrawLine(&pen, 642, 684, 607, 674);
    gf.DrawLine(&pen, 668, 670, 635, 660);
    gf.DrawLine(&pen, 692, 656, 660, 645);

// ladder 72 to 94
// left line of ladder
    gf.DrawLine(&pen, 480, 60, 635, 210);
// right line of ladder
    gf.DrawLine(&pen, 510, 45, 665, 195);
// first upper step of ladder
    gf.DrawLine(&pen, 500, 75, 525, 60);
    gf.DrawLine(&pen, 515, 95, 544, 80);
    gf.DrawLine(&pen, 535, 114, 564, 100);
    gf.DrawLine(&pen, 555, 135, 584, 120);
    gf.DrawLine(&pen, 575, 150, 604, 140);
    gf.DrawLine(&pen, 595, 170, 624, 160);
    gf.DrawLine(&pen, 615, 190, 644, 180);


// ladder 1 to 38
// left line of ladder
    gf.DrawLine(&pen, 25, 700, 185, 470);
// right line of ladder
    gf.DrawLine(&pen, 53, 710, 212, 483);
// first upper step of ladder
    gf.DrawLine(&pen, 38, 680, 66, 690);
    gf.DrawLine(&pen, 51, 660, 79, 670);
    gf.DrawLine(&pen, 64, 640, 92, 650);
    gf.DrawLine(&pen, 79, 620, 108, 630);
    gf.DrawLine(&pen, 94, 600, 123, 610);
    gf.DrawLine(&pen, 108, 580, 138, 590);
    gf.DrawLine(&pen, 124, 560, 153, 570);
    gf.DrawLine(&pen, 137, 540, 168, 550);
    gf.DrawLine(&pen, 150, 520, 180, 527);
    gf.DrawLine(&pen, 163, 500, 195, 510);

// ladder 28 to 76
// left line of ladder
    gf.DrawLine(&pen, 320, 195, 540, 575);
// right line of ladder
    gf.DrawLine(&pen, 360, 190, 580, 570);
// first upper step of ladder
    gf.DrawLine(&pen, 329, 213, 370, 212);
    gf.DrawLine(&pen, 342, 235, 384, 235);
    gf.DrawLine(&pen, 355, 257, 399, 258);
    gf.DrawLine(&pen, 368, 280, 410, 281);
    gf.DrawLine(&pen, 381, 303, 420, 300);
    gf.DrawLine(&pen, 394, 326, 432, 320);
    gf.DrawLine(&pen, 409, 349, 445, 343);
    gf.DrawLine(&pen, 422, 373, 460, 366);
    gf.DrawLine(&pen, 435, 396, 475, 389);
    gf.DrawLine(&pen, 448, 419, 490, 412);
    gf.DrawLine(&pen, 461, 442, 505, 436);
    gf.DrawLine(&pen, 474, 465, 518, 460);
    gf.DrawLine(&pen, 489, 489, 531, 484);
    gf.DrawLine(&pen, 502, 514, 546, 508);
    gf.DrawLine(&pen, 515, 537, 559, 532);
    gf.DrawLine(&pen, 528, 560, 575, 556);


// ladder 17 to 36
// left line of ladder
    gf.DrawLine(&pen, 250, 640, 330 ,480);
// right line of ladder
    gf.DrawLine(&pen, 280, 645, 360 ,485);
// first upper step of ladder
    gf.DrawLine(&pen, 255, 630, 285 ,635);
    gf.DrawLine(&pen, 264, 613, 294 ,618);
    gf.DrawLine(&pen, 273, 596, 303 ,601);
    gf.DrawLine(&pen, 282, 579, 312 ,584);
    gf.DrawLine(&pen, 291, 562, 321 ,567);
    gf.DrawLine(&pen, 298, 545, 330 ,550);
    gf.DrawLine(&pen, 307, 528, 339 ,533);
    gf.DrawLine(&pen, 316, 511, 348 ,516);
    gf.DrawLine(&pen, 325, 494, 357 ,499);

   //Gdiplus::Bitmap bmp(L"xyz.png");
    //gf.DrawImage(&bmp, 10, 50);
}

LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam);
void draw(HDC hdc);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

	// Register the window class
    static TCHAR szClassName[] = TEXT("SHIV-SAN APP");
    static TCHAR szWindowName[] = TEXT("Snake And Ladder Game");

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
    wndEx.lpfnWndProc = WindowProcessMessages; 
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
    Gdiplus::GdiplusShutdown(gdiplusToken);
    return (msg.wParam); 
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


