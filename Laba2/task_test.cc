#include <iostream>
#include "linked_list.cc" 

int main() {
    LinkedList<int> myList;
    for (int i = 1; i < 10; ++i)
        myList.pushTail(i);

    myList.printList();

    reverseLinkedList(myList);

    myList.printList();

    return 0;
}
