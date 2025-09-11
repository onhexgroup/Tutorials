#include <windows.h>

int main() {
    MessageBoxA(NULL, "Im Good boy", "MSG1", MB_OK | MB_ICONINFORMATION);
    MessageBoxA(NULL, "Im Bad boy", "MSG2", MB_OK | MB_ICONINFORMATION);
    return 0;
}
