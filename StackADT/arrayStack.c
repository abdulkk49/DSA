#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int capacity;
    int top;
    int* arr;
}stack;

stack* createStack(int);
void push(stack*, int);
int top(stack*);
int pop(stack*);

void push(stack* myStack, int value){
    if(myStack->top == myStack->capacity -1){
        printf("Overflow\n");
        return;
    }
    myStack->top = myStack->top + 1;
    myStack->arr[myStack->top] = value;
}

int pop(stack* myStack){
    if(myStack->top == -1){
        printf("Undeflow\n");
        return -1;
    }
    myStack->top = myStack->top - 1;
    return myStack->arr[myStack->top + 1];
}

int top(stack* myStack){
    return myStack->arr[myStack->top];
}

stack* createStack(int capacity){
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->capacity = capacity;
    temp->top = -1;
    temp->arr = (int*)malloc(sizeof(int)*capacity);
    return temp;
}
int main(){
    stack* myStack = createStack(6);
    push(myStack, 1);
    push(myStack, 3);
    push(myStack, 2);
    push(myStack, 4);
    push(myStack, 5);
    printf("%d \n", pop(myStack));

}