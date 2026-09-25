#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <MMsystem.h>
#include <unistd.h>
#include <conio.h>

#define EasyStartUp 1
#define MultiStartUp 2
#define MediumStartUp 3
#define HardStartUp 4

HBITMAP hLogo, hSinglePlayerEasy, hSinglePlayerMedium, hSinglePlayerHard, hTwoPlayers, hbackground, hintro1, hintro2, hintro3, hintro4;
HMENU hMenu;
HWND hLogoHandler;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

    switch (msg) {
    case WM_COMMAND:
        switch (wp) {
        case EasyStartUp:
            system("bin\\Debug\\easyyyyyyy.exe");
            break;
        case HardStartUp:
            system("\"bin\\Debug\\play game hard.exe\"");
            break;
        case MultiStartUp:
            system("bin\\Debug\\twoplayers.exe");
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_CREATE:
        loadimages();
        AddControls(hWnd);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

void AddControls(HWND hWnd) {
    HWND hback = CreateWindowW(L"static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 0, 1000, 1000, hWnd, NULL, NULL, NULL);
    SendMessageW(hback, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbackground);

    HWND hButton1 = CreateWindowW(L"Button", NULL, WS_VISIBLE | WS_CHILD | BS_BITMAP | SS_LEFT, 120, 400, 375, 75, hWnd, (HMENU)EasyStartUp, NULL, NULL);
    SendMessageW(hButton1, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hSinglePlayerEasy);

    HWND hButton3 = CreateWindowW(L"Button", NULL, WS_VISIBLE | WS_CHILD | BS_BITMAP | SS_LEFT, 500, 400, 375, 75, hWnd, (HMENU)HardStartUp, NULL, NULL);
    SendMessageW(hButton3, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hSinglePlayerHard);

    HWND hButton4 = CreateWindowW(L"Button", NULL, WS_VISIBLE | WS_CHILD | BS_BITMAP | SS_LEFT, 125, 600, 750, 150, hWnd, (HMENU)MultiStartUp, NULL, NULL);
    SendMessageW(hButton4, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hTwoPlayers);
}

void loadimages() {
    hSinglePlayerEasy = (HBITMAP)LoadImageW(NULL, L"Delivering the Fu0000ture44.bmp", IMAGE_BITMAP, 375, 75, LR_LOADFROMFILE);
    hSinglePlayerHard = (HBITMAP)LoadImageW(NULL, L"Delivering t77he00000 Future.bmp", IMAGE_BITMAP, 375, 75, LR_LOADFROMFILE);
    hTwoPlayers = (HBITMAP)LoadImageW(NULL, L"Delivering the Fut00000000000000ure.bmp", IMAGE_BITMAP, 750, 150, LR_LOADFROMFILE);
    hbackground = (HBITMAP)LoadImageW(NULL, L"1.bmp", IMAGE_BITMAP, 1000, 1000, LR_LOADFROMFILE);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

    WNDCLASSW wc = { 0 };
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"TicTacToe";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) {
        return -1;
    }

    CreateWindowW(L"TicTacToe", L"Tic Tac Toe", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 460, 0, 1000, 1000, NULL, NULL, NULL, NULL);

    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
