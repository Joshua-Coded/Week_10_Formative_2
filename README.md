# Systems Programming Assignment Solutions

## Overview
This project implements four distinct C programming challenges focusing on system-level programming, file operations, and multi-threading.

## Solution Architecture

### 1. File and Process Operations
#### Problem
Demonstrate fundamental system calls for file and process management.

#### Technical Solution
- Use low-level system calls: `open()`, `read()`, `write()`, `close()`
- Implement process creation and management with `fork()`, `exec()`, `wait()`
- Leverage system-level file descriptors for I/O operations

#### Key Implementation Techniques
- File descriptor manipulation
- Process forking and execution
- Error handling for system calls
- Comprehensive system call tracing

### 2. Buffered vs Unbuffered File Copying
#### Problem
Implement two file copying methods to compare performance and system call overhead.

#### Technical Solution
- Buffered I/O Method:
  - Use standard library functions: `fopen()`, `fread()`, `fwrite()`
  - Utilize memory buffering for efficient file reading/writing
  - Leverage standard I/O stream abstraction

- Unbuffered I/O Method:
  - Use low-level system calls: `open()`, `read()`, `write()`
  - Direct kernel-level file operations
  - Minimal memory buffering
  - Precise control over I/O operations

#### Performance Comparison
- Measure system call count using `strace`
- Compare execution time
- Analyze I/O efficiency and overhead

### 3. Multi-threaded Prime Number Counter
#### Problem
Efficiently count prime numbers using parallel processing.

#### Technical Solution
- Use POSIX Threads (pthreads) for parallel computation
- Divide number range [0, 10,000] into 20 equal segments
- Implement efficient prime number detection algorithm

#### Key Implementation Techniques
- Thread creation and management
- Range segmentation
- Synchronized global counting
- Mutex-based thread-safe operations

#### Prime Number Detection
- Optimize primality testing algorithm
- Minimize computational complexity
- Efficient parallel workload distribution

### 4. Multi-threaded File Copier
#### Problem
Develop a high-performance file copying mechanism using multiple threads.

#### Technical Solution
- Dynamically divide file into chunks
- Assign chunks to multiple threads
- Use `lseek()` for precise file positioning
- Implement thread-safe file writing

#### Advanced Implementation Features
- Dynamic thread count configuration
- Chunk-based parallel file processing
- Prevent data corruption
- Optimize thread resource utilization

## Compilation and Execution

### Prerequisites
- GCC Compiler
- POSIX Threads (pthread) Library
- Linux/UNIX Environment

### Compilation Instructions
```bash
# Navigate to project directory
cd project_root

# Compile all projects
make all

# Clean build artifacts
make clean
```

### Execution Examples

#### File and Process Operations
```bash
cd q1_file_process_ops
./file_process_ops
```

#### Buffered/Unbuffered File Copy
```bash
cd q2_file_copy
./file_copy source.txt destination.txt
```

#### Prime Number Counter
```bash
cd q3_prime_counter
./prime_counter
# Outputs total prime numbers from 0 to 10,000
```

#### Multi-threaded File Copier
```bash
cd q4_multithreaded_file_copier
./file_copier source.txt destination.txt 4
# Copies file using 4 threads
```

## Performance Analysis Tools
- `strace`: System call tracing
- `time`: Execution time measurement
- Custom timing and counting mechanisms

## Development Approach
- Modular code design
- Comprehensive error handling
- Optimize for performance and readability
- Leverage system-level programming techniques
