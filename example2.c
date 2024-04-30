#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
   int data;
   struct Node* left;
   struct Node* right;
} Node;

Node* createNode(int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

Node* insertNode(Node* root, int data) {
   if (root == NULL) {
       return createNode(data);
   }

   if (data < root->data) {
       root->left = insertNode(root->left, data);
   } else if (data > root->data) {
       root->right = insertNode(root->right, data);
   }

   return root;
}

void inorderTraversal(Node* root) {
   if (root != NULL) {
       inorderTraversal(root->left);
       printf("%d ", root->data);
       inorderTraversal(root->right);
   }
}

int calculateHeight(Node* root) {
   if (root == NULL) {
       return 0;
   }

   int leftHeight = calculateHeight(root->left);
   int rightHeight = calculateHeight(root->right);

   return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int calculateSize(Node* root) {
   if (root == NULL) {
       return 0;
   }

   return calculateSize(root->left) + calculateSize(root->right) + 1;
}

void freeTree(Node* root) {
   if (root != NULL) {
       freeTree(root->left);
       freeTree(root->right);
       free(root);
   }
}

int main() {
   Node* root = NULL;
   int numNodes, data;
   printf("Enter the number of nodes: ");
   scanf("%d", &numNodes);

   printf("Enter the data for each node:\n");
   for (int i = 0; i < numNodes; i++) {
       scanf("%d", &data);
       root = insertNode(root, data);
   }

   printf("\nInorder traversal: ");
   inorderTraversal(root);

   int height = calculateHeight(root);
   int size = calculateSize(root);

   printf("\nHeight of the tree: %d", height);
   printf("\nSize of the tree: %d\n", size);

   freeTree(root);

   return 0;
}