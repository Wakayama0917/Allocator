#include "MemoryPoolAllocator.h"


int main() {
    MemoryPoolAllocator allocator(10); // メモリプールのサイズを10とします

    // メモリの割り当てと解放のテスト
    void* ptr1 = allocator.allocate(); // メモリの割り当て
    if (ptr1) {
        
        // メモリの解放
        allocator.deallocate(ptr1); 
        
    }
    else {
        std::cout << "Failed to allocate memory." << std::endl;
    }

    return 0;
}