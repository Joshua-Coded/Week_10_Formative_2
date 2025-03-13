# Question 2: Buffered vs Unbuffered File Copying

## Objective
Implement and compare two file copying methods: 
1. Buffered I/O using standard library functions
2. Unbuffered I/O using low-level system calls

## Technical Approach

### Buffered I/O Method
- Uses `fopen()`, `fread()`, `fwrite()`
- Leverages standard I/O stream buffering
- Managed by C standard library
- Efficient for most general file copying tasks

### Unbuffered I/O Method
- Uses `open()`, `read()`, `write()`
- Direct kernel-level file operations
- Minimal library-level buffering
- More direct control over I/O processes

## Performance Analysis
- Measure system call count using `strace`
- Compare execution time for both methods
- Analyze I/O efficiency and overhead

## Compilation
```bash
make
```

## Execution
```bash
# Usage: ./file_copy <source_file> <destination_file>
./file_copy input.txt output.txt
```

## Strace Analysis
Analyze system calls for each method:
```bash
strace ./file_copy input.txt output.txt
```

## Key Learning Points
- Understand differences between buffered and unbuffered I/O
- Compare performance characteristics
- Explore low-level file operation mechanisms
