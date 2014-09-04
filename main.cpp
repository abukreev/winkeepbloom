#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int main(int argc, _TCHAR* argv[])
{
    HMODULE dll = LoadLibrary("inject.dll");
    if(dll == NULL) {
        printf("The DLL could not be found.\n");
        return -1;
    }

    HOOKPROC addr = (HOOKPROC)GetProcAddress(dll, "meconnect");
    if(addr == NULL) {
        printf("The function was not found.\n");
        return -1;
    }
    HHOOK handle = SetWindowsHookEx(WH_SHELL, addr, dll, 0);
    
    if(handle != NULL) {
        printf("Program successfully hooked.\nPress enter to unhook the function and stop the program.\n");
        getchar();
    } else {
        printf("Could not be hooked.\n");
    }

    UnhookWindowsHookEx(handle);

    return 0;
}

