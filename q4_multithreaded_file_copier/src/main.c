#include "multithreaded_copier.h"

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file> [num_threads]\n", argv[0]);
        return 1;
    }

    // Determine number of threads
    int num_threads = (argc == 4) ? atoi(argv[3]) : 0;

    // Perform multi-threaded file copy
    printf("Copying file using multi-threaded approach...\n");
    if (copy_file_multithreaded(argv[1], argv[2], num_threads) != 0) {
        fprintf(stderr, "File copying failed\n");
        return 1;
    }

    printf("File copied successfully!\n");
    return 0;
}
