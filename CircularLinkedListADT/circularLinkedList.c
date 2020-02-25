#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;
void printList(node*);
node* createNode(int);
node* insertNodeAtEnd(node*, int);
node* insertNodeAtBegin(node*, int);
node* insertNodeAfter(node*, int, int);
node* deleteNodeAtBegin(node*);
node* deleteNodeAtEnd(node*);
node* deleteNodeAfter(node*, int);

node* deleteNodeAfter(node* last, int refValue){
    if(last == NULL){
        printf("List is empty..\n");
        return last;
    }

    if(last == last->link){
        printf("List only has one element..\n");
        return last;
    }
    node* temp1 = last->link;
    node* temp2 = NULL;
    
    do{
        if(temp1->data == refValue){
            temp2 = temp1->link;
            if(temp1->link == last){
                last = temp1;
            }
            temp1->link = temp2->link;
            free(temp2); 
            return last;     
        }
        temp1 = temp1->link;

    }
    while(temp1 != last->link);
    printf("Reference Value does not exist..\n");
}

node* deleteNodeAtBegin(node* last){
    if(last == NULL){
        printf("List is empty..\n");
        return last;
    }
    if(last == last->link){
        free(last);
        return NULL;
    }
    node* temp1 = last->link;
    last->link = last->link->link;
    free(temp1);
    return last;
}

node* deleteNodeAtEnd(node* last){
    if(last == NULL){
        printf("List is empty..\n");
        return last;
    }
    node* temp1 = last->link;
    while(temp1->link != last){
        temp1 = temp1->link;
    }
    node* temp2 = last;
    temp1->link = last->link;
    if(last == last->link){
        temp1 = NULL;
    }
    last = temp1;
    free(temp2);
    return last;
}

node* insertNodeAfter(node* last, int refValue, int newValue){
    if(last == NULL){
        printf("List is empty..\n");
        return last;
    }
    node* temp = last->link;
    node* newNode = NULL;
    do{
        if(temp->data == refValue){
            newNode = createNode(newValue);
            newNode->link = temp->link;
            temp->link = newNode;
            if(temp == last){
                last = newNode;
            }
            return last;
        }
        temp = temp->link;
    }
    while(temp != last->link);
    printf("Reference Value does not exist..\n");
}

node* insertNodeAtBegin(node* last, int value){
    node* newNode = createNode(value);
    if(last == NULL){
        last = newNode;
        last->link = last;
        return last;
    }
    newNode->link = last->link;
    last->link = newNode;
    return last;

}

node* insertNodeAtEnd(node* last,int value){
    last = insertNodeAtBegin(last, value);          // node* newNode = createNode(value);
    last = last->link;                              // if(last == NULL){
                                                    //     last = newNode;
     return last;                                   //     last->link = last;
 }                                                  //     return last;
                                                    // }
                                                    // newNode->link = last->link;
                                                    // last->link = newNode;
                                                    // last = newNode;
    

node* createNode(int value){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->link = NULL;
    return temp;
}

void printList(node* last){
    if(last == NULL){
        printf("List is empty..\n");
        return;
    }
    node* temp = last->link;
    do{
        printf("%d ", temp->data);
        temp = temp->link;
    }
    while(temp != last->link);
    printf("\n");
}

int main(){
    node* last = NULL;
    last = insertNodeAtBegin(last, 3);
    last = insertNodeAtBegin(last, 5);
    last = insertNodeAtBegin(last, 6);
    last = insertNodeAtEnd(last, 4);
    last = insertNodeAtEnd(last, 11);
    last = insertNodeAtEnd(last, 9);
    printList(last);
    last = insertNodeAfter(last, 6, 555);
    printList(last);
    last = deleteNodeAfter(last, 9);
    printList(last);
}