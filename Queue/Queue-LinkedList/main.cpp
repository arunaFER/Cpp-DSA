#include <iostream>
#include "LinkedList.h"  

int main() {
    LinkedList queue;  
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    queue.recursionDisplay();

    std::cout << "Peek: " << queue.peek() << std::endl;

    // Dequeue an element
    queue.dequeue();
    std::cout << "After dequeue:" << std::endl;
    queue.recursionDisplay();

    std::cout << "Peek: " << queue.peek() << std::endl;

    queue.dequeue();
    queue.dequeue();
    
    // Try to dequeue from an empty queue
    queue.dequeue();

    // Try to peek at the empty queue
    std::cout << "Peek: " << queue.peek() << std::endl;

    return 0;
}
