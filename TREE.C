#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
	return createNode(value);
    }
    if (value < root->value) {
	root->left = insert(root->left, value);
    } else {
	root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
	inorder(root->left);
	printf("%d ", root->value);
	inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
	printf("%d ", root->value);
	preorder(root->left);
	preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->value);
    }
}

void displayTree(struct Node* root, int choice) {
    switch (choice) {
	case 1:
	    printf("In-order Traversal: ");
	    inorder(root);
	    break;
	case 2:
	    printf("Pre-order Traversal: ");
	    preorder(root);
	    break;
	case 3:
	    printf("Post-order Traversal: ");
	    postorder(root);
	    break;
	default:
	    printf("Invalid choice!\n");
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int i,choice;
    int values[] = {6, 4, 8, 5, 9, 7};
    int n = sizeof(values) / sizeof(values[0]);
    clrscr();
    for (i = 0; i < n; i++) {
	root = insert(root, values[i]);
    }

    choice;
    printf("Choose a traversal method:\n");
    printf("1. In-order\n");
    printf("2. Pre-order\n");
    printf("3. Post-order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    displayTree(root, choice);
    getch();
    return 0;
}
