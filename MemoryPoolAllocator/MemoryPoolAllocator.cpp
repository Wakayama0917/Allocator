#include "MemoryPoolAllocator.h"

MemoryPoolAllocator::MemoryPoolAllocator(size_t size) : memoryPool(size) 
{
    // �������v�[�����̊e�u���b�N�̎g�p�󋵂�������
    for (auto& block : memoryPool) {
        block.inUse = false;
    }
}

void* MemoryPoolAllocator::allocate()
{
    // ���p�\�ȃ������u���b�N���������A�ŏ��Ɍ����������̂����蓖�Ă�
    for (auto& block : memoryPool) {
        if (!block.inUse) {
            block.inUse = true;
            //�����m�F�̃R�����g
            std::cout << "Memory deallocated from: " << &block << ", inUse: " << block.inUse << std::endl;
            return &block;
        }
    }
    // ���p�\�ȃu���b�N��������Ȃ��ꍇ�͗�O���X���[����
    throw std::runtime_error("No available memory blocks in the pool.");
}

void MemoryPoolAllocator::deallocate(void* ptr)
{
    // �n���ꂽ�|�C���^�[�ɑΉ����郁�����u���b�N���������A�g�p�󋵂������Ԃɐݒ肷��
    for (auto& block : memoryPool) {
        if (&block == ptr) {
            block.inUse = false;
            // �������u���b�N�̃f�[�^��K�؂Ƀ��Z�b�g����K�v������ꍇ�͂����ōs��

            //�����m�F�̃R�����g
            std::cout << "Memory deallocated from: " << ptr << ", inUse: " << block.inUse << std::endl;
            break;
        }
    }
}
