#include <windows.h>

#include <cmath>

#define ROUND(a) ((int) (a + 0.5))

/* set window handle */

static HWND sHwnd;

static COLORREF redColor=RGB(255,0,0);

static COLORREF blueColor=RGB(0,0,255);

static COLORREF greenColor=RGB(0,255,0);


void SetWindowHandle(HWND hwnd) {

    sHwnd=hwnd;

}

/* SetPixel */

void setPixel(int x,int y,COLORREF& color=redColor) {

    if(sHwnd==NULL) {

        MessageBox(NULL,"sHwnd was not initialized !","Error",MB_OK|MB_ICONERROR);

        exit(0);

    }

    HDC hdc=GetDC(sHwnd);

    SetPixel(hdc,x,y,color);

    ReleaseDC(sHwnd,hdc);

    return;

// NEVERREACH //

}


void drawLineDDA(int xa, int ya, int xb, int yb) {

    int dx = xb - xa, dy = yb - ya, steps, k;

    float xIncrement, yIncrement, x = xa, y = ya;

    if(abs(dx) > abs(dy)) steps = abs(dx);

    else steps = abs(dy);

    xIncrement = dx / (float) steps;

    yIncrement = dy / (float) steps;

    setPixel(ROUND(x), ROUND(y));

    for(int k = 0; k < steps; k++) {

        x += xIncrement;

        y += yIncrement;

        setPixel(x, y);

    }

}

