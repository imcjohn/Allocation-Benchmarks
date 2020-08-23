# Constant-Time (amortized) Malloc
### Overview
The purpose of this repository is to provide an example of how memory allocation can be optimized for performance-specific applications, without using the traditional technique of just only doing dynamic allocation at initialization time. It provides a simple benchmarking tool, as well as a couple of reference implementations of ways to allocate memory. If you'd like to provide your own implementation of the abstract class defined in MemoryAllocator.hpp, feel free to submit a pull request, as we'd love to have a variety of implementations!
### Some Results
#### Medium (1mb) chunk size
- SimpleMemoryAllocator -> 0.31 packets/us
- ConcurrentMemoryAllocator -> 0.78 packets/us
### File Descriptions
- main.cpp -> Benchmarking tool
- SimpleMemoryAllocator[.cpp/.hpp] -> Super-simple example of a memory allocator that just is a wrapper around new and delete, great for benchmarking implementations
- ConcurrentMemoryAllocator[.cpp/hpp] -> Example of using a dispatcher thread to handle the actual allocation, and populating queues. More effective than simple for loads >=512kb or so
- MemoryAllocator[.hpp] -> Abstract class/template for all future memory allocators