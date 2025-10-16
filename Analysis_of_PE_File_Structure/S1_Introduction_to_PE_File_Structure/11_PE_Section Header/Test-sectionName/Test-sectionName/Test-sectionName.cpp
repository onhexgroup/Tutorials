#include <windows.h>
#include <stdio.h>

#pragma section(".onhexgroup", read, write)
__declspec(allocate(".onhexgroup")) char my_data[] = "OnHexGroup\n";

int main() {
    printf("%s", my_data);
    return 0;
}
