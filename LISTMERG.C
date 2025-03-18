#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;
    struct ListNode* mergedHead;

    while (list1 != NULL && list2 != NULL) {
	if (list1->val <= list2->val) {
	    current->next = list1;
	    list1 = list1->next;
	} else {
	    current->next = list2;
	    list2 = list2->next;
	}
	current = current->next;
    }

    if (list1 != NULL) {
	current->next = list1;
    } else if (list2 != NULL) {
	current->next = list2;
    }

    mergedHead = dummy->next;
    free(dummy);
    return mergedHead;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* inputList() {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* newNode;
    int value;
    printf("Enter values for the linked list (enter -1 to stop):\n");

    while (1) {
	scanf("%d", &value);
	if (value == -1) break;
	newNode = createNode(value);
	if (head == NULL) {
	    head = newNode;
	    tail = head;
	} else {
	    tail->next = newNode;
	    tail = tail->next;
	}
    }
    return head;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    printf("[");
    while (current != NULL) {
	printf("%d", current->val);
	if (current->next != NULL) {
	    printf(", ");
	}
	current = current->next;
    }
    printf("]\n");
    getch();
}

int main() {
    struct ListNode* list1 = inputList();
    struct ListNode* list2 = inputList();
    struct ListNode* mergedList;
    clrscr();
    mergedList = mergeTwoLists(list1,list2);
    printf("Merged list: ");
    printList(mergedList);
    getch();
    return 0;
}