#include <iostream>
#include "linked_list.cc" 

int main() {
    try {
        LinkedList<int> list;
        list.pushTail(10);
        list.pushTail(20);
        list.pushTail(30);
        list.pushTail(40);
        list.pushTail(20);
        list.pushTail(30);
        list.pushTail(40);
        list.pushTail(20);
        list.pushTail(30);
        list.pushTail(40);
        list.pushTail(20);
        list.pushTail(30);
        list.pushTail(40);

        std::cout << "Size of the list: " << list.getSize() << std::endl;
        list.printList();
        list.popHead();
        list.popTail();
        std::cout << "Size of the list after popping head and tail: " << list.getSize() << std::endl;
        list.printList();
        list.pushHead(5);
        list.pushTail(15);
        list.deleteNode(20);
        list.deleteNode(30);
        list.deleteNode(40);
        std::cout << "Size of the list after additional operations: " << list.getSize() << std::endl;
        list.printList();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
