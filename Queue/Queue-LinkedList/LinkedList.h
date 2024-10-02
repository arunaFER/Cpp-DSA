
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.h"

class LinkedList{
private:
    Node* front;
    Node* rear;
public:
    LinkedList();
    ~LinkedList();

    bool isEmpty();

    void enqueue(int value);
    void dequeue();
    int peek();

    void recursionDisplayHelper(Node* n);
    void recursionDisplay();
};

#endif