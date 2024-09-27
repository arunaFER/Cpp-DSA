/*
    Linked list
*/

#include <stdlib.h>
#include <iostream>

struct Node
{
    int data;
    struct  Node* next;
};

// global
Node* head {nullptr};

void insert(int x){
    Node* newNode = new Node();
    newNode->data = x; // (*newNode).data = x;
    newNode->next = head;
    head = newNode;
}

void print(){
    Node* temp = head;
    std::cout << "Linked list: ";
    while (temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main(){
    std::cout << "########## Linked List ##########" << std::endl;

    char choice;

    do{
        int num {0};
        std::cout << "Enter number to insert into linked list: ";
        std::cin >> num;

        insert(num);

        print();


        std::cout << "Do you want to insert another number? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}