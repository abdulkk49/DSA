#include<iostream>
using namespace std;

class arrayADT{
    private:
        int capacity;
        int lastIndex;
        int* ptr;

    public:
        arrayADT(){
            capacity = 0;
            lastIndex = -1;
            ptr = NULL;
        }
        void createArray(int);
        int getItem(int);
        int editItem(int, int);
        int setItem(int, int);
        int countItems();
        int removeItem(int);

        ~arrayADT(){
            delete[] ptr;
        }
};

//creating array
void arrayADT::createArray(int capacity){
    arrayADT* arr = (arrayADT*)malloc(sizeof(arrayADT));
    this->capacity = capacity;
    this->lastIndex = -1;
    this->ptr = new int[capacity];
}

//accessing the array
int arrayADT::getItem(int index){

    if(this->lastIndex < index || index < 0 || this->lastIndex == -1){
        printf("Invalid Access or Empty array");
        return -1;
    }
    if(index > this->capacity){
        return -1;
    }
    return this->ptr[index];
}

//add to array
int arrayADT::setItem(int index, int value){
    if(this->lastIndex == this->capacity - 1){
        printf("Array is full");
        return -1;
    }
    if(index < 0 || index >= this->lastIndex + 2){
        printf("Can't skip an index");
        return -1;
    }

    if(index == this->lastIndex + 1){
        this->ptr[index] = value;
        this->lastIndex = this->lastIndex + 1;
        return 1;
    }

    if(index <= this->lastIndex){
        this->lastIndex = this->lastIndex + 1;
        int i = this->lastIndex;
        while(i != index){
            this->ptr[i] = this->ptr[i-1];
            i--;
        }
        this->ptr[index] = value;
        printf("Value added at index %d", i);
        return 1;
    }
    return 1;
}

//Update the element in array
int arrayADT::editItem(int index, int value){
    if(index < 0 || index > this->lastIndex){
        printf("Invalid Access");
        return -1;
    }
    this->ptr[index] = value;
    return 1;
}

int arrayADT::countItems(){
    return (this->lastIndex + 1);
}


//remove from array
int arrayADT::removeItem(int index){
    if(index < 0 || index > this->lastIndex){
        printf("Invalid Access");
        return -1;
    }

    int i = index;
    while(i != this->lastIndex){
        this->ptr[i] = this->ptr[i+1];
        i++;
    }
    this->lastIndex = this->lastIndex - 1;
    return 1;
}


//driver main
int main(){
    arrayADT myArray;
    myArray.createArray(5);
    myArray.setItem(0, 1);
    myArray.setItem(1, 4);
    myArray.setItem(2, 5);
    cout << myArray.getItem(2)<<endl;
    return 0;

}
