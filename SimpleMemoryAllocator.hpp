//
// Created by imcjohn on 8/23/20.
// Memory allocator for benchmarking more advance implementations, very simple
//

#include "MemoryAllocator.hpp"

#ifndef CONSTANT_MALLOC_SIMPLEMEMORYALLOCATOR_HPP
#define CONSTANT_MALLOC_SIMPLEMEMORYALLOCATOR_HPP


class SimpleMemoryAllocator: public MemoryAllocator {
public:
    bool free(memory_pkt *mem); /* free a memory packet */
    memory_pkt *alloc(); /* alloc a memory packet */
    bool run(); /* for implementations that use a dispatcher thread, start it */
    bool stop(); /* ^^, but stopping the thread */
};


#endif //CONSTANT_MALLOC_SIMPLEMEMORYALLOCATOR_HPP
