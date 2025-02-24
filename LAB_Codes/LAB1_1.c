#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (!root) return createNode(key);
    key < root->key ? (root->left = insert(root->left, key)) : (root->right = insert(root->right, key));
    return root;
}

struct Node* search(struct Node* root, int key) {
    return (!root || root->key == key) ? root : search(key < root->key ? root->left : root->right, key);
}

void traverse(struct Node* root, int order) {
    if (!root) return;
    if (order == 0) printf("%d ", root->key);
    traverse(root->left, order);
    if (order == 1) printf("%d ", root->key);
    traverse(root->right, order);
    if (order == 2) printf("%d ", root->key);
}

int main() {
    struct Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80}, n = sizeof(keys) / sizeof(keys[0]), key;
    for (int i = 0; i < n; i++) root = insert(root, keys[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);
    if (search(root, key)) printf("Key found\n");
    else { printf("Key not found, inserting key...\n"); root = insert(root, key); }

    printf("Inorder: "); traverse(root, 1); printf("\n");
    printf("Preorder: "); traverse(root, 0); printf("\n");
    printf("Postorder: "); traverse(root, 2); printf("\n");
    return 0;
}


