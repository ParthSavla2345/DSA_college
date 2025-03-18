#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10

int count = 0;

struct stack {
    char items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s) {
    s->top = -1;
}

int isfull(st *s) {
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty(st *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(st *s, char newitem) {
    if (isfull(s)) {
        printf("STACK FULL\n");
    } else {
        s->top++;
        s->items[s->top] = newitem;
    }
    count++;
}

char pop(st *s) {
    if (isempty(s)) {
        printf("\nSTACK EMPTY\n");
        return -1;
    } else {
        char item = s->items[s->top];
        s->top--;
        count--;
        return item;
    }
}

char peek(st *s) {
    if (isempty(s)) {
        return -1;
    } else {
        return s->items[s->top];
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') {
	return 1;
    } else if (op == '*' || op == '/') {
	return 2;
    } else {
	return 0;
}
}
int isOpening(char c) {
    return (c == '(' || c == '[' || c == '{');
}

int isClosing(char c) {
    return (c == ')' || c == ']' || c == '}');
}

int matchingOpening(char c) {
    if (c == ')') return '(';
    if (c == ']') return '[';
    if (c == '}') return '{';
    return -1;
}

void infixToPostfix(char* infix) {
    st* s = (st*)malloc(sizeof(st));
    int i = 0, k = 0;
    char postfix[MAX];
    createEmptyStack(s);

    while (infix[i] != '\0') {
	if (isalnum(infix[i])) {

	    postfix[k++] = infix[i];
	} else if (isOpening(infix[i])) {

	    push(s, infix[i]);
	} else if (isClosing(infix[i])) {

	    while (!isempty(s) && peek(s) != matchingOpening(infix[i])) {
		postfix[k++] = pop(s);
	    }
	    pop(s);
	} else {

	    while (!isempty(s) && precedence(peek(s)) >= precedence(infix[i])) {
		postfix[k++] = pop(s);
	    }
	    push(s, infix[i]);
	}
	i++;
    }

    while (!isempty(s)) {
	postfix[k++] = pop(s);
    }

    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    clrscr();
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    getch();
    return 0;
}