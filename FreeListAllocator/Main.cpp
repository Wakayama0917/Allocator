#include <iostream>
#include "FreeList.h"

int main() {
    FreeListAllocator allocator;  //FreeListAllocator�̃C���X�^���X���쐬

    //�������̊��蓖�ĂƉ���̃e�X�g
    void* ptr1 = allocator.allocate(10);  //10�o�C�g�̃����������蓖��
    std::cout << "Allocated memory at: " << ptr1 << std::endl;  //���蓖�Ă��������̃|�C���^���o��
    allocator.deallocate(ptr1, 10);  //���蓖�Ă������������
    std::cout << "Deallocated memory from: " << ptr1 << std::endl;  //��������������̃|�C���^���o��

    return 0;
}