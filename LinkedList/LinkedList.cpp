#include <iostream>
#include <stack>
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

// Improved delete node
// void LinkedList::deleteNode(int position) {
//     if (position <= 0) {
//         std::cout << "Invalid position. Position must be greater than 0.\n";
//         return;
//     }

//     if (head == nullptr) {
//         std::cout << "List is empty. Cannot delete node.\n";
//         return;
//     }

//     Node* temp1 = head;

//     // Special case: delete the head node
//     if (position == 1) {
//         head = temp1->next; // Move head to the next node
//         delete temp1;       // Free the old head node
//         return;
//     }

//     // Traverse to the (position-1)-th node (1-based index)
//     for (int i = 1; i < position - 1 && temp1 != nullptr; ++i) {
//         temp1 = temp1->next;
//     }

//     // Check if the position is out of bounds
//     if (temp1 == nullptr || temp1->next == nullptr) {
//         std::cout << "Position is out of bounds. Cannot delete node.\n";
//         return;
//     }

//     // Delete the node at the given position
//     Node* temp2 = temp1->next;  // Node to be deleted
//     temp1->next = temp2->next; // Link to the next node
//     delete temp2;              // Free memory
// }


// reverse list
void LinkedList::reverseList(){

    if (head == nullptr)
        return;

    Node* current; 
    Node* prev {nullptr}; 
    Node* next {nullptr};

    current = head;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}


// reverse list with recursion
void LinkedList::recursionReverseListHelper(Node* n){
    if (n->next == nullptr){
        head = n;
        return;
    }

    recursionReverseListHelper(n->next);

    Node* m = n->next; // n->next->next = n;
    m->next = n;       // 
    n->next = nullptr;    
}
    
void LinkedList::recursionReverse(){
    if (head == nullptr)
        return;

    recursionReverseListHelper(head);
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


// display list with recursion
void LinkedList::recursionDisplayHelper(Node* n){
    if (n == nullptr)
        return;

    std::cout << n->data << " ";
    LinkedList::recursionDisplayHelper(n->next);
}

void LinkedList::recursionDisplay(){
    std::cout << "Recursion Linked list: ";
    LinkedList::recursionDisplayHelper(head);
    std::cout << std::endl;
}


// display list in reverse with recursion
void LinkedList::reverseRecursionDisplayHelper(Node* n){
    if (n == nullptr)
        return;

    LinkedList::reverseRecursionDisplayHelper(n->next);
    std::cout << n->data << " ";
}

void LinkedList::reverseRecursionDisplay(){
    std::cout << "Reversed Recursion Linked list: ";
    LinkedList::reverseRecursionDisplayHelper(head);
    std::cout << std::endl;
}

// reverse linked list using stack
void LinkedList::stackReverse(){
    if (head == nullptr)
        return;

    std::stack<Node*> s;

    Node* temp = head;

    while (temp != nullptr){
        s.push(temp);
        temp = temp->next;
    }

    temp = s.top();
    head = temp;

    while(!s.empty()){
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }

    temp->next = nullptr;
}