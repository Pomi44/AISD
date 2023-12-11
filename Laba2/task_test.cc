#include <iostream>
#include "linked_list.cc"

int main() {
    LinkedList<int> myList;
    for(int i=1;i<11;++i)
        myList.push_tail(i);

    // Вывод изначального списка
    myList.printList();

    // Развернуть список
    reverseLinkedList(myList);

    // Вывод развернутого списка
    myList.printList();

    return 0;
}
