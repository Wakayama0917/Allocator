#pragma once
#include <vector>

class FreeListAllocator {
private:
    //�������u���b�N���Ǘ�����\����
    struct MemoryBlock {
        void* ptr;  //�|�C���^
        size_t size;  //�T�C�Y
    };

    std::vector<MemoryBlock> freeList;

public:
    FreeListAllocator() {}

    //�������̊��蓖��
    void* allocate(size_t size);

    //�������̉��
    void deallocate(void* ptr, size_t size);
};
