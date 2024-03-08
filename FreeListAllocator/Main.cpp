#include <iostream>
#include "FreeList.h"

int main() {
    FreeListAllocator allocator;  //FreeListAllocatorのインスタンスを作成

    //メモリの割り当てと解放のテスト
    void* ptr1 = allocator.allocate(10);  //10バイトのメモリを割り当て
    std::cout << "Allocated memory at: " << ptr1 << std::endl;  //割り当てたメモリのポインタを出力
    allocator.deallocate(ptr1, 10);  //割り当てたメモリを解放
    std::cout << "Deallocated memory from: " << ptr1 << std::endl;  //解放したメモリのポインタを出力

    return 0;
}