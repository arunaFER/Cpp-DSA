#ifndef _LINKEDLISTSTACK_H_
#define _LINKEDLISTSTACK_H_

#include "Node.h"

class LinkedListStack{
private:
    Node* top;
    int size;
public:
    LinkedListStack();
    ~LinkedListStack();
    
    bool isEmpty() const;

    void push(int value);
    int pop();
    int peek() const;

    // int size() const;
    // void clear(); // similar to destructor
    void display() const;
};

#endif