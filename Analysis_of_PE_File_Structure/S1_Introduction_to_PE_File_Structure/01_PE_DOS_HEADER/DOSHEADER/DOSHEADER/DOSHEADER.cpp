#include <iostream>
#include <fstream>
#include <stdio.h>
#include <Windows.h>

using namespace std;



int main() {
	// Open the executable file
	ifstream file("C:\\Users\\USER\\Desktop\\PE_1\\PE_Sample_32.exe", ios::binary);
	if (!file) {
		cerr << "Error opening file!" << endl;
		return 1;
	}

	// Read the DOS header
	IMAGE_DOS_HEADER dosHeader;
	file.read(reinterpret_cast<char*>(&dosHeader), sizeof(IMAGE_DOS_HEADER));
	file.close();

	// Access fields of dosHeader
	printf("e_magic: %x\ne_lfanew: %x", dosHeader.e_magic, dosHeader.e_lfanew);

	return 0;
}
