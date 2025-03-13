#include "prime_counter.h"

// Global variables
static int total_primes = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Efficient prime checking function
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    
    // Optimization: Check only up to square root of n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Thread function to count primes in a specific range
void *count_primes(void *arg) {
    thread_args *args = (thread_args *)arg;
    int local_primes = 0;

    // Count primes in the assigned range
    for (int num = args->start; num <= args->end; num++) {
        if (is_prime(num)) {
            local_primes++;
        }
    }

    // Safely update global prime count
    pthread_mutex_lock(&mutex);
    total_primes += local_primes;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Get total prime count (for potential external use)
int get_total_primes(void) {
    return total_primes;
}
