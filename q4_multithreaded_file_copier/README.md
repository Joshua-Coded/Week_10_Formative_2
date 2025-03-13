# Question 4: Multi-threaded File Copier

## Objective
Implement an efficient multi-threaded file copying program that copies large files by dividing them into chunks processed in parallel.

## Technical Overview

### Key Features
- Parallel file copying using multiple threads
- Dynamic thread count configuration
- Efficient chunk-based file processing
- Precise file positioning with `lseek()`

### Performance Characteristics
- Minimize thread creation overhead
- Prevent data corruption
- Optimize I/O operations
- Support variable thread counts

## Thread Management
- Dynamically divide file into equal chunks
- Assign each chunk to a separate thread
- Handle last chunk separately if file size is not perfectly divisible
- Use `lseek()` for precise file positioning

## Compilation
```bash
make
```

## Execution
```bash
# Usage: ./file_copier <source_file> <destination_file> <number_of_threads>
./file_copier big.txt destination.txt 4
```

## Performance Analysis
- Compare file copying performance with:
  - Fewer threads
  - Average number of threads
  - Maximum possible threads
- Measure and analyze:
  - Execution time
  - System call overhead
  - CPU utilization

## Thread Optimization Strategies
- Avoid excessive thread creation
- Balance thread count with system resources
- Minimize synchronization overhead
- Ensure thread-safe file operations

## Error Handling
- Comprehensive error checking
- Graceful failure modes
- Informative error messages

## Learning Objectives
- Advanced multi-threading techniques
- File I/O performance optimization
- System-level programming challenges
- Parallel processing strategies
