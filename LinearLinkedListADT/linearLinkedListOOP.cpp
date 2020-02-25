#include<iostream>
using namespace std;

class LinearLinkedList{
    private:
        struct node{
        int data;
        node* link;
        };
        node* start;
        int size;

    public:
        LinearLinkedList(){
            start = NULL;
            size = 0;
        }
        void printList();
        node* createNode(int);
        void insertNodeAtEnd(int);
        void insertNodeAtBegin(int);
        void insertNodeAtPosition(int, int);
        void deleteNodeAtBegin();
        void deleteNodeAtEnd();
        void deleteNodeByValue(int);
        void deleteNodeAtPosition(int);
        void reverseList();
        ~LinearLinkedList(){
            while(start!=NULL){
                deleteNodeAtBegin();
            }
        }
};


//Node Creation by DMA
LinearLinkedList::node* LinearLinkedList::createNode(int value){
    node* temp = new node();
    temp->link = NULL;
    temp->data = value;
    return temp;
}

//Add at end of list
void LinearLinkedList::insertNodeAtEnd(int value){
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

//Add at beginningof list
void LinearLinkedList::insertNodeAtBegin(int value){
    node* newNode = createNode(value);
    newNode->link = start;
    start = newNode;
    size++;
}

//Add by index position
void LinearLinkedList::insertNodeAtPosition(int pos, int value){
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
void LinearLinkedList::deleteNodeAtBegin(){
    if(start == NULL){
        printf("List is Empty..");
        return;
    }
    node* temp = start;
    start = start->link;
    size--;
    delete(temp);
}

//delete from end
void LinearLinkedList::deleteNodeAtEnd(){
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
    delete(temp);
}

//delete by index
void LinearLinkedList::deleteNodeAtPosition(int pos){
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
    delete(temp);
    size--;
}

//delete by value
void LinearLinkedList::deleteNodeByValue(int value){
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
    delete(temp1);
    size--;
}

//Reverse the list
void LinearLinkedList::reverseList(){
    node *temp1 = NULL, *temp2 = NULL;
    while(start != NULL){
        temp2 = start->link;
        start->link = temp1;
        temp1 = start;
        start = temp2;
    }
    start = temp1;
}

void LinearLinkedList::printList(){
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
    LinearLinkedList l1;
    l1.deleteNodeAtPosition(3);
    printf("\n");
    l1.deleteNodeAtEnd();
    printf("\n");
    l1.insertNodeAtPosition(4, 34);
    printf("\n");

    //List
    printf("Creating List..\n");
    l1.insertNodeAtPosition(0, 1001);
    l1.insertNodeAtBegin(3);
    l1.insertNodeAtBegin(4);
    l1.insertNodeAtBegin(2);
    l1.insertNodeAtBegin(1);
    l1.insertNodeAtEnd(23);
    l1.insertNodeAtEnd(24);
    l1.printList();
    l1.insertNodeAtPosition(4, 34);
    l1.printList();
    l1.insertNodeAtPosition(7, 100);
    l1.printList();


    printf("Reversing...\n");

    
    l1.reverseList();
    l1.printList();
    l1.insertNodeAtPosition(9, 101);
    l1.deleteNodeAtBegin();
    l1.printList();
    l1.deleteNodeAtPosition(3);
    l1.printList();
    l1.deleteNodeByValue(99);
    l1.printList();
    l1.deleteNodeByValue(1);
    l1.printList();
    return 0;
}
