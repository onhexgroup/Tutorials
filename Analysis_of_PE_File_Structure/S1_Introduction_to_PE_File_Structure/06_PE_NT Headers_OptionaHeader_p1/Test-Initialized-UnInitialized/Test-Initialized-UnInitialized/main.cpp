#include <stdio.h>

// Global Uninitialized Data (BSS)
int g_uninitialized_int;
long g_uninitialized_long_array[5];
static unsigned char large_bss_array[1024];

int main() {
    printf("PE Data Understanding Example (Runtime Changes):\n");
    printf("--------------------------------------------------\n");

    printf("Initial g_uninitialized_int: %d (Addr: %p)\n", g_uninitialized_int, &g_uninitialized_int);
    printf("Initial large_bss_array[0]: %d (Addr: %p)\n", large_bss_array[0], &large_bss_array[0]);

    // --- PAUSE HERE AND OBSERVE BSS IN X64DBG ---
    // (You can set a breakpoint on the next line or after the printf)

    // Modify some BSS variables
    g_uninitialized_int = 0x100;
    g_uninitialized_long_array[2] = 0x54321;
    large_bss_array[0] = 0x255;
    large_bss_array[1] = 0x127;
    large_bss_array[100] = 'X';

    // --- PAUSE HERE AGAIN AND OBSERVE BSS IN X64DBG ---
    // (Set another breakpoint here)

    // Print modified values
    printf("\nModified g_uninitialized_int: %x (Addr: %p)\n", g_uninitialized_int, &g_uninitialized_int);
    printf("Modified g_uninitialized_long_array[2]: %lx (Addr: %p)\n", g_uninitialized_long_array[2], &g_uninitialized_long_array[2]);
    printf("Modified large_bss_array[0]: %x (Addr: %p)\n", large_bss_array[0], &large_bss_array[0]);
    printf("Modified large_bss_array[1]: %x (Addr: %p)\n", large_bss_array[1], &large_bss_array[1]);
    printf("Modified large_bss_array[100]: %c (Addr: %p)\n", large_bss_array[100], &large_bss_array[100]);


    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}