#ifndef FILE_PROCESS_OPS_H
#define FILE_PROCESS_OPS_H

#include <stdio.h>      // Standard input/output operations
#include <stdlib.h>     // Standard library functions (exit, etc.)
#include <string.h>     // String manipulation and strerror()
#include <unistd.h>     // POSIX operating system API (fork, exec)
#include <fcntl.h>      // File control options (open flags)
#include <sys/wait.h>   // Waiting for process termination
#include <errno.h>      // Error number definitions

/**
 * Performs file I/O operations demonstrating low-level system calls
 * 
 * @return 0 on success, 1 on failure
 * @note Demonstrates open(), write(), read(), and close() system calls
 */
int perform_file_operations(void);

/**
 * Performs process management operations demonstrating fork, exec, and wait
 * 
 * @return 0 on success, 1 on failure
 * @note Demonstrates fork(), execvp(), and waitpid() system calls
 */
int perform_process_operations(void);

/**
 * Error handling utility to provide detailed error information
 * 
 * @param operation Description of the operation that failed
 * @return Always returns 1 to indicate error
 */
int handle_error(const char* operation);

#endif // FILE_PROCESS_OPS_H
