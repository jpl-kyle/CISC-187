#include <iostream>
#include "Stack.h"

void Stack::push(int value) 
{
    Node* newNode = new Node{value, nullptr}; // create a node
    newNode->next = top; // make the node point to the top node
    top = newNode; // assign the node as the new top.
}

void Stack::pop()
{
    if (top == nullptr) //if there is no top, there is nothing in the stack.
    {
        std::cout << "Stack Underflow." << std::endl;
        return;
    }

    Node* temp = top; //create a temp node that is assigned to the top node.
    top = top->next; //set the new top as the node after it.
    delete temp; // deallocate temp.
}

int Stack::peek() 
{
    if (top != nullptr) //if there is no top, there is nothing in the stack.
    {
        return top->data; //return this stack's top data.
    }
    else
    {
        std::cout << "No peeking! (The Stack is empty.)" << std::endl;
        return 0;
    }
}

bool Stack::isEmpty() 
{
    if (top == nullptr) { //if there is no top, there is nothing in the stack.
        std::cout << "The Stack is empty." << std::endl;
        return true;
    }
    else {
        std::cout << "The Stack is not empty." << std::endl;
        return false;
    }
}

void Stack::display() 
{
    if (top == nullptr) //if there is no top, there is nothing in the stack.
    {
        std::cout << "Nothing to display." << std::endl;
        return;
    }

    Node* element = top; //create an element that assigns top's data and pointer to the next node.

    std::cout << "Stack Elements: " << std::endl; 
    while (element != nullptr)
    {
        std::cout << element->data << std::endl; // cout this element's data,
        element = element->next; //assign the element with the next node.
    }
    
}

Stack::Stack()
{
    top = nullptr;
}
