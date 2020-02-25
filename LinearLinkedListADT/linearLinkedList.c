#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

//Global Access
node* start = NULL;
int size = 0;

void printList();
node* createNode(int);
void insertNodeAtEnd(int);
void insertNodeAtBegin(int);
void insertNodeAtPosition(int, int);
void deleteNodeAtBegin();
void deleteNodeAtEnd();
void deleteNodeByValue(int);
void deleteNodeByPosition(int);

//Node Creation by DMA
node* createNode(int value){
    node* temp = (node*)malloc(sizeof(node));
    temp->link = NULL;
    temp->data = value;
    return temp;
}

//Add at end of list
void insertNodeAtEnd(int value){
    node* newNode = createNode(value);
    if(start == NULL){
        start = newNode;
        size++;
        return;
    }
    node* temp = start;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = newNode;
    size++;
}

//Add at beginning of list
void insertNodeAtBegin(int value){
    node* newNode = createNode(value);
    start = newNode;
    newNode->link = start;
    size++;
}

//Add by index position
void insertNodeAtPosition(int pos, int value){
    if(pos < 0){
        printf("Negative Index not allowed");
    }

    if(pos >= size + 1){
        printf("Missing Index..");
        return;
    }
    if(start == NULL && pos > 0){
        printf("Invalid index.. List is empty. \n");
        return;
    }
    node* newNode = createNode(value);
    if(pos == 0){
        newNode->link = start;
        start = newNode;
        size++;
        return;
    }
    node* temp = start;
    while(pos != 1){
        temp = temp->link;
        pos--;
    }
    newNode->link = temp->link;
    temp->link = newNode;
    size++;
}

//delete from beginning
void deleteNodeAtBegin(){
    if(start == NULL){
        printf("List is Empty..");
        return;
    }
    node* temp = start;
    start = start->link;
    size--;
    free(temp);
}

//delete from end
void deleteNodeAtEnd(){
    if(start == NULL){
        printf("List is Empty..");
        return;
    }
    node* temp = start;
    node* temp2 = NULL;
    while(temp->link != NULL){
        temp2 = temp;
        temp = temp->link;
    }
    temp2->link = NULL;
    size--;
    free(temp);
}

//delete by index
void deleteNodeAtPosition(int pos){
    if(pos < 0){
        printf("Negative Index not allowed");
        return;
    }

    if(start == NULL){
        printf("List is Empty..");
        return;
    }

    if(pos >= size + 1){
        printf("Missing Index..");
        return;
    }
    
    node* temp = start;
   
    if(pos == 0){
        start = start->link;
        free(temp);
        size--;
        return;
    }

    node* temp2 = NULL;
    while(pos != 0){
        temp2 = temp;
        temp = temp->link;
        pos--;
    }
    temp2->link = temp->link;
    free(temp);
    size--;
}

//delete by value
void deleteNodeByValue(int value){
    if(start == NULL){
        printf("List is Empty..");
        return;
    }
    node* temp1 = start, *temp2 = NULL;
    while(temp1 != NULL && temp1->data != value){
        temp2 = temp1;
        temp1 = temp1->link;
    }
    if(temp1 == NULL){  //Reaches the end and does not find the element
        printf("Value does not exist..\n");
        return;
    }
    temp2->link = temp1->link;
    free(temp1);
    size--;
}

//Reverse the list
void reverseList(){
    node *temp1 = NULL, *temp2 = NULL;
    while(start != NULL){
        temp2 = start->link;
        start->link = temp1;
        temp1 = start;
        start = temp2;
    }
    start = temp1;
}

void printList(){
    node* temp = start;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

//driver main
int main(){

    //Boundary Check
    printf("Bundary Check\n");
    deleteNodeAtPosition(3);
    printf("\n");
    deleteNodeAtEnd();
    printf("\n");
    insertNodeAtPosition(4, 34);
    printf("\n");

    //List
    printf("Creating List..\n");
    insertNodeAtPosition(0, 1001);
    insertNodeAtStart(3);
    insertNodeAtStart(4);
    insertNodeAtStart(2);
    insertNodeAtStart(1);
    insertNodeAtEnd(23);
    insertNodeAtEnd(24);
    printList();
    insertNodeAtPosition(4, 34);
    printList();
    insertNodeAtPosition(7, 100);
    printList();
    printf("Reversing...\n");
    reverseList();
    printList();
    insertNodeAtPosition(9, 101);
    deleteNodeAtBegin();
    printList();
    deleteNodeAtPosition(3);
    printList();
    deleteNodeByValue(99);
    printList();
    deleteNodeByValue(1);
    
    printList();
    return 0;
}