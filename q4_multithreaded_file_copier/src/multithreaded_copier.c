#include "multithreaded_copier.h"

// Determine optimal thread count based on file size
int determine_optimal_threads(off_t file_size) {
    // Get number of CPU cores
    int num_cores = sysconf(_SC_NPROCESSORS_ONLN);
    
    // Base thread count on file size and CPU cores
    if (file_size < 1024 * 1024) return 1;  // Small files use single thread
    if (file_size < 1024 * 1024 * 10) return num_cores / 2;  // Medium files
    
    // Large files, but limit to reasonable thread count
    return (num_cores > 8) ? 8 : num_cores;
}

// Thread function to copy a chunk of the file
void *copy_chunk(void *arg) {
    thread_args *args = (thread_args *)arg;
    char *buffer = NULL;
    
    // Allocate buffer for chunk
    buffer = malloc(args->chunk_size);
    if (!buffer) {
        perror("Memory allocation failed");
        return NULL;
    }

    // Seek to correct position in source file
    if (lseek(args->source_fd, args->offset, SEEK_SET) == -1) {
        perror("Error seeking in source file");
        free(buffer);
        return NULL;
    }

    // Seek to correct position in destination file
    if (lseek(args->dest_fd, args->offset, SEEK_SET) == -1) {
        perror("Error seeking in destination file");
        free(buffer);
        return NULL;
    }

    // Read the chunk
    ssize_t bytes_read = read(args->source_fd, buffer, args->chunk_size);
    if (bytes_read == -1) {
        perror("Error reading source file");
        free(buffer);
        return NULL;
    }

    // Write the chunk
    ssize_t bytes_written = write(args->dest_fd, buffer, bytes_read);
    if (bytes_written != bytes_read) {
        perror("Error writing to destination file");
        free(buffer);
        return NULL;
    }

    // Cleanup
    free(buffer);
    return NULL;
}

// Main function to copy file using multiple threads
int copy_file_multithreaded(const char *source_path, 
                             const char *dest_path, 
                             int num_threads) {
    int source_fd, dest_fd;
    struct stat file_stat;
    pthread_t *threads = NULL;
    thread_args *thread_arguments = NULL;

    // Open source file
    source_fd = open(source_path, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return -1;
    }

    // Get file size
    if (fstat(source_fd, &file_stat) == -1) {
        perror("Error getting file size");
        close(source_fd);
        return -1;
    }
    off_t file_size = file_stat.st_size;

    // Determine optimal thread count if not specified
    if (num_threads <= 0) {
        num_threads = determine_optimal_threads(file_size);
    }

    // Open destination file
    dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd);
        return -1;
    }

    // Truncate destination file to source file size
    if (ftruncate(dest_fd, file_size) == -1) {
        perror("Error truncating destination file");
        close(source_fd);
        close(dest_fd);
        return -1;
    }

    // Calculate chunk size
    size_t chunk_size = file_size / num_threads;
    if (chunk_size == 0) chunk_size = file_size;

    // Allocate thread and argument arrays
    threads = malloc(num_threads * sizeof(pthread_t));
    thread_arguments = malloc(num_threads * sizeof(thread_args));
    if (!threads || !thread_arguments) {
        perror("Memory allocation failed");
        close(source_fd);
        close(dest_fd);
        free(threads);
        free(thread_arguments);
        return -1;
    }

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_arguments[i].source_fd = source_fd;
        thread_arguments[i].dest_fd = dest_fd;
        thread_arguments[i].offset = i * chunk_size;
        
        // Adjust last chunk size if needed
        if (i == num_threads - 1) {
            thread_arguments[i].chunk_size = file_size - (i * chunk_size);
        } else {
            thread_arguments[i].chunk_size = chunk_size;
        }

        // Create thread
        if (pthread_create(&threads[i], NULL, copy_chunk, &thread_arguments[i]) != 0) {
            perror("Failed to create thread");
            // Cleanup previous threads
            for (int j = 0; j < i; j++) {
                pthread_cancel(threads[j]);
            }
            close(source_fd);
            close(dest_fd);
            free(threads);
            free(thread_arguments);
            return -1;
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    close(source_fd);
    close(dest_fd);
    free(threads);
    free(thread_arguments);

    return 0;
}
