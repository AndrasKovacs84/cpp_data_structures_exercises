#pragma once
#include <memory>
#include <string>
#include <iostream>

//template <class T>
class Stack
{
public:
    Stack();
    ~Stack();

    void addItem(std::string element);
    void deleteItem();
    size_t size();
    int find(std::string element);
    void printAll();
    void clear();

private:

    struct Node
    {
        std::string value;
        std::unique_ptr<Node> previous;
    };

    std::unique_ptr<Node> head;
    size_t _size;
};

