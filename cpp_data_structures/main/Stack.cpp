#include "stdafx.h"
#include "Stack.h"


Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::addItem(std::string element)
{
    if (!head)
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
}

void Stack::deleteItem()
{
    if (head)
    {
        head = std::move(head->previous);
        _size--;
    }
}

size_t Stack::size()
{
    return _size;
}

int Stack::find(std::string element)
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
}

void Stack::printAll()
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
}

void Stack::clear()
{
    if (head)
    {
        head = nullptr;
    }
}
