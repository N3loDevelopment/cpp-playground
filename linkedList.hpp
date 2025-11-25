#pragma once
#include <string>

struct Node
{
    std::string data;
    Node *prev;
    Node *next;
};

void initList();
void addToList(const std::string &val);
void removeAt(int index);
void getList();