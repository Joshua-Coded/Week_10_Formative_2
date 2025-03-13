#ifndef PRIME_COUNTER_H
#define PRIME_COUNTER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// Constants
#define NUM_THREADS 20
#define MAX_NUMBER 10000

// Thread argument structure
typedef struct {
    int start;
    int end;
} thread_args;

// Function to check if a number is prime
bool is_prime(int n);

// Thread function to count primes in a specific range
void *count_primes(void *arg);

// Get total prime count
int get_total_primes(void);

#endif // PRIME_COUNTER_H
