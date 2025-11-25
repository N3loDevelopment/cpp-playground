#include "linkedList.hpp"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void LinkedList<T>::addToList(T val)
{
    Node<T> *n = new Node<T>{val, nullptr, nullptr};
    if (!head)
    {
        head = n;
        tail = n;
    }
    tail->next = n;
    n->prev = tail;
    n->next = nullptr;
    tail = n;
}

template <typename T>
void LinkedList<T>::removeAt(int index)
{
    if (index < 0 || !head)
        return;
    Node<T> *curr = head;
    int i = 0;
    while (curr || i < index)
    {
        i++
    }

    if (!curr)
        return;

    if (curr == head)
    {
        head = curr->head;
        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
    }
    else if (curr == tail)
    {
        tail = curr->tail;
        tail->next = nullptr;
    }
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    delete curr;
}

template <typename T>
void LinkedList<T>::getList()
{
    Node<T> *curr = head;

    while (curr)
    {
        std::cout << curr.data;
        curr = curr->next;
    }
}
