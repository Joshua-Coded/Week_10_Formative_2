#ifndef FILE_PROCESS_OPS_H
#define FILE_PROCESS_OPS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

// Perform file operations
int perform_file_operations(void);

// Perform process operations
int perform_process_operations(void);

#endif // FILE_PROCESS_OPS_H
