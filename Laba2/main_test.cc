#include <iostream>
#include "linked_list.cc" // Подключаем заголовочный файл с определением класса LinkedList

int main() {
    try {
        // Создание пустого списка
        LinkedList<int> list;

        // Добавление элементов в список
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

        // Вывод размера списка
        std::cout << "Size of the list: " << list.getSize() << std::endl;

        // Вывод элементов списка с использованием метода printList
        list.printList();

        // Удаление первого и последнего элементов
        list.pop_head();
        list.pop_tail();

        // Вывод размера списка после удаления элементов
        std::cout << "Size of the list after popping head and tail: " << list.getSize() << std::endl;

        // Вывод элементов списка после удаления элементов
        list.printList();

        // Добавление элементов в начало и удаление по значению
        list.push_head(5);
        list.push_tail(15);
        list.delete_node(20);
        list.delete_node(30);
        list.delete_node(40);
         // Удаление элемента со значением 20

        // Вывод размера списка после добавления и удаления элементов
        std::cout << "Size of the list after additional operations: " << list.getSize() << std::endl;

        // Вывод элементов списка после добавления и удаления элементов
        list.printList();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
