#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
    :head{nullptr}{
        // std::cout << "---Using LinkedList Constructor ---" << std::endl;
}

LinkedList::~LinkedList(){
    // std::cout << "---Using LinkedList Destructor ---" << std::endl;

    Node* current = head;
    Node* nextNode;
    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

void LinkedList::insertAtBeginning(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtPosition(int value, int position){
    Node* temp1 = new Node(value);

    if (position < 1) {
        std::cout << "Invalid position" << std::endl;
        delete temp1;
        return;
    }
    
    if (position == 1){
        temp1->next = head;
        head = temp1;
        return;
    }

    Node* temp2 = head;
    for (int i {0}; i < position - 2; ++i){
        if (temp2 == nullptr){
            std::cout << "Position out of bounds!" << std::endl;
            delete temp1; 
            return;
        }
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void LinkedList::insertAtEnd(int value){
    Node* newNode = new Node(value);
    newNode->next = nullptr;

    if (head == nullptr){
        head = newNode;
        return;
    }

    Node* temp1 = head;
    while (temp1->next != nullptr){
        temp1 =  temp1->next;
    }
    
    temp1->next = newNode;
}

void LinkedList::deleteNode(int position){
    Node* temp1 = head;

    if (position == 1){
        head = temp1->next;
        delete temp1;
        return;
    }

    for (int i{0}; i < position - 2; ++i){
        temp1 = temp1->next;
    }

    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

void LinkedList::display(){
    Node* temp = head;
    std::cout << "Linked list: ";

    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    while (temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}