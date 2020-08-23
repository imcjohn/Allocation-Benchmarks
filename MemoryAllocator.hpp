//
// Created by imcjohn on 8/23/20.
// Interface for MemoryAllocator types, to provide a common set of access functions for benchmarking
//

#ifndef CONSTANT_MALLOC_MEMORYALLOCATOR_HPP
#define CONSTANT_MALLOC_MEMORYALLOCATOR_HPP

#define MEMORY_SIZE 1000000

struct memory_pkt{
    char memory[MEMORY_SIZE];
    int sz;
};

class MemoryAllocator {
public:
    virtual bool free(memory_pkt *mem) = 0; /* free a memory packet */
    virtual memory_pkt *alloc()       = 0; /* alloc a memory packet */
    virtual bool run()                = 0; /* for implementations that use a dispatcher thread, start it */
    virtual bool stop()               = 0; /* ^^, but stopping the thread */
};

#endif //CONSTANT_MALLOC_MEMORYALLOCATOR_HPP
