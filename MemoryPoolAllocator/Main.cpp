#include "MemoryPoolAllocator.h"


int main() {
    MemoryPoolAllocator allocator(10); // �������v�[���̃T�C�Y��10�Ƃ��܂�

    // �������̊��蓖�ĂƉ���̃e�X�g
    void* ptr1 = allocator.allocate(); // �������̊��蓖��
    if (ptr1) {
        
        // �������̉��
        allocator.deallocate(ptr1); 
        
    }
    else {
        std::cout << "Failed to allocate memory." << std::endl;
    }

    return 0;
}