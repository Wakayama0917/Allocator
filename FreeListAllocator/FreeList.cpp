#include "FreeList.h"

void* FreeListAllocator::allocate(size_t size)
{
    //�t���[���X�g����T�C�Y���K�؂ȃ������u���b�N��T��
    for (auto& block : freeList) {
        if (block.size >= size) {
            void* ptr = block.ptr;  //�������u���b�N�̃|�C���^��ۑ�
            //�t���[���X�g���犄�蓖�Ă��������u���b�N���폜
            freeList.erase(std::remove_if(freeList.begin(), freeList.end(),
                [ptr](const MemoryBlock& b) { return b.ptr == ptr; }),
                freeList.end());
            return ptr;  //�������u���b�N�̃|�C���^��Ԃ�
        }
    }
    //�t���[���X�g�ɓK�؂ȃT�C�Y�̃������u���b�N���Ȃ��ꍇ�͐V�������蓖�Ă�
    return new char[size];
}

void FreeListAllocator::deallocate(void* ptr, size_t size)
{
    //��������������u���b�N���t���[���X�g�ɒǉ�
    freeList.push_back({ ptr, size });
}
