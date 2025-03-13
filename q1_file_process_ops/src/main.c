#include "file_process_ops.h"

int main() {
    printf("System Calls Demonstration Program\n");
    printf("==================================\n");

    // Demonstrate File Operations
    printf("\n[FILE OPERATIONS DEMONSTRATION]\n");
    if (perform_file_operations() != 0) {
        fprintf(stderr, "File operations demonstration failed\n");
        return EXIT_FAILURE;
    }

    // Demonstrate Process Operations
    printf("\n[PROCESS OPERATIONS DEMONSTRATION]\n");
    if (perform_process_operations() != 0) {
        fprintf(stderr, "Process operations demonstration failed\n");
        return EXIT_FAILURE;
    }

    printf("\nSystem Calls Demonstration Completed Successfully\n");
    return EXIT_SUCCESS;
}
