/*
    Queue - Array based implementation
*/

#include <iostream>

class Queue{
private:
    int front;
    int rear;
    int size; // queue size
    int* queue; // Array pointer
    // int queue[size] {} // for fixed size array
public:
    Queue(int s):
        front {-1}, rear{-1}, size{s}{
                queue = new int[size];
    }

    ~Queue(){
        delete [] queue;
    }

    bool isEmpty() const{
        return (front == -1);
    }

    bool isFull() const{
        return (rear == size -1);
    }

    void push(int value){
        if (isFull())
            return;

        if (front == -1)
            front = 0; // set to 0 for first element

        queue[++rear] = value;
        std::cout << value << " pushed to the queue." << std::endl;
    }

    // for pop we remove from front
    void pop(){
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot pop." << std::endl;
            return;
        }

        std::cout << queue[front] << " popped from the queue." << std::endl;

        // if one element was is in queue
        // now it is empty
        // so rest it

        if (front == rear){
            front = rear = -1;
        } else {
            ++front;
        }
    }

    int isFront() const{
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot pop." << std::endl;
            return -1;
        }

        return queue[front];
    }
};

int main(){
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    
    std::cout << "Front element: " << q.isFront() << std::endl;

    q.pop();
    std::cout << "Front element: " << q.isFront() << std::endl;

    q.push(40);
    q.push(50);
    q.push(60);  // queue is full

    while (!q.isEmpty()) {
        std::cout << "Front element: " << q.isFront() << std::endl;
        q.pop();
    }

    return 0;
}

