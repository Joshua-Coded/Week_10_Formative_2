#include "prime_counter.h"

int main() {
    pthread_t threads[NUM_THREADS];
    thread_args thread_arguments[NUM_THREADS];

    // Divide the range into equal segments
    int range_per_thread = (MAX_NUMBER + 1) / NUM_THREADS;

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_arguments[i].start = i * range_per_thread;
        
        // Last thread handles any remaining numbers
        if (i == NUM_THREADS - 1) {
            thread_arguments[i].end = MAX_NUMBER;
        } else {
            thread_arguments[i].end = (i + 1) * range_per_thread - 1;
        }

        // Create thread
        if (pthread_create(&threads[i], NULL, count_primes, &thread_arguments[i]) != 0) {
            perror("Failed to create thread");
            exit(1);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(1);
        }
    }

    // Print total number of primes
    printf("The total prime numbers from 0 to %d is %d\n", MAX_NUMBER, get_total_primes());

    // Cleanup
    pthread_mutex_destroy(&mutex);

    return 0;
}
