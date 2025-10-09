//Test Heap in PE File
#include <windows.h>
#include <iostream>

int main() {
    std::cout << "Program started...\n";

   
    SIZE_T reserveSize = 0x200000;  // 2MB
    SIZE_T commitSize = 0x3000;    // 12KB

    HANDLE myHeap = HeapCreate(0, commitSize, reserveSize);
    if (!myHeap) {
        std::cerr << "HeapCreate failed!\n";
        return 1;
    }

    std::cout << "Heap created at: " << myHeap << "\n";

   
    void* mem = HeapAlloc(myHeap, 0, 4096);  // 4KB
    if (!mem) {
        std::cerr << "HeapAlloc failed!\n";
        return 1;
    }

    std::cout << "Memory allocated at: " << mem << "\n";

    HANDLE defaultHeap = GetProcessHeap();
    std::cout << "Default Heap: " << defaultHeap << "\n";

 
    std::cout << "Press Enter to exit...\n";
    std::cin.get();


    HeapFree(myHeap, 0, mem);
    HeapDestroy(myHeap);

    return 0;
}
