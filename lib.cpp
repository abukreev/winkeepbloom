#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <stdio.h>

extern "C" __declspec(dllexport)
int meconnect(int code, WPARAM wParam, LPARAM lParam) {
    FILE *file;
    file = fopen("C:\\function.txt", "a+");
    if (code != HSHELL_WINDOWACTIVATED) {
        HWND window = (HWND) wParam;

        const DWORD TITLE_SIZE = 1024;
        TCHAR title[TITLE_SIZE];
        if (GetWindowText(window, title, TITLE_SIZE)) {
            fprintf(file, "title = \"%s\"\n", title);
            if (strcmp(title, "Bloomberg - Session Timeout Warnig") == 0) {
                fprintf(file, "Title mathecs\n");
                HWND button = FindWindowEx(window, NULL, "Button", "&Yes");
                if (NULL != button) {
                    fprintf(file, "Sending messages\n");
                    SendMessage(button, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
                    SendMessage(button, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
                    fprintf(file, "Message sent\n");
                } else {
                    fprintf(file, "Can't find the button\n");
                }
            }
        }
    }
    fclose(file);
    return(CallNextHookEx(NULL, code, wParam, lParam));
}
