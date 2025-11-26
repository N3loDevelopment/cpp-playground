#pragma once
#include <string>

template <typename T>
struct Node
{
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template <typename T>

class LinkedList
{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

public:
    LinkedList();
    void addToList(T val);
    void removeAt(int index);
    void getList();
};