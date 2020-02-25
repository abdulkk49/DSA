#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct arrayADT{
    int capacity;
    int lastIndex;
    int* ptr;
}arrayADT;


//function declarations
arrayADT* createArray(int);
int getItem(arrayADT*, int);
int editItem(arrayADT*, int, int);
int setItem(arrayADT*, int, int);
int countItems(arrayADT*);
int removeItem(arrayADT*, int);

//creating array
arrayADT* createArray(int capacity){
    arrayADT* arr = (arrayADT*)malloc(sizeof(arrayADT));
    arr->capacity = capacity;
    arr->lastIndex = -1;
    arr->ptr = (int*)malloc(capacity * sizeof(int));
    return arr;
}

//accessing the array
int getItem(arrayADT* arr, int index){

    if(arr->lastIndex < index || index < 0 || arr->lastIndex == -1){
        printf("Invalid Access or Empty array");
        return -1;
    }
    if(index > arr->capacity){
        return -1;
    }
    return arr->ptr[index];
}

//add to array
int setItem(arrayADT* arr, int index, int value){
    if(arr->lastIndex == arr->capacity - 1){
        printf("Array is full");
        return -1;
    }
    if(index < 0 || index >= arr->lastIndex + 2){
        printf("Can't skip an index");
        return -1;
    }

    if(index == arr->lastIndex + 1){
        arr->ptr[index] = value;
        arr->lastIndex = arr->lastIndex + 1;
        return 1;
    }

    if(index <= arr->lastIndex){
        arr->lastIndex = arr->lastIndex + 1;
        int i = arr->lastIndex;
        while(i != index){
            arr->ptr[i] = arr->ptr[i-1];
            i--;
        }
        arr->ptr[index] = value;
        printf("Value added at index %d", i);
        return 1;
    }
    return 1;
}

//Update the element in array
int editItem(arrayADT* arr, int index, int value){
    if(index < 0 || index > arr->lastIndex){
        printf("Invalid Access");
        return -1;
    }
    arr->ptr[index] = value;
    return 1;
}

int countItems(arrayADT* arr){
    return (arr->lastIndex + 1);
}


//remove from array
int removeItem(arrayADT* arr, int index){
    if(index < 0 || index > arr->lastIndex){
        printf("Invalid Access");
        return -1;
    }

    int i = index;
    while(i != arr->lastIndex){
        arr->ptr[i] = arr->ptr[i+1];
        i++;
    }
    arr->lastIndex = arr->lastIndex - 1;
    return 1;
}


//driver main
int main(){
    arrayADT* myArray = createArray(5);
    setItem(myArray, 0, 1);
    setItem(myArray, 1, 4);
    setItem(myArray, 2, 5);
    printf("Get index: %d", getItem(myArray, 1));
    printf("\n");
}
