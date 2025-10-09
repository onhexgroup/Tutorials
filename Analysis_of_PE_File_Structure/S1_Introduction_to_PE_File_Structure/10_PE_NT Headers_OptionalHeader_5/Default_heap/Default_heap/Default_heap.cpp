//Check Default Process Heap
#include <windows.h>
#include <iostream>

int main() {
    std::cout << "Program started...\n";

    
    HANDLE defaultHeap = GetProcessHeap();
    if (!defaultHeap) {
        std::cerr << "GetProcessHeap failed!\n";
        return 1;
    }

    std::cout << "Default process heap handle: " << defaultHeap << "\n";

    
    void* mem = HeapAlloc(defaultHeap, 0, 4096);
    if (!mem) {
        std::cerr << "HeapAlloc failed!\n";
        return 1;
    }

    std::cout << "Memory allocated at: " << mem << "\n";

    std::cout << "Press Enter to exit...\n";
    std::cin.get();

    
    HeapFree(defaultHeap, 0, mem);

    return 0;
}
