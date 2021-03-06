// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.hpp"
#include <iostream>

int main()
{
    Stack<std::string> myStack;
    myStack.addItem("boop");
    myStack.addItem("beep");
    myStack.printAll();
    std::cout << "find: beep: ";
    std::cout << myStack.find("beep") << std::endl;

    std::cout << "find: boop: ";
    std::cout << myStack.find("boop") << std::endl;

    std::cout << "find: shwoop: ";
    std::cout << myStack.find("shwoop") << std::endl;

    myStack.clear();

    std::cout << "printing cleared stack" << std::endl;
    myStack.printAll();

    return 0;
}

