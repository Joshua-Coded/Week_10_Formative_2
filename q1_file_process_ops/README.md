# Question 1: System Calls Demonstration

## Objective
Explore and demonstrate low-level system calls for file and process management, providing insights into kernel-level interactions.

## System Call Performance Characteristics

### File I/O Operations
- **Overhead**: Direct system calls have minimal overhead compared to buffered I/O
- **Performance Factors**:
  - Disk I/O speed
  - File system type
  - Kernel optimization
- **Complexity**: O(1) for single read/write operations

### Process Management
- **fork() Performance**:
  - Copy-on-write mechanism reduces memory overhead
  - Typically takes microseconds to create a new process
- **exec() Performance**:
  - Replaces current process image
  - Overhead depends on executable size and complexity
- **Wait Performance**:
  - Minimal overhead for process synchronization

## Detailed System Call Analysis

### File Operations
1. `open()`
   - Creates file descriptor
   - Manages file access permissions
   - Time complexity: O(1)

2. `write()`
   - Transfers data from user space to kernel
   - Buffering depends on file system
   - Time complexity: O(1)

3. `read()`
   - Transfers data from kernel to user space
   - Caching can improve performance
   - Time complexity: O(1)

4. `close()`
   - Releases system resources
   - Flushes pending writes
   - Time complexity: O(1)

### Process Operations
1. `fork()`
   - Creates process copy
   - Uses copy-on-write for efficiency
   - Time complexity: O(1)

2. `exec()`
   - Replaces process image
   - Loads and initializes new program
   - Time complexity: Varies based on program

3. `wait()`
   - Synchronizes parent-child processes
   - Prevents zombie processes
   - Time complexity: O(1)

## Strace Analysis Recommendations
```bash
# Detailed system call tracing
strace -c ./file_process_ops

# Comprehensive call log
strace -f ./file_process_ops
```

### What to Observe in Strace
- Number of system calls
- Execution time of each call
- Kernel resources utilized
- Potential performance bottlenecks

## Compilation
```bash
make
```

## Execution
```bash
./file_process_ops
```

## Learning Outcomes
- Understand system call mechanics
- Explore process and file management
- Analyze low-level programming techniques
- Recognize kernel-user space interactions

## Best Practices
- Minimize system call frequency
- Handle errors gracefully
- Use appropriate flags and permissions
- Understand performance implications