/* Window Procedure WndProc */

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam) {

    switch(message) {

    case WM_PAINT:

        SetWindowHandle(hwnd);
        /* /__ */
        drawLineDDA(96,20,21,116);
        drawLineDDA(20,117,118,116);
        /* \__ */
        drawLineDDA(132,24,176,113);
        drawLineDDA(176,113,257,114);
        /* |__ */
        drawLineDDA(284,15,284,115);
        drawLineDDA(284,117,367,115);
        /// acute trinlge
        drawLineDDA(385,116,477,116);
        drawLineDDA(477,116,433,18);
        drawLineDDA(433,18,386,117);
        /// right trianlge
        drawLineDDA(503,119,593,117);
        drawLineDDA(593,117,504,12);
        drawLineDDA(504,12,504,117);
        /// rectangle
        drawLineDDA(22,161,126,162);
        drawLineDDA(126,162,125,242);
        drawLineDDA(125,242,22,242);
        drawLineDDA(22,242,22,161);
        /// <>
        drawLineDDA(151,204,203,259);
        drawLineDDA(203,259,254,205);
        drawLineDDA(254,205,204,147);
        drawLineDDA(204,147,152,203);
        /// pentagon
        drawLineDDA(276,181,342,137);
        drawLineDDA(342,137,412,182);
        drawLineDDA(412,182,386,251);
        drawLineDDA(386,251,300,252);
        drawLineDDA(300,252,274,182);
        /// hexagon
        drawLineDDA(458,169,507,135);
        drawLineDDA(507,135,556,169);
        drawLineDDA(556,169,556,234);
        drawLineDDA(556,234,508,265);
        drawLineDDA(508,265,458,234);
        drawLineDDA(458,234,458,169);

        /// cube
        drawLineDDA(30,274,113,274);
        drawLineDDA(113,274,112,383);
        drawLineDDA(112,383,30,382);
        drawLineDDA(30,382,32,276);
        drawLineDDA(32,276,66,310);
        drawLineDDA(66,310,146,310);
        drawLineDDA(146,310,148,417);
        drawLineDDA(148,417,68,420);
        drawLineDDA(68,420,67,310);
        drawLineDDA(67,310,67,310);
        drawLineDDA(112,275,146,309);
        drawLineDDA(112,383,146,418);
        drawLineDDA(32,384,66,417);
        /// 4 star
        drawLineDDA(160,344,209,326);
        drawLineDDA(209,326,226,275);
        drawLineDDA(226,275,240,326);
        drawLineDDA(240,326,288,344);
        drawLineDDA(288,344,239,360);
        drawLineDDA(239,360,225,408);
        drawLineDDA(225,408,210,361);
        drawLineDDA(210,361,160,345);
        /// 5 star
        drawLineDDA(294,321,339,320);
        drawLineDDA(339,320,352,267);
        drawLineDDA(352,267,364,319);
        drawLineDDA(364,319,410,320);
        drawLineDDA(410,320,375,352);
        drawLineDDA(375,352,388,404);
        drawLineDDA(388,404,353,376);
        drawLineDDA(353,376,318,406);
        drawLineDDA(318,406,331,353);
        drawLineDDA(331,353,294,321);
        /// 6 star
        drawLineDDA(448,315,485,316);
        drawLineDDA(485,316,507,275);
        drawLineDDA(507,275,528,315);
        drawLineDDA(528,315,566,315);
        drawLineDDA(566,315,547,356);
        drawLineDDA(547,356,566,392);
        drawLineDDA(566,392,527,393);
        drawLineDDA(527,393,508,435);
        drawLineDDA(508,435,486,393);
        drawLineDDA(486,393,448,393);
        drawLineDDA(448,393,467,356);
        drawLineDDA(467,356,448,315);

        ///house

        drawLineDDA(640,110,792,17); ///upper
        drawLineDDA(792,17,941,109);
        drawLineDDA(941,109,641,110);

        drawLineDDA(673,109,673,380); /// body
        drawLineDDA(673,380,911,380);
        drawLineDDA(911,380,911,109);

        drawLineDDA(624,381,948,381); ///lower
        drawLineDDA(948,381,948,430);
        drawLineDDA(948,430,626,431);
        drawLineDDA(626,431,624,381);

        drawLineDDA(777,218,822,218); ///door
        drawLineDDA(822,218,822,381);
        drawLineDDA(822,381,777,381);
        drawLineDDA(777,381,777,218);


        drawLineDDA(693,213,738,213); ///left window
        drawLineDDA(738,213,738,281);
        drawLineDDA(738,281,693,281);
        drawLineDDA(693,281,693,213);

        drawLineDDA(849,213,892,213); /// right window
        drawLineDDA(892,213,892,281);
        drawLineDDA(892,281,850,281);
        drawLineDDA(850,281,849,213);

        break;

    case WM_CLOSE: // FAIL THROUGH to call DefWindowProc

        break;

    case WM_DESTROY:

        PostQuitMessage(0);

        return 0;

    default:

        break; // FAIL to call DefWindowProc //

    }

    return DefWindowProc(hwnd,message,wParam,lParam);

}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iCmdShow) {

    static TCHAR szAppName[] = TEXT("Straight Line");

    WNDCLASS wndclass;

    wndclass.style         = CS_HREDRAW|CS_VREDRAW ;

    wndclass.lpfnWndProc   = WndProc ;

    wndclass.cbClsExtra    = 0 ;

    wndclass.cbWndExtra    = 0 ;

    wndclass.hInstance     = hInstance ;

    wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;

    wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;

    wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;

    wndclass.lpszMenuName  = NULL ;

    wndclass.lpszClassName = szAppName ;

// Register the window //

    if(!RegisterClass(&wndclass)) {

        MessageBox(NULL,"Registering the class failled","Error",MB_OK|MB_ICONERROR);

        exit(0);

    }

// CreateWindow //

    HWND hwnd=CreateWindow(szAppName,"DDA - Programming Techniques",

                           WS_OVERLAPPEDWINDOW,

                           CW_USEDEFAULT,

                           CW_USEDEFAULT,

                           CW_USEDEFAULT,

                           CW_USEDEFAULT,

                           NULL,

                           NULL,

                           hInstance,

                           NULL);

    if(!hwnd) {

        MessageBox(NULL,"Window Creation Failed!","Error",MB_OK);

        exit(0);

    }

// ShowWindow and UpdateWindow //

    ShowWindow(hwnd,iCmdShow);

    UpdateWindow(hwnd);

// Message Loop //

    MSG msg;

    while(GetMessage(&msg,NULL,0,0)) {

        TranslateMessage(&msg);

        DispatchMessage(&msg);

    }

    /* return no error to the operating system */

    return 0;

}
