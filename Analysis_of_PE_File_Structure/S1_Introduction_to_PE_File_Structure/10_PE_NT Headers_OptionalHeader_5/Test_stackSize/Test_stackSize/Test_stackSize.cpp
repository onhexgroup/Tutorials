//Check Stack size in PE File
#include <windows.h>
#include <stdio.h>

DWORD WINAPI ThreadFunc(LPVOID lpParam)
{
    MessageBoxA(NULL, "Hello from thread!", "Thread", MB_OK);
    return 0;
}

int main()
{
    DWORD threadId;

    SIZE_T stackSize = 2 * 1024 * 1024; // 2 MB

    HANDLE hThread = CreateThread(
        NULL,                    // lpThreadAttributes
        stackSize,              // dwStackSize  
        ThreadFunc,             // lpStartAddress
        NULL,                   // lpParameter
        STACK_SIZE_PARAM_IS_A_RESERVATION, // dwCreationFlags       
        &threadId               // lpThreadId
    );

    if (hThread == NULL)
    {
        printf("CreateThread failed. Error: %lu\n", GetLastError());
        return 1;
    }

    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    return 0;
}
