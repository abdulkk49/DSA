#include<iostream>
#include<string.h>
#include"stdio.h"
#include<stdlib.h>
#include<stack>

using namespace std;
class Mystack{
    private:
        struct node{
            char data;
            node* link;   
        };
        node* top;

    public:
        Mystack(){
            top = NULL;
        }
        void push(char);
        void pop();
        bool empty();
        char tops();
        void printList();
        ~Mystack(){
            while(top!=NULL)
                pop();
        }
};

char Mystack::tops(){
    if(top == NULL)
        return 0;
    return top->data;
}

bool Mystack::empty(){
    if(top == NULL){
        return true;
    }
    return false;
}
void Mystack::push(char value){
    node* newNode = new node;
    newNode->data = value;
    newNode->link = top;
    top = newNode;
}

void Mystack::pop(){
    if(top == NULL){
        printf("Underflow..\n");
        return;
    }
    node* temp = top;
    // char item = temp->data;
    top = top->link;
    delete(temp);
}

void Mystack::printList(){
    if(top == NULL){
        cout<<"Hard Luck"<<endl;
        return;
    }
    node* temp = top;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

bool isBalanced(string str){
    Mystack s1;
    for(int i = 0; i<str.length(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s1.push(str[i]);
        }
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')'){
            if(s1.empty() || (s1.tops() != '(' && str[i] == ')') || (s1.tops() != '{' && str[i] == '}') || (s1.tops() != '[' && str[i] == ']'))
                return false;
            else
                s1.pop();
        }
    }
    return s1.empty();
}
int main(){
    string str;
    cout << "Enter a string:\n";
    getline(cin, str);
    if(isBalanced(str)){
        cout <<"YES"<< endl;
    }    
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}