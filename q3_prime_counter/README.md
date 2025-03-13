# Question 3: Multi-threaded Prime Number Counter

## Objective
Efficiently count prime numbers between 0 and 10,000 using 20 parallel threads.

## Implementation Details

### Parallel Processing Approach
- Divide range [0, 10,000] into 20 equal segments
- Each thread independently checks for primes in its assigned segment
- Use POSIX Threads (pthreads) for parallel computation

### Key Features
- Efficient prime number detection algorithm
- Thread-safe global prime number counting
- Minimal synchronization overhead
- Optimized for performance

## Algorithm Overview
1. Divide total range into 20 equal segments
2. Create 20 threads, each responsible for a segment
3. Each thread:
   - Checks primality of numbers in its segment
   - Maintains a local prime count
   - Safely updates global prime count

## Synchronization Mechanism
- Use mutex to protect global prime count
- Minimize lock contention
- Ensure thread-safe counting

## Compilation
```bash
make
```

## Execution
```bash
./prime_counter
```

## Expected Output
```
The total prime numbers from 0 to 10000 is <total>
```

## Performance Considerations
- Optimize prime checking algorithm
- Efficient thread workload distribution
- Minimal synchronization overhead

## Learning Objectives
- Understand multi-threading concepts
- Implement parallel computational algorithms
- Practice thread synchronization
- Optimize performance-critical code
