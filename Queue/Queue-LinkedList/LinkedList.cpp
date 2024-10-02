#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList()
    :front {nullptr}, rear {nullptr}{
}

LinkedList::~LinkedList(){
    Node* current = front;
    Node* nextNode;

    while(current != nullptr){
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    front = nullptr;
}

bool LinkedList::isEmpty(){
   return front == nullptr;
}

void LinkedList::enqueue(int value){
    Node* newNode = new Node(value);
    newNode->next = nullptr;

    if (isEmpty()){
        front = rear = newNode;
        return;
    }
    
    rear->next = newNode;
    rear = newNode;
}

void LinkedList::dequeue(){
    if (isEmpty()){
        std::cout << "Cannot dequeue, queue is empty" << std::endl;
        return;
    } 
    
    Node* temp = front;
    
    if (front == rear) {
        front = rear = nullptr; // removing last node. Now queue is empty
    } else {
        front = front->next;
    }

    delete temp;
}

int LinkedList::peek(){
    if (isEmpty()) {
        std::cout << "Queue is empty, nothing to peek" << std::endl;
        return -1;
    }

    return front->data;
}

void LinkedList::recursionDisplayHelper(Node* n){
    if (n == nullptr)
        return;

    std::cout << n->data << " ";
    recursionDisplayHelper(n->next);
}

void LinkedList::recursionDisplay(){
    std::cout << "Recursion display queue: " << std::endl;
    recursionDisplayHelper(front);
    std::cout << std::endl;
}