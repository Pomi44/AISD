#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <ctime>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList(size_t count, const T& value);
    ~LinkedList();

    LinkedList& operator=(const LinkedList& other);

    void push_tail(const T& value);
    void push_head(const T& value);
    void pop_head();
    void pop_tail();
    void delete_node(const T& value);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t getSize() const;
    void clear();
};
#endif  
