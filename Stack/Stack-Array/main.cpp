/*
    Stack using Arrays
*/

#include <iostream>
#include <stdexcept>

class Stack {
private:
    static const int capacity = 100;
    int arr[capacity];
    int top;
public:
    Stack(): top{-1} {}

    bool isFull() const {
        return top == capacity -1;
    }

    bool isEmpty() const{
        return top == -1;
    }

    int size() const{
        return top + 1;
    }

    // push
    void push(int x){
        if (isFull()) {
            throw std::overflow_error("Stack overflow: Cannot push, the stack is full.");
        }
        arr[++top] = x;
    }

    int pop(){
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: Cannot pop, the stack is empty.");
        }
        return arr[top--];
    }

    int peek(){
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: No element to peek.");
        }
        return arr[top];
    }

    void display() const{
        std::cout << "Printing stack: ";
        for(int i {0}; i <= top; ++i){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    intStack.display();

    std::cout << "Top element: " << intStack.peek() << std::endl;

    std::cout << "Popped element: " << intStack.pop() << std::endl;
    std::cout << "Popped element: " << intStack.pop() << std::endl;

    std::cout << "Stack size: " << intStack.size() << std::endl;

    intStack.display();
    
    return 0;
}