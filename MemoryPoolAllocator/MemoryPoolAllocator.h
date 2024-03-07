#pragma once
#include <iostream>
#include <vector>

class MemoryPoolAllocator {
private:
    // メモリブロックを表す構造体
    struct MemoryBlock {
        bool inUse; // メモリブロックが使用中かどうかを示すフラグ
        // メモリブロックのデータを格納するための必要なデータをここに追加できます
    };

    std::vector<MemoryBlock> memoryPool; // メモリプールを管理するベクター

public:
    // コンストラクター
    MemoryPoolAllocator(size_t size);


    // メモリの割り当て
    void* allocate();

    // メモリの解放
    void deallocate(void* ptr);
};
