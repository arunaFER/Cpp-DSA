#include <iostream>
#include <stdexcept>

#include "LinkedListStack.h"

LinkedListStack::LinkedListStack():
    top {nullptr}, size {0}{
}

LinkedListStack::~LinkedListStack(){
    Node* current = top;
    Node* nextNode;

    while(current != nullptr){
        nextNode =  current->next;
        delete current;
        current = nextNode;
    }

    top = nullptr;
    size = 0;
}

bool LinkedListStack::isEmpty() const{
   return top == nullptr;
}

void LinkedListStack::push(int value){
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    ++size;
}

int LinkedListStack::pop(){
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty. Cannot pop.");
    }

    Node* current = top;
    top = current->next;
    int value = current->data;
    delete current;
    --size;
    return value;
}

int LinkedListStack::peek() const{
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty. Cannot peek.");
    }
    return top->data;
}

// Better to have private variable for size

// int LinkedListStack::size() const{
//     Node* current = top;
//     int count {0};
//     while (current != nullptr){
//         count += 1;
//         current = current->next;
//     }
//     return count;
// }

void LinkedListStack::display() const{
    Node* temp = top;
    std::cout << "Stack: ";

    if (top == nullptr) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }

    while (temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}