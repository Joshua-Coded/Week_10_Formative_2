#include "file_process_ops.h"

int main() {
    printf("Demonstrating File Operations:\n");
    if (perform_file_operations() != 0) {
        fprintf(stderr, "File operations failed\n");
        return 1;
    }

    printf("\nDemonstrating Process Operations:\n");
    if (perform_process_operations() != 0) {
        fprintf(stderr, "Process operations failed\n");
        return 1;
    }

    return 0;
}
