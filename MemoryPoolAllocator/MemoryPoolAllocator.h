#pragma once
#include <iostream>
#include <vector>

class MemoryPoolAllocator {
private:
    // �������u���b�N��\���\����
    struct MemoryBlock {
        bool inUse; // �������u���b�N���g�p�����ǂ����������t���O
        // �������u���b�N�̃f�[�^���i�[���邽�߂̕K�v�ȃf�[�^�������ɒǉ��ł��܂�
    };

    std::vector<MemoryBlock> memoryPool; // �������v�[�����Ǘ�����x�N�^�[

public:
    // �R���X�g���N�^�[
    MemoryPoolAllocator(size_t size);


    // �������̊��蓖��
    void* allocate();

    // �������̉��
    void deallocate(void* ptr);
};
