#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <random>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    // Конструктор по умолчанию
    Node() : data(), next(nullptr), prev(nullptr) {}

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};


template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_tail(current->data);
            current = current->next;
        }
    }

    LinkedList(size_t count, const T& value) : head(nullptr), tail(nullptr), size(0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);

        for (size_t i = 0; i < count; ++i) {
            push_tail(static_cast<T>(dis(gen))); // Генерация случайного числа и добавление в список
        }
    }

    ~LinkedList() {
        clear();
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other.head;
            while (current != nullptr) {
                push_tail(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push_tail(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            head->next = nullptr;
            head->prev = nullptr;
        }
        else {
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    void push_head(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            head->next = nullptr;
            head->prev = nullptr;
        }
        else {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }



    void pop_head() {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        --size;
    }

    void pop_tail() {
        if (tail == nullptr) {
            throw std::out_of_range("List is empty");
        }
        if (head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
        --size;
    }

    

    T& operator[](size_t index) {
        if (index >= size || size == 0) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    const T& operator[](size_t index) const {
        if (index >= size || size == 0) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    size_t getSize() const {
        return size;
    }

    void clear() {
        while (head != nullptr) {
            pop_head();
        }
    }

    void printList() const {
        if (size == 0) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node<T>* current = head;
        std::cout << "Elements in the list: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node<T>* find(const T& value) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current; 
            }
            current = current->next;
        }
        return nullptr; 
    }

    void removeByPointer(Node<T>* ptr) {
        if (ptr == nullptr) {
            return; 
        }
        Node<T>* foundNode = find(ptr->data);
        if (foundNode == nullptr) {
            return; 
        }
        if (foundNode == head) {
            pop_head(); 
        }
        else if (foundNode == tail) {
            pop_tail(); 
        }
        else {
            foundNode->prev->next = foundNode->next;
            foundNode->next->prev = foundNode->prev;
            delete foundNode; 
            --size;
        }
    }

    void delete_node(const T& value) {
        Node<T>* foundNode = find(value);

        while (foundNode != nullptr) {
            removeByPointer(foundNode); 
            foundNode = find(value); 
        }
    }
};

#endif  
