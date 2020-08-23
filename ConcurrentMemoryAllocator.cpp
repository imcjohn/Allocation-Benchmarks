//
// Created by imcjohn on 8/23/20.
//

#include "ConcurrentMemoryAllocator.hpp"

ConcurrentMemoryAllocator::ConcurrentMemoryAllocator(){
    alloc_queue = new boost::lockfree::queue<memory_pkt *>(QUEUE_SIZE);
    free_queue = new boost::lockfree::queue<memory_pkt *>(QUEUE_SIZE);
}

ConcurrentMemoryAllocator::~ConcurrentMemoryAllocator() {
    delete free_queue;
    delete alloc_queue;
}

bool ConcurrentMemoryAllocator::run(){
    done = false;
    dispatcher_threads.create_thread(boost::bind(&ConcurrentMemoryAllocator::alloc_dispatcher, this));
    return (alloc_queue) && (free_queue);
}

bool ConcurrentMemoryAllocator::stop(){
    done = true;
    dispatcher_threads.join_all();
    return true;
}

void ConcurrentMemoryAllocator::alloc_dispatcher(){
    while (!done){
        if (heap_size < PKT_BUFFER){
            memory_pkt *pkt = new memory_pkt;
            alloc_queue->push(pkt);
            // maybe memory barrier here?
            heap_size++;
        }
        memory_pkt *del;
        if (free_queue->pop(del))
            delete del;
    }
}

memory_pkt* ConcurrentMemoryAllocator::alloc() {
    memory_pkt *out;
    heap_size--;
    // maybe memory barrier here?
    alloc_queue->pop(out);
    return out;
}

bool ConcurrentMemoryAllocator::free(memory_pkt *mem) {
    return free_queue->push(mem);
}