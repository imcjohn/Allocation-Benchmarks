//
// Created by imcjohn on 8/23/20.
// Memory allocator that uses a dispatcher thread for additional speed
//
#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/atomic.hpp>
#include "MemoryAllocator.hpp"

#ifndef CONSTANT_MALLOC_CONCURRENTMEMORYALLOCATOR_HPP
#define CONSTANT_MALLOC_CONCURRENTMEMORYALLOCATOR_HPP

#define PKT_BUFFER 4096
#define QUEUE_SIZE PKT_BUFFER * 2


class ConcurrentMemoryAllocator: public MemoryAllocator {
public:
    bool free(memory_pkt *mem); /* free a memory packet */
    memory_pkt *alloc(); /* alloc a memory packet */
    bool run(); /* for implementations that use a dispatcher thread, start it */
    bool stop(); /* ^^, but stopping the thread */
    ConcurrentMemoryAllocator();
    ~ConcurrentMemoryAllocator();
private:
    bool done;
    void alloc_dispatcher();
    boost::thread_group dispatcher_threads;
    boost::atomic_int heap_size;
    boost::lockfree::queue<memory_pkt *> *alloc_queue;
    boost::lockfree::queue<memory_pkt *> *free_queue;
};


#endif //CONSTANT_MALLOC_SIMPLEMEMORYALLOCATOR_HPP
