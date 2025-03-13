#ifndef FILE_COPY_METHODS_H
#define FILE_COPY_METHODS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>

// Buffered file copy using standard I/O
double buffered_copy(const char *src, const char *dest);

// Unbuffered file copy using low-level I/O
double unbuffered_copy(const char *src, const char *dest);

// Utility function to get current time
double get_current_time(void);

#endif // FILE_COPY_METHODS_H
