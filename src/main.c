#include <windows.h>

// window function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.lpszClassName = L"MinhaJanela";

    if (!RegisterClass(&wc)) {
        return 1;
    }

    // build window
    HWND hwnd = CreateWindow(L"MinhaJanela", L"Minha Aplicação", WS_OVERLAPPEDWINDOW, 100, 100, 400, 200, 0, 0, hInstance, 0);

    if (!hwnd) {
        return 2;
    }

    // build button
    HWND button = CreateWindow(L"BUTTON", L"Sair", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 150, 100, 80, 30, hwnd, (HMENU)1, hInstance, 0);

    if (!button) {
        return 3;
    }

    // build label with message
    CreateWindow(L"STATIC", L"Oi, eu estou no seu computador agora :D", WS_CHILD | WS_VISIBLE | SS_CENTER, 50, 30, 300, 40, hwnd, 0, hInstance, 0);

    ShowWindow(hwnd, nCmdShow);
    MSG msg;

    while (GetMessage(&msg, 0, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_COMMAND:
            if (LOWORD(wParam) == 1) {
                // press button to exit
                PostQuitMessage(0);
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
