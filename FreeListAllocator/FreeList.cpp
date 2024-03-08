#include "FreeList.h"

void* FreeListAllocator::allocate(size_t size)
{
    //フリーリストからサイズが適切なメモリブロックを探す
    for (auto& block : freeList) {
        if (block.size >= size) {
            void* ptr = block.ptr;  //メモリブロックのポインタを保存
            //フリーリストから割り当てたメモリブロックを削除
            freeList.erase(std::remove_if(freeList.begin(), freeList.end(),
                [ptr](const MemoryBlock& b) { return b.ptr == ptr; }),
                freeList.end());
            return ptr;  //メモリブロックのポインタを返す
        }
    }
    //フリーリストに適切なサイズのメモリブロックがない場合は新しく割り当てる
    return new char[size];
}

void FreeListAllocator::deallocate(void* ptr, size_t size)
{
    //解放したメモリブロックをフリーリストに追加
    freeList.push_back({ ptr, size });
}
