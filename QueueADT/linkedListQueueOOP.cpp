#include<iostream>
using namespace std;

class Queue{
    private:
        struct node{
            int value;
            node* link;
        };
        node* front, *rear;
    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }
        bool isEmpty(){
            return (front == NULL && rear == NULL);
        }

        void enQueue(int value){
            node* newNode = new node();
            newNode->value = value;
            newNode->link = NULL;
            if(isEmpty()){
                front = rear = newNode;
                return;
            }
            rear->link = newNode;
            rear = newNode;
        }

        int deQueue(){
            if(isEmpty()){
                cout << "Queue is empty..\n";
                return -1;
            }
            node* temp = front;
            if(front == rear){
                rear = NULL;
            }
            front = front->link;
            delete temp;
        }

        ~Queue(){
            while(front != rear){
                deQueue();
            }
            delete front;
        }

        int frontQ(){
            if(!isEmpty()){
                return front->value;
            }
            cout << "Queue is Empty..\n";
            return -1;
        }
};

int main(){
    Queue q1;
    q1.deQueue();
    q1.enQueue(3);
    q1.enQueue(6);
    q1.enQueue(4);
    q1.deQueue();
    cout << q1.frontQ() << endl;
}