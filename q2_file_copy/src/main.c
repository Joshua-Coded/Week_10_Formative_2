#include "file_copy_methods.h"

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Perform buffered copy
    printf("Buffered Copy Method:\n");
    double buffered_time = buffered_copy(argv[1], "buffered_dest.txt");
    if (buffered_time < 0) {
        fprintf(stderr, "Buffered copy failed\n");
        return 1;
    }
    printf("Buffered copy time: %f seconds\n", buffered_time);

    // Perform unbuffered copy
    printf("\nUnbuffered Copy Method:\n");
    double unbuffered_time = unbuffered_copy(argv[1], "unbuffered_dest.txt");
    if (unbuffered_time < 0) {
        fprintf(stderr, "Unbuffered copy failed\n");
        return 1;
    }
    printf("Unbuffered copy time: %f seconds\n", unbuffered_time);

    return 0;
}
