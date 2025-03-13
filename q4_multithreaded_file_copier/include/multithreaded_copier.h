#ifndef MULTITHREADED_COPIER_H
#define MULTITHREADED_COPIER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

// Thread argument structure
typedef struct {
    int source_fd;       // Source file descriptor
    int dest_fd;         // Destination file descriptor
    off_t offset;        // Starting offset in file
    size_t chunk_size;   // Size of chunk to copy
} thread_args;

// Function to copy file using multiple threads
int copy_file_multithreaded(const char *source_path, 
                             const char *dest_path, 
                             int num_threads);

// Thread function for copying file chunk
void *copy_chunk(void *arg);

// Determine optimal thread count
int determine_optimal_threads(off_t file_size);

#endif // MULTITHREADED_COPIER_H
