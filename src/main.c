#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = L"MinhaJanela";

    if (!RegisterClass(&wc)) {
        return 1;
    }

    HWND hwnd = CreateWindow(L"MinhaJanela", L"Minha Aplicação", WS_OVERLAPPEDWINDOW, 100, 100, 400, 200, nullptr, nullptr, hInstance, nullptr);

    if (!hwnd) {
        return 2;
    }

    HWND button = CreateWindow(L"BUTTON", L"Sair", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 150, 100, 80, 30, hwnd, (HMENU)1, hInstance, nullptr);

    if (!button) {
        return 3;
    }

    CreateWindow(L"STATIC", L"Oi, eu estou no seu computador agora :D", WS_CHILD | WS_VISIBLE | SS_CENTER, 50, 30, 300, 40, hwnd, nullptr, hInstance, nullptr);

    ShowWindow(hwnd, nCmdShow);
    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_COMMAND:
        if (LOWORD(wParam) == 1) {
            PostQuitMessage(0);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
