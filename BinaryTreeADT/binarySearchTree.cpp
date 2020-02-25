#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

typedef struct bstNode{
    int value;
    struct bstNode* left;
    struct bstNode* right;
}bstNode;

bstNode* createNode(int value){
    bstNode* temp = (bstNode*)malloc(sizeof(bstNode));
    temp->value = value;
    temp->left = temp->right = NULL;
    return temp;
}

// bstNode* insertNode(bstNode* root, int value){
//     bstNode* newNode = createNode(value);
//     bstNode* temp1 = root;
//     int flag = 0;
//     if(temp1 == NULL){
//         root = newNode;
//         return root;
//     }
//     while(true){
//         if(value < temp1->value){
//             if(temp1->left == NULL){
//                 flag = 0;
//                 break;
//             }
//             temp1 = temp1->left;
//         }
//         else if(value >= temp1->value){
//             if(temp1->right == NULL){
//                 flag = 1;
//                 break;
//             }
//             temp1 = temp1->right;
//         }
//     }
//     if(flag == 0){
//         temp1->left = newNode;
//     }
//     else{
//         temp1->right = newNode;
//     }
//     return root;

// }
//Recursive Implementation

bstNode* insertNode(bstNode* root, int value){
    bstNode* newNode = createNode(value);
    if(root == NULL){
        root = newNode;
    }
    else if(root->value <= value){
        root->right = insertNode(root->right, value);
    }
    else if(root->value > value){
        root->left = insertNode(root->left, value);
    }
    return root;
}

bool search(bstNode* root, int value){
    if(root == NULL){
        return false;
    }
    else if(root->value == value){
        return true;
    }
    else if(root->value <= value){
        return search(root->right, value);
    }
    else if(root->value > value){
        return search(root->left, value);
    }
}


// int findMin(bstNode* root){
//     if(root == NULL){
//         printf("Tree is empty..\n");
//         return -1;
//     }
//     else if(root->value == value){
//         return value;
//     }
//     return findMin(root->left);
// }
bstNode* findMin(bstNode* root){
    if(root == NULL){
        printf("Tree is empty..\n");
        return root;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
int max(int a, int b){
    return a >= b? a : b;
}
int findHeight(bstNode* root){
    if(root == NULL){
        return -1;
    }
    //All these cases are covered by the above case:
    // if(root->left == NULL && root->right == NULL){
    //     return 0;
    // }
    // if(root->left == NULL && root->right != NULL){
    //     return 1 + findHeight(root->right);
    // }
    // if(root->right == NULL && root->left != NULL){
    //     return 1 + findHeight(root->left);
    // }
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

int levelOrderTraversal(bstNode* root){
    if(root == NULL){
        printf("Tree is Empty..\n");
        return -1;
    }
    queue<bstNode*> q;
    q.push(root);
    int height = -1;
    int nodeCount = 1;
    while(true){
        nodeCount = q.size();
        if(nodeCount == 0){
            return height;
        }
        height++;
        while(nodeCount > 0){
            bstNode* current = q.front();
            cout << current->value << " ";
            if(current->left != NULL){
                q.push(current->left);
            }
            if(current->right != NULL){
                q.push(current->right);
            }
            q.pop();
            nodeCount--;
        }
        cout << endl;
    }
}
void preOrderTraversal(bstNode* root){
    if(root == NULL){
        return;
    }
    cout << root->value << endl;
    if(root->left != NULL){
        preOrderTraversal(root->left);
    }
    if(root->right != NULL){
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(bstNode* root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        inOrderTraversal(root->left);
    }

    cout << root->value << endl;
    
    if(root->right != NULL){
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(bstNode* root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        postOrderTraversal(root->left);
    }
    if(root->right != NULL){
        postOrderTraversal(root->right);
    }
    cout << root->value << endl;
}
//Smart implementation
bool isBSTUtil(bstNode* root, int minVal, int maxVal){
    if(root == NULL) 
        return true;
    if(root->value < maxVal && root->value > minVal &&
        isBSTUtil(root->left, minVal, root->value) && isBSTUtil(root->right, root->value, maxVal))
        return true;
    return false;
}

bool isBST(bstNode* root){
    isBSTUtil(root, INT32_MIN, INT32_MAX);
}
bstNode* deleteNode(bstNode* root, int value){
    if(root == NULL) return root;
    else if(value <= root->value) root->left = deleteNode(root->left, value);
    else if(value > root->value) root->right = deleteNode(root->right, value);
    else{
        //Case 1: Leaf Node
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            bstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            bstNode* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            bstNode* temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }        
    }
    return root;
}
bstNode* searchNode(bstNode* root, int value){
    if(root == NULL){
        return root;
    }
    while(root->value != value){
        if(root->value < value){
            root = root->right;
            if(root == NULL){
                return NULL;
            }
        }
        else if(root->value > value){
            root = root->left;
            if(root == NULL){
                return NULL;
            }
        }
    }
    
    return root;
}
bstNode* inOrderSuccessor(bstNode* root, int value){
    if(root == NULL) return root;
    bstNode* current = searchNode(root, value);
    bstNode* successor = NULL;
    if(current == NULL) return NULL;
    else if(current->right != NULL){
        successor = findMin(current->right);
    }
    else{
        bstNode* ancestor = root;
        while (ancestor != current){
            if(current->value < ancestor->value){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
            
    }
    return successor;
}


int main(){
    bstNode* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 12);
    root = insertNode(root, 20);
    root = insertNode(root, 13);
    root = insertNode(root, 22);
    root = insertNode(root, 18);
    root = insertNode(root, 19);

    bstNode* succesor = inOrderSuccessor(root, 19);
    cout << succesor->value << endl;
    // if(search(root, 12)){
    //     printf("Found\n");
    // }
    // else{
    //     printf("Not Found\n");
    // }
    // printf("Recursice Height: %d \n", findHeight(root));
    // preOrderTraversal(root);
    // if(isBST(root))
    //     cout << "YES\n";
    // root = deleteNode(root, 19);
    // preOrderTraversal(root);
    // cout << "Iterative Height: "<< iterativeHeight << endl;
    return 0;

}

// void levelOrderTraversal(bstNode* root){
//     static int flag = 1;               //don't be confused about flag i'm only using it because otherwise every node except the 
//     if(root == NULL)                          //original root node was printing twice
//         return;
//     if(flag){
//         cout<<root->data<<" ";
//         flag = 0;
//     }
//     if(root->left !=NULL && root->right !=NULL){
//         cout<<root->left->data<<" ";
//         cout<<root->right->data<<" ";
//     }
//     else{
//         if(root->left != NULL)
//             cout<<root->left->data<<" ";
//         else if(root->right != NULL)
//         {
//             cout<<root->right->data<<" ";
//         }
//     }
//     printTree(root->left);
//     printTree(root->right);  
// }

//Naive Implementation
// bool isSubTreeGreater(bstNode* root, int value){
//     if(root == NULL) return true;
//     if(root->data > value && isSubTreeGreater(root->left, value) 
//         && isSubTreeGreater(root->right, value))
//         return true;
//     return false;
// }
// bool isSubTreeLesser(bstNode* root, int value){
//     if(root == NULL) return true;
//     if(root->data <= value && isSubTreeLesser(root->left, value) 
//         && isSubTreeLesser(root->right, value))
//         return true;
//     return false;
// }
// bool isBST(bstNode* root){
//     if(root == NULL) 
//         return true;
//     if(isSubTreeGreater(root->right, root->data) && isSubTreeLesser(root->left, root->data) &&
//         isBST(root->left) && isBST(root->right))
//         return true;
//     return false;
// }

