//
// Created by imcjohn on 8/23/20.
//

#include "SimpleMemoryAllocator.hpp"

bool SimpleMemoryAllocator::run(){
    return true;
}

bool SimpleMemoryAllocator::stop(){
    return true;
}

memory_pkt* SimpleMemoryAllocator::alloc() {
    return new memory_pkt;
}

bool SimpleMemoryAllocator::free(memory_pkt *mem) {
    delete mem;
    return true;
}