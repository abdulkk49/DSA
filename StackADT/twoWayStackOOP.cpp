#include<iostream>
using namespace std;

class TwoWayStack{
    private:
        int capacity;
        int topLeft;
        int topRight;
        int *arr;
    public:
        TwoWayStack( int capacity){
            this->capacity = capacity;
            topLeft = -1;
            topRight = capacity;
            arr = new int[capacity];
        }
        bool isFull();
        bool isEmptyRight();
        bool isEmptyLeft();
        void pushLeft(int value);
        int popLeft();
        void pushRight(int value);
        int popRight();
        int peekLeft();
        int peekRight();
        ~TwoWayStack(){
            delete[] arr;
        }
};
bool TwoWayStack::isFull(){
    return (topLeft + 1 == topRight);
}

bool TwoWayStack::isEmptyRight(){
    return (topRight == capacity);
}

bool TwoWayStack::isEmptyLeft(){
    return (topLeft == -1);
}

void TwoWayStack::pushLeft(int value){
    if(!isFull()){
        topLeft++;
        arr[topLeft] = value;
        return;
    }
    cout<<"Stack is Full\n";
}

void TwoWayStack::pushRight(int value){
    if(!isFull()){
        topRight--;
        arr[topRight] = value;
        return;
    }
    cout << "Stack is Full\n";
}

int TwoWayStack::popLeft(){
    if(!isEmptyLeft()){
        topLeft--;
        return arr[topLeft + 1];
    }
    return -1;
}

int TwoWayStack::peekLeft(){
    if(!isEmptyLeft()){
        return arr[topLeft];
    }
    return -1;
}

int TwoWayStack::popRight(){
    if(!isEmptyRight()){
        topRight++;
        return arr[topRight - 1];
    }
    return -1;
}

int TwoWayStack::peekRight(){
    if(!isEmptyRight()){
        return arr[topRight];
    }
    return -1;
}

int main(){
    TwoWayStack s1(7);
    s1.pushLeft(1);
    s1.pushLeft(2);
    s1.pushLeft(3);
    cout<<s1.peekLeft()<<endl;
    s1.pushLeft(4);
    s1.pushLeft(5);
    cout<<s1.peekLeft()<<endl;
    s1.popLeft();
    s1.pushRight(6);
    s1.pushRight(7);
    s1.pushRight(8);
    cout<<s1.peekRight()<<endl;
    s1.pushLeft(0);
    return 0;
}