# Question 1: File and Process Operations

## Objective
Demonstrate system calls for file and process operations, focusing on `open()`, `read()`, `write()`, `close()`, `fork()`, `exec()`, and `wait()`.

## Implementation Details
- Perform file operations (open, read, write, close)
- Create a child process using `fork()`
- Execute a system command using `exec()`
- Wait for child process completion

## System Calls Explored
### File Operations
- `open()`: Open a file with specified flags
- `read()`: Read data from a file descriptor
- `write()`: Write data to a file descriptor
- `close()`: Close a file descriptor

### Process Operations
- `fork()`: Create a new process
- `exec()`: Replace the current process image
- `wait()`: Wait for child process termination

## Strace Analysis
Use `strace` to trace and analyze system calls:
```bash
strace ./file_process_ops
```

## Compilation
```bash
make
```

## Execution
```bash
./file_process_ops
```

## Expected Behavior
- Demonstrate file I/O operations
- Create and manage a child process
- Execute a system command
- Show process interaction and system call usage
