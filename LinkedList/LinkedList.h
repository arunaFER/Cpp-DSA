
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.h"

class LinkedList{
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();
    void insertAtBeginning(int value);
    void insertAtPosition(int value, int position);
    void insertAtEnd(int value);
    
    void deleteNode(int position);
    
    void reverseList();
    void recursionReverseListHelper(Node* n);
    void recursionReverse();
    void stackReverse();
    
    void display();
    void recursionDisplayHelper(Node* n);
    void recursionDisplay();
    void reverseRecursionDisplayHelper(Node* n);
    void reverseRecursionDisplay();
};

#endif