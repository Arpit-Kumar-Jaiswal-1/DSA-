#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

// Function to find minimum value node
struct Node* findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to find maximum value node
struct Node* findMax(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("Enter number of values: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    struct Node* minNode = findMin(root);
    struct Node* maxNode = findMax(root);

    if (minNode != NULL)
        printf("Minimum value in BST: %d\n", minNode->key);
    if (maxNode != NULL)
        printf("Maximum value in BST: %d\n", maxNode->key);

    return 0;
}
