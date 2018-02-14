#pragma once
#include <memory>
#include <string>
#include <iostream>

template <class T>
class Stack
{
public:
    Stack() {};
    ~Stack() {};

    void addItem(T element)
    {
        if(!head)
        {
            head = std::unique_ptr<Node>(new Node());
            head->value = element;
            _size++;
        }
        else
        {
            std::unique_ptr<Node> temp = std::unique_ptr<Node>(new Node());
            temp->previous = std::move(head);
            temp->value = element;
            head = std::move(temp);
            _size++;
        }

    };

    void deleteItem()
    {
        if (head)
        {
            head = std::move(head->previous);
            _size--;
        }
    };

    size_t size()
    {
        return _size;
    };

    int find(T element) 
    {
        Node* currentNode = head.get();
        int index = 0;
        while (currentNode)
        {
            if (currentNode->value == element)
            {
                return index;
            }
            currentNode = currentNode->previous.get();
            index++;
        }
        return -1;
    };

    void printAll() 
    {
        Node* currentNode = head.get();
        int index = 0;
        while (currentNode)
        {
            std::cout << "index: " << index << " ";
            std::cout << "value: " << currentNode->value << std::endl;
            currentNode = currentNode->previous.get();
            index++;
        }
    };

    void clear() 
    {
        if (head)
        {
            head = nullptr;
        }
    };

private:

    struct Node
    {
        T value;
        std::unique_ptr<Node> previous;
    };

    std::unique_ptr<Node> head;
    size_t _size;
};
