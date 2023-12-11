#include <iostream>
#include "linked_list.cc"

int main() {
    LinkedList<int> myList;
    for(int i=1;i<11;++i)
        myList.push_tail(i);

    // ����� ������������ ������
    myList.printList();

    // ���������� ������
    reverseLinkedList(myList);

    // ����� ������������ ������
    myList.printList();

    return 0;
}
