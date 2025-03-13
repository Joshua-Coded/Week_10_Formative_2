#include "file_process_ops.h"

#define BUFFER_SIZE 1024
#define FILE_PATH "example.txt"

/**
 * Centralized error handling function
 * 
 * @param operation Description of the operation that failed
 * @return Always returns 1 to indicate error
 */
int handle_error(const char* operation) {
    // Print detailed error message including system error description
    fprintf(stderr, "ERROR in %s: %s (Error number: %d)\n", 
            operation, strerror(errno), errno);
    return 1;
}

int perform_file_operations(void) {
    int fd;  // File descriptor for low-level file operations
    char write_buffer[] = "Demonstrating system calls: File I/O operations showcase!";
    char read_buffer[BUFFER_SIZE] = {0};  // Buffer to store read data
    ssize_t bytes_written, bytes_read;

    // SYSTEM CALL: open() - Create/Truncate file for writing
    // Flags explained:
    // O_WRONLY: Write-only access
    // O_CREAT: Create file if it doesn't exist
    // O_TRUNC: Truncate existing file to zero length
    // 0644: Permission mode (user read/write, others read-only)
    fd = open(FILE_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        return handle_error("open() for writing");
    }

    // SYSTEM CALL: write() - Write data to file
    // Writes entire buffer to file, returns bytes actually written
    bytes_written = write(fd, write_buffer, sizeof(write_buffer));
    if (bytes_written == -1) {
        close(fd);  // Ensure file descriptor is closed
        return handle_error("write()");
    }
    
    // Log successful write operation
    printf("Successful write: %zd bytes written to %s\n", 
           bytes_written, FILE_PATH);

    // SYSTEM CALL: close() - Release file descriptor
    if (close(fd) == -1) {
        return handle_error("close() after writing");
    }

    // SYSTEM CALL: open() - Reopen file for reading
    fd = open(FILE_PATH, O_RDONLY);
    if (fd == -1) {
        return handle_error("open() for reading");
    }

    // SYSTEM CALL: read() - Read file contents
    // Reads up to BUFFER_SIZE bytes, returns actual bytes read
    bytes_read = read(fd, read_buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        close(fd);  // Ensure file descriptor is closed
        return handle_error("read()");
    }

    // Log successful read operation
    printf("Successful read: %zd bytes read from %s\n", 
           bytes_read, FILE_PATH);
    printf("Read content: %s\n", read_buffer);

    // SYSTEM CALL: close() - Release file descriptor
    if (close(fd) == -1) {
        return handle_error("close() after reading");
    }

    return 0;
}

int perform_process_operations(void) {
    // SYSTEM CALL: fork() - Create new process
    // Returns:
    // - Negative: Fork failed
    // - Zero: In child process
    // - Positive: In parent process (contains child's PID)
    pid_t pid = fork();

    // Error checking for fork
    if (pid == -1) {
        return handle_error("fork()");
    }

    if (pid == 0) {
        // CHILD PROCESS CONTEXT
        printf("Child Process Execution:\n");
        printf("- Child Process PID: %d\n", getpid());
        printf("- Parent Process PID: %d\n", getppid());

        // SYSTEM CALL: execvp() - Replace process image
        // Searches executable in PATH
        // NULL-terminated argument list
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);

        // execvp() only returns on error
        return handle_error("execvp()");
    } else {
        // PARENT PROCESS CONTEXT
        printf("Parent Process Execution:\n");
        printf("- Parent Process PID: %d\n", getpid());
        printf("- Child Process PID: %d\n", pid);

        // SYSTEM CALL: waitpid() - Wait for child process
        // Suspends parent until child terminates
        int status;
        pid_t terminated_pid = waitpid(pid, &status, 0);

        if (terminated_pid == -1) {
            return handle_error("waitpid()");
        }

        // Analyze child process termination
        if (WIFEXITED(status)) {
            printf("Child process exited normally\n");
            printf("Exit status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process terminated by signal\n");
            printf("Terminating signal: %d\n", WTERMSIG(status));
        }
    }

    return 0;
}
