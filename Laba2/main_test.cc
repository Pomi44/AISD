#include <iostream>
#include "linked_list.cc" // ���������� ������������ ���� � ������������ ������ LinkedList

int main() {
    try {
        // �������� ������� ������
        LinkedList<int> list;

        // ���������� ��������� � ������
        list.push_tail(10);
        list.push_tail(20);
        list.push_tail(30);
        list.push_tail(40);
        list.push_tail(20);
        list.push_tail(30);
        list.push_tail(40);
        list.push_tail(20);
        list.push_tail(30);
        list.push_tail(40);
        list.push_tail(20);
        list.push_tail(30);
        list.push_tail(40);

        // ����� ������� ������
        std::cout << "Size of the list: " << list.getSize() << std::endl;

        // ����� ��������� ������ � �������������� ������ printList
        list.printList();

        // �������� ������� � ���������� ���������
        list.pop_head();
        list.pop_tail();

        // ����� ������� ������ ����� �������� ���������
        std::cout << "Size of the list after popping head and tail: " << list.getSize() << std::endl;

        // ����� ��������� ������ ����� �������� ���������
        list.printList();

        // ���������� ��������� � ������ � �������� �� ��������
        list.push_head(5);
        list.push_tail(15);
        list.delete_node(20);
        list.delete_node(30);
        list.delete_node(40);
         // �������� �������� �� ��������� 20

        // ����� ������� ������ ����� ���������� � �������� ���������
        std::cout << "Size of the list after additional operations: " << list.getSize() << std::endl;

        // ����� ��������� ������ ����� ���������� � �������� ���������
        list.printList();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
