#include "linked_list.cc" 

int main() {

    LinkedList<int> myList;


    myList.pushTail(10);
    myList.pushTail(20);
    myList.pushHead(5);
    myList.pushHead(2);
    std::cout << "Size of the list: " << myList.getSize() << std::endl;
    myList.printList(); 


    LinkedList<int> copiedList(myList);
    std::cout << "Copied list: ";
    copiedList.printList(); 


    LinkedList<int> assignedList;
    assignedList = myList;
    std::cout << "Assigned list: ";
    assignedList.printList(); 


    myList.popHead();
    myList.popTail();
    std::cout << "List after popHead and popTail: ";
    myList.printList(); 


    std::cout << "Element at index 1: " << myList[1] << std::endl; 

    LinkedList<int> testList1;
    testList1.pushTail(10);
    testList1.pushTail(112);
    testList1.pushTail(14);
    testList1.pushTail(10);
    std::cout << "testList1: ";
    testList1.printList();

    LinkedList<int> testList2;
    testList2.pushHead(17);
    testList2.pushHead(5);
    testList2.pushHead(89);
    testList2.pushHead(5);
    std::cout << "testList2: ";
    testList2.printList();

    myList.pushTail(testList1);
    myList.pushHead(testList2);
    std::cout << "List after pushTail testList1 and pushHead testList2: ";
    myList.printList();
    myList.deleteNode(10);
    myList.deleteNode(5);
    std::cout << "List after removing node with value 5 and 10: ";
    myList.printList(); 



    LinkedList<int> reversedList;
    reversedList.pushTail(1);
    reversedList.pushTail(2);
    reversedList.pushTail(3);
    reversedList.pushTail(4);
    reversedList.pushTail(5);
    reversedList.pushTail(6);
    reversedList.pushTail(7);
    reversedList.pushTail(8);
    reversedList.pushTail(9);
    reversedList.pushTail(10);
    std::cout << "List before reversing: ";
    reversedList.printList(); 
    reverseLinkedList(reversedList);
    std::cout << "List after reversing: ";
    reversedList.printList(); 


    reversedList.clear();
    std::cout << "List after clear: ";
    reversedList.printList(); 

    return 0;
}
