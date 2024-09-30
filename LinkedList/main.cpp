/*
    Linked list
*/

#include <stdlib.h>
#include <iostream>

#include "Node.h"
#include "LinkedList.h"


int main(){

    LinkedList linkedList;

    linkedList.display(); // Empty List

    linkedList.insertAtBeginning(2);
    linkedList.insertAtBeginning(3);
    linkedList.insertAtBeginning(4);
    linkedList.insertAtBeginning(5);

    linkedList.display(); // 5 4 3 2

    linkedList.insertAtPosition(-17, 2);

    linkedList.display(); // 5 -17 4 3 2

    linkedList.insertAtEnd(9); 

    linkedList.display(); // 5 -17 4 3 2 9

    linkedList.deleteNode(1);

    linkedList.display(); // -17 4 3 2 9

    linkedList.reverseList();

    linkedList.display(); // 9 2 3 4 -17

    linkedList.recursionDisplay();

    linkedList.reverseRecursionDisplay();

    linkedList.recursionReverse();

    linkedList.display();

    linkedList.stackReverse();

    linkedList.display();

    return 0;
}


/*
    ---------------------- Single File Linked List ----------------------
*/

// struct Node
// {
//     int data;
//     struct  Node* next;
// };

// // global
// Node* head {nullptr};

// insert node from the front
// void insert(int x){
//     Node* newNode = new Node();
//     newNode->data = x; // (*newNode).data = x;
//     newNode->next = head;
//     head = newNode;
// }

// insert node at given position n
// void insert(int x, int n){
//     Node* temp1 = new Node();
//     temp1->data = x;
//     temp1->next = NULL;

//     if (n == 1){
//         temp1->next = head;
//         head = temp1;
//         return;
//     }

//     Node* temp2 = head;
//     for (int i {0}; i < n - 2; ++i){
//         temp2 = temp2->next;
//     }

//     temp1->next = temp2->next;
//     temp2->next = temp1;
// }

// insert node at the end

// delete node at given position n
// void deleteNode(int n){
//     Node* temp1 = head;

//     if (n == 1){
//         head = temp1->next;
//         delete temp1;
//         return;
//     }

//     for (int i{0}; i < n - 2; ++i){
//         temp1 = temp1->next;
//     }

//     Node* temp2 = temp1->next;
//     temp1->next = temp2->next;
//     delete temp2;
// }

// void print(){
//     Node* temp = head;
//     std::cout << "Linked list: ";
//     while (temp != nullptr){
//         std::cout << temp->data << " ";
//         temp = temp->next;
//     }
//     std::cout << std::endl;
// }

// int main() {

//     head = NULL;
//     insert(2, 1);
//     insert(3, 2);
//     insert(4, 1);
//     insert(5, 2);

//     print();

//     deleteNode(2);

//     print();

//     return 0;
// }