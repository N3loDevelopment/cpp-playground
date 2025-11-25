#include <iostream>
#include <string>

struct Node
{
    std::string data;
    Node *prev;
    Node *next;
};

Node *head;
Node *tail;

void initList()
{
    head = nullptr;
    tail = nullptr;
}

void addToList(const std::string &val)
{
    Node *n = new Node{val, nullptr, nullptr};
    if (!head)
    {
        head = n;
        tail = n;
        return;
    }
    tail->next;
    n->prev;
    tail = n;
}

void getList()
{
    Node *curr = head;
    while (curr)
    {
        std::cout << curr->data << std::endl;
        curr = curr->next;
    }
}