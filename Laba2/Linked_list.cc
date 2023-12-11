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

    Node() : data(), next(nullptr), prev(nullptr) {}

    explicit Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* _head;
    Node<T>* _tail;
    size_t _size;

public:
    LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}

    LinkedList(const LinkedList& other) : _head(nullptr), _tail(nullptr), _size(0) {
        Node<T>* current = other._head;
        while (current != nullptr) {
            pushTail(current->data);
            current = current->next;
        }
    }

    explicit LinkedList(size_t count, const T& value) : _head(nullptr), _tail(nullptr), _size(0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);

        for (size_t i = 0; i < count; ++i) {
            pushTail(static_cast<T>(dis(gen)));
        }
    }

    ~LinkedList() {
        clear();
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other._head;
            while (current != nullptr) {
                pushTail(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void pushTail(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (_head == nullptr) {
            _head = newNode;
            _tail = newNode;
            _head->next = nullptr;
            _head->prev = nullptr;
        }
        else {
            newNode->next = nullptr;
            newNode->prev = _tail;
            _tail->next = newNode;
            _tail = newNode;
        }
        ++_size;
    }

    void pushHead(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (_head == nullptr) {
            _head = newNode;
            _tail = newNode;
            _head->next = nullptr;
            _head->prev = nullptr;
        }
        else {
            newNode->next = _head;
            newNode->prev = nullptr;
            _head->prev = newNode;
            _head = newNode;
        }
        ++_size;
    }

    void popHead() {
        if (_head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        if (_head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
        }
        else {
            Node<T>* temp = _head;
            _head = _head->next;
            if (_head != nullptr) {
                _head->prev = nullptr;
            }
            else {
                _tail = nullptr;
            }
            delete temp;
        }
        --_size;
    }


    void popTail() {
        if (_tail == nullptr) {
            throw std::out_of_range("List is empty");
        }
        if (_head == _tail) {
            delete _tail;
            _head = nullptr;
            _tail = nullptr;
        }
        else {
            Node<T>* temp = _tail;
            _tail = _tail->prev;
            _tail->next = nullptr;
            delete temp;
        }
        --_size;
    }

    T& operator[](size_t index) {
        if (index >= _size || _size == 0) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = _head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    const T& operator[](size_t index) const {
        if (index >= _size || _size == 0) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = _head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    size_t getSize() const {
        return _size;
    }

    Node<T>* getHead() const {
        return _head;
    }

    Node<T>* getTail() const {
        return _tail;
    }

    void setHead(Node<T>* newHead) {
        _head = newHead;
    }

    void setTail(Node<T>* newTail) {
        _tail = newTail;
    }

    void clear() {
        while (_head != nullptr) {
            popHead();
        }
    }

    void printList() const {
        if (_size == 0) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node<T>* current = _head;
        std::cout << "Elements in the list: ";
        for (size_t i = 0; i < _size; ++i) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node<T>* find(const T& value) const {
        Node<T>* current = _head;
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
        if (ptr == _head) {
            popHead();
        }
        else if (ptr == _tail) {
            popTail();
        }
        else {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete ptr;
            --_size;
        }
    }

    void deleteNode(const T& value) {
        Node<T>* foundNode = find(value);

        while (foundNode != nullptr) {
            removeByPointer(foundNode);
            foundNode = find(value);
        }
    }
};

template <typename T>
void reverseLinkedList(LinkedList<T>& list) {
    if (list.getSize() == 0 || list.getHead() == list.getTail()) {
        return;
    }

    Node<T>* currentNode = list.getHead();
    Node<T>* tempNode = nullptr;

    while (currentNode != nullptr) {
        tempNode = currentNode->prev;
        currentNode->prev = currentNode->next;
        currentNode->next = tempNode;
        currentNode = currentNode->prev;
    }

    if (tempNode != nullptr) {
        list.setHead(tempNode->prev);
        list.setTail(tempNode);
    }
}

#endif // LINKEDLIST_H
