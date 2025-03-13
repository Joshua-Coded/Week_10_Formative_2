#include "file_copy_methods.h"

#define BUFFER_SIZE 4096

// Get current time with high precision
double get_current_time(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

// Buffered file copy using standard I/O
double buffered_copy(const char *src, const char *dest) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    double start_time, end_time;

    // Open source file
    source = fopen(src, "rb");
    if (source == NULL) {
        perror("Error opening source file (buffered)");
        return -1;
    }

    // Open destination file
    destination = fopen(dest, "wb");
    if (destination == NULL) {
        perror("Error opening destination file (buffered)");
        fclose(source);
        return -1;
    }

    // Start timing
    start_time = get_current_time();

    // Copy file using buffered I/O
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }

    // End timing
    end_time = get_current_time();

    // Close files
    fclose(source);
    fclose(destination);

    // Return execution time
    return end_time - start_time;
}

// Unbuffered file copy using low-level I/O
double unbuffered_copy(const char *src, const char *dest) {
    int source_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    double start_time, end_time;

    // Open source file
    source_fd = open(src, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file (unbuffered)");
        return -1;
    }

    // Open destination file
    dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file (unbuffered)");
        close(source_fd);
        return -1;
    }

    // Start timing
    start_time = get_current_time();

    // Copy file using unbuffered I/O
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            return -1;
        }
    }

    // End timing
    end_time = get_current_time();

    // Close file descriptors
    close(source_fd);
    close(dest_fd);

    // Return execution time
    return end_time - start_time;
}
