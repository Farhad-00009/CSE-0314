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


        ///house

        drawLineDDA(100,320,430,320);
        drawLineDDA(100,320,100,280);
        drawLineDDA(100,300,10,370);
        drawLineDDA(10,370,340,400);
        drawLineDDA(430,320,340,400);
        drawLineDDA(60,372,60,600);
        drawLineDDA(340,400,340,650);
        drawLineDDA(340,650,430,650);
        drawLineDDA(60,600,340,650);
        drawLineDDA(430,650,580,680);
        drawLineDDA(430,320,430,650);
        drawLineDDA(430,610,580,640);
        drawLineDDA(580,640,1180,600);
        drawLineDDA(580,680,1180,630);
        drawLineDDA(580,680,580,208);
        drawLineDDA(600,220,1250,300);
        drawLineDDA(600,220,350,60);
        drawLineDDA(350,60,100,280);
        drawLineDDA(100,280,80,260);
        drawLineDDA(80,260,350,25);
        drawLineDDA(350,25,1160,180);
        drawLineDDA(1160,180,1250,300);
        drawLineDDA(1180,290,1180,630);
        drawLineDDA(770,105,770,15);
        drawLineDDA(770,15,782,3);
        drawLineDDA(782,3,860,3);
        drawLineDDA(782,3,782,108);
        drawLineDDA(860,121,860,3);
        drawLineDDA(0,420,60,420);
        drawLineDDA(1180,420,1400,420);
        drawLineDDA(365,650,365,430);
        drawLineDDA(405,650,405,430);
        drawLineDDA(365,430,405,430);
        drawLineDDA(160,430,250,430);
        drawLineDDA(160,430,160,530);
        drawLineDDA(160,530,250,530);
        drawLineDDA(250,430,250,530);
        drawLineDDA(300,150,400,150);
        drawLineDDA(300,230,400,230);
        drawLineDDA(300,150,300,230);
        drawLineDDA(400,150,400,230);
        drawLineDDA(680,330,780,330);
        drawLineDDA(680,330,680,480);
        drawLineDDA(780,330,780,480);
        drawLineDDA(680,480,780,480);
        drawLineDDA(960,360,1040,360);
        drawLineDDA(960,360,960,490);
        drawLineDDA(1040,360,1040,490);
        drawLineDDA(960,490,1040,490);

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
