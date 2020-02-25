#include<iostream>
using namespace std;

class Queue{
    private:
        int capacity;
        int frontQ, rear;
        int* arr;
    public:
        Queue(int capacity){
            arr = new int[capacity];
            this->capacity = capacity;
            frontQ = rear = -1;
        }
        bool isEmpty();
        bool isFull();
        void enQueue(int);
        int deQueue();
        int front();
        ~Queue(){
            delete[] arr;
        }
};
bool Queue::isEmpty(){
    return (frontQ == -1 && rear == -1);
}

bool Queue::isFull(){
    return (frontQ == ((rear + 1)%capacity));
}

void Queue::enQueue(int value){
    if(isEmpty()){
        rear++;
        frontQ++;
        arr[rear] = value;
        return;
    }
    if(!isFull()){
        rear = (rear + 1)%capacity;
        arr[rear] = value;
        return;
    }
    cout << "Queue is Full..\n";
}

int Queue::deQueue(){
    if(isEmpty()){
        cout << "Queue is empty..\n";
        return -1;
    }
    if(frontQ == rear){
        int item = arr[rear];
        frontQ = rear = -1;
        return item;   
    }
    int item = arr[frontQ];
    frontQ = (frontQ + 1)%capacity;
    return item;
}

int Queue::front(){
    if(!isEmpty()){
        return arr[frontQ];
    }
    cout << "Queue is Empty\n";
    return -1;
}

int main(){
    Queue q1(6);
    q1.deQueue();
    q1.enQueue(3);
    q1.enQueue(6);
    q1.enQueue(4);
    q1.deQueue();
    cout << q1.front() << endl;
}