#pragma once
#include <vector>

class FreeListAllocator {
private:
    //メモリブロックを管理する構造体
    struct MemoryBlock {
        void* ptr;  //ポインタ
        size_t size;  //サイズ
    };

    std::vector<MemoryBlock> freeList;

public:
    FreeListAllocator() {}

    //メモリの割り当て
    void* allocate(size_t size);

    //メモリの解放
    void deallocate(void* ptr, size_t size);
};
