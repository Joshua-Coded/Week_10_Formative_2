#include "file_process_ops.h"

#define BUFFER_SIZE 1024

int perform_file_operations(void) {
    int fd;
    char write_buffer[] = "Demonstrating file operations: Writing system calls!";
    char read_buffer[BUFFER_SIZE] = {0};
    ssize_t bytes_written, bytes_read;

    // Open file for writing
    fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file for writing");
        return 1;
    }

    // Write to file
    bytes_written = write(fd, write_buffer, sizeof(write_buffer));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }
    printf("Wrote %zd bytes to file\n", bytes_written);

    // Close file after writing
    if (close(fd) == -1) {
        perror("Error closing file after writing");
        return 1;
    }

    // Reopen file for reading
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        return 1;
    }

    // Read from file
    bytes_read = read(fd, read_buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }
    printf("Read %zd bytes from file: %s\n", bytes_read, read_buffer);

    // Close file after reading
    if (close(fd) == -1) {
        perror("Error closing file after reading");
        return 1;
    }

    return 0;
}

int perform_process_operations(void) {
    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d)\n", getpid());
        
        // Execute a system command
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);
        
        // If execvp fails
        perror("execvp");
        exit(1);
    } else {
        // Parent process
        printf("Parent process (PID: %d)\n", getpid());
        
        // Wait for child to finish
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
