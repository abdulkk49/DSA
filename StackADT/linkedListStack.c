#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;   
}node;


node* push(node*, int);
int top(node*);
int pop(node**);

node* push(node* top, int value){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->link = top;
    top = newNode;
    return top;
}

int pop(node** top){
    if(*top == NULL){
        printf("Underflow..\n");
        return 0;
    }
    node* temp = *top;
    int item = temp->data;
    *top = (*top)->link;
    free(temp);
    return item;
}
int main(){
    node* stack = NULL;
    stack = push(stack, 1);
    stack = push(stack, 2);
    stack = push(stack, 3);
    printf("%d \n",pop(&stack));

}