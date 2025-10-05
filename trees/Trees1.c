#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node{
    int data;
    struct Node *right;
    struct Node *left;
} Node;

// Create new node
Node* newnode(int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->right = newnode->left = NULL;
    return newnode;
}

// Stack structure
typedef struct{
    Node* arr[100];
    int top;
} stack;

// Stack functions
void initStack(stack *s){ s->top = -1; }
int isEmpty(stack *s){ return s->top == -1; }
void push(stack *s, Node* node){ s->arr[++(s->top)] = node; }
Node* pop(stack* s){ return s->arr[(s->top)--]; }
Node* peek(stack* s){ return s->arr[s->top]; }

// Inorder Iterative
void inorder(Node *root){
    Node *curr = root;
    stack s; 
    initStack(&s);

    while(curr != NULL || !isEmpty(&s)){
        while(curr != NULL){
            push(&s, curr);
            curr = curr->left;
        }
        curr = pop(&s);
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// Preorder Iterative
void preorder(Node *root){
    if(root == NULL) return;
    stack s; 
    initStack(&s);
    push(&s, root);

    while(!isEmpty(&s)){
        Node *temp = pop(&s);
        printf("%d ", temp->data);

        if(temp->right) push(&s, temp->right);
        if(temp->left) push(&s, temp->left);
    }
}

// Postorder Iterative using two stacks
void postorder(Node *root){
    if(root == NULL) return;

    stack s1, s2;
    initStack(&s1); initStack(&s2);

    push(&s1, root);
    while(!isEmpty(&s1)){
        Node *temp = pop(&s1);
        push(&s2, temp);

        if(temp->left) push(&s1, temp->left);
        if(temp->right) push(&s1, temp->right);
    }

    while(!isEmpty(&s2)){
        printf("%d ", pop(&s2)->data);
    }
}

// Print parent of a node
void printparent(Node *root,int val){
    if(root == NULL) return;
    if((root->right && root->right->data == val) || (root->left && root->left->data == val)){
        printf("Parent of %d is %d\n", val, root->data);
        return;
    }
    printparent(root->left, val);
    printparent(root->right, val);
}

// Height of tree
int Height(Node *root){
    if(root == NULL) return 0;
    int lefth = Height(root->left);
    int righth = Height(root->right);
    return (lefth > righth ? lefth : righth) + 1;
}

// Print ancestors
int printAncestors(Node *root , int target){
    if(root == NULL) return 0;
    if(root->data == target) return 1;
    if(printAncestors(root->left,target) || printAncestors(root->right,target)){
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// Count leaf nodes
int countLeaves(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Main function
int main(){
    Node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    printparent(root, 5);
    printparent(root, 3);

    printf("Height: %d\n", Height(root));

    printf("Ancestors of 5: "); printAncestors(root, 5); printf("\n");

    printf("Leaf count: %d\n", countLeaves(root));

    return 0;
}
