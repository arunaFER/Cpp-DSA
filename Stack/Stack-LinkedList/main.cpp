#include <iostream>

#include "LinkedListStack.h"

int main(){

    LinkedListStack stack;

    stack.display();

    stack.push(34);
    stack.push(8);
    stack.push(5);

    stack.display();

    stack.peek();
    
    stack.display();

    stack.pop();

    stack.display();

    return 0;
}