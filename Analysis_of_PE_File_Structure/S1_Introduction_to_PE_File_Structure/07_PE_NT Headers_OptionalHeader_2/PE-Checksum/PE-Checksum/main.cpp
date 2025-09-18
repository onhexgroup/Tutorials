#include <windows.h>
#include <imagehlp.h>
#include <iostream>


int main(int argc, char* argv[]) {

    const char* filePath = "C:\\Users\\USER\\Desktop\\PE_6\\PE_Sample_32.exe";
    DWORD headerChecksum = 0;
    DWORD computedChecksum = 0;

    LONG status = MapFileAndCheckSumA(filePath, &headerChecksum, &computedChecksum);

    if (status != CHECKSUM_SUCCESS) {
        std::cerr << "Error: MapFileAndCheckSumA failed. Code: " << status << std::endl;
        return 1;
    }

    std::cout << "File: " << filePath << std::endl;
    std::cout << "Header Checksum   : 0x" << std::hex << headerChecksum << std::endl;
    std::cout << "Computed Checksum : 0x" << std::hex << computedChecksum << std::endl;

    if (headerChecksum == computedChecksum) {
        std::cout << "Checksum is valid." << std::endl;
    }
    else {
        std::cout << "Checksum is invalid." << std::endl;
    }

    return 0;
}
