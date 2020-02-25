#include<iostream>
using namespace std;

class stack{
    private:
        struct node{
            int data;
            node* link;   
        };
        node* top;

    public:
        stack(){
            top = NULL;
        }
        void push(int);
        int pop();
        int tops();
};
int stack::tops(){
    return top->data;
}

void stack::push(int value){
    node* newNode = new node();
    newNode->data = value;
    newNode->link = top;
    top = newNode;
}

int stack::pop(){
    if(top == NULL){
        printf("Underflow..\n");
        return 0;
    }
    node* temp = top;
    int item = temp->data;
    top = (top)->link;
    free(temp);
    return item;
}
int main(){
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    printf("%d \n",s1.tops());
    printf("%d \n",s1.pop());
    
    printf("%d \n",s1.pop());

}