#include<stdio.h>
#include<conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
	printf("Memory allocation failed.\n");
	exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
	*head = newNode;
    } else {
	struct Node* temp = *head;
	while (temp->next != NULL) {
	    temp = temp->next;
	}
	temp->next = newNode;
    }
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    int i=0;
    if (position == 1) {
	insertAtBeginning(head, data);
	return;
    }

    for (i = 1; temp != NULL && i < position - 1; i++) {
	temp = temp->next;
    }

    if (temp == NULL) {
	printf("The position is greater than the length of the list.\n");
    } else {
	newNode->next = temp->next;
	temp->next = newNode;
    }
}


void deleteAtBeginning(struct Node** head) {
    struct Node* temp = *head;
    if (*head == NULL) {
	printf("The list is empty.\n");
	return;
    }

    *head = (*head)->next;
    free(temp);
    printf("Node deleted at the beginning.\n");
}


void deleteAtEnd(struct Node** head) {
    struct Node* temp = *head;
    if (*head == NULL) {
	printf("The list is empty.\n");
	return;
    }

    if (temp->next == NULL) {
	*head = NULL;
	free(temp);
	printf("Node deleted at the end.\n");
	return;
    }

    while (temp->next != NULL && temp->next->next != NULL) {
	temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted at the end.\n");
}

void deleteAtPosition(struct Node** head, int position) {
    struct Node* temp = *head;
    int i=0;
    if (*head == NULL) {
	printf("The list is empty.\n");
	return;
    }

    if (position == 1) {
	*head = (*head)->next;
	free(temp);
	printf("Node deleted at position %d.\n", position);
	return;
    }

    for (i = 1; temp != NULL && i < position - 1; i++) {
	temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
	printf("Position is out of range.\n");
    } else {
	struct Node* toDelete = temp->next;
	temp->next = temp->next->next;
	free(toDelete);
	printf("Node deleted at position %d.\n", position);
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
	printf("The list is empty.\n");
	return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
	printf("%d -> ", temp->data);
	temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    clrscr();
    while (1) {
	printf("\nLinked List Operations\n");
	printf("1. Insert at the beginning\n");
	printf("2. Insert at the end\n");
	printf("3. Insert at a specific position\n");
	printf("4. Delete at the beginning\n");
	printf("5. Delete at a specific position\n");
	printf("6. Delete at the end\n");
	printf("7. Display the list\n");
	printf("8. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter the data to insert at the beginning: ");
		scanf("%d", &data);
		insertAtBeginning(&head, data);
		break;

	    case 2:
		printf("Enter the data to insert at the end: ");
		scanf("%d", &data);
		insertAtEnd(&head, data);
		break;

	    case 3:
		printf("Enter the data to insert: ");
		scanf("%d", &data);
		printf("Enter the position at which to insert: ");
		scanf("%d", &position);
		insertAtPosition(&head, data, position);
		break;

	    case 4:
		deleteAtBeginning(&head);
		break;

	    case 5:
		printf("Enter the position to delete: ");
		scanf("%d", &position);
		deleteAtPosition(&head, position);
		break;

	    case 6:
		deleteAtEnd(&head);
		break;

	    case 7:
		displayList(head);
		break;

	    case 8:
		printf("Exiting program.\n");
		exit(0);

	    default:
		printf("Invalid choice. Please try again.\n");
	}
    }
    getch();
    return 0;
}
