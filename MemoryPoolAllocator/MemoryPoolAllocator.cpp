#include "MemoryPoolAllocator.h"

MemoryPoolAllocator::MemoryPoolAllocator(size_t size) : memoryPool(size) 
{
    // メモリプール内の各ブロックの使用状況を初期化
    for (auto& block : memoryPool) {
        block.inUse = false;
    }
}

void* MemoryPoolAllocator::allocate()
{
    // 利用可能なメモリブロックを検索し、最初に見つかったものを割り当てる
    for (auto& block : memoryPool) {
        if (!block.inUse) {
            block.inUse = true;
            //内部確認のコメント
            std::cout << "Memory deallocated from: " << &block << ", inUse: " << block.inUse << std::endl;
            return &block;
        }
    }
    // 利用可能なブロックが見つからない場合は例外をスローする
    throw std::runtime_error("No available memory blocks in the pool.");
}

void MemoryPoolAllocator::deallocate(void* ptr)
{
    // 渡されたポインターに対応するメモリブロックを検索し、使用状況を解放状態に設定する
    for (auto& block : memoryPool) {
        if (&block == ptr) {
            block.inUse = false;
            // メモリブロックのデータを適切にリセットする必要がある場合はここで行う

            //内部確認のコメント
            std::cout << "Memory deallocated from: " << ptr << ", inUse: " << block.inUse << std::endl;
            break;
        }
    }
}
