#include <iostream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "MemoryAllocator.hpp"
#include "SimpleMemoryAllocator.hpp"
#include "ConcurrentMemoryAllocator.hpp"

#define MAX_RUNS 100
#define ALLOCS_PER_RUN 1000

using namespace std;

inline int busy_wait(long long n){
    volatile int i = 67;
    while(n--){
        i = i + 55;
    }
    return i;
}

void run_tests(MemoryAllocator *m){
    cout << "Starting allocation tests..." << endl;
    long long allocs = 0;
    long long time = 0;
    for (int i = 0; i < MAX_RUNS; ++i){
        cout << "Starting Round " << i << endl;
        memory_pkt *arr[ALLOCS_PER_RUN];
        auto start = chrono::high_resolution_clock::now();

        for (auto & j : arr){
            j = m->alloc();
            j->memory[15] = 't';
        }

        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        cout << "Round " << i << " took " << microseconds << " microseconds" << endl;
        time += microseconds;
        allocs += ALLOCS_PER_RUN;

        this_thread::sleep_for(std::chrono::milliseconds (100));
        for (auto & j : arr){
            m->free(j);
        }
        this_thread::sleep_for(std::chrono::milliseconds (100));
    }
    long double frac = ((long double) allocs) / time;
    cout << "All rounds took " << time << " microseconds to allocate " << allocs << " packets, for an average of " << frac << " packets per us." << endl;
}

int main() {
    cout << "Benchmarks initializing" << endl;
    //MemoryAllocator *m = new ConcurrentMemoryAllocator();
    MemoryAllocator *m = new SimpleMemoryAllocator();
    m->run();
    sleep(5);
    run_tests(m);
    m->stop();
    delete m;
    return 0;
}
