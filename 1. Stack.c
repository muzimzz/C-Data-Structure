#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STACK_SIZE 5
#define TRUE 1;
#define FALSE 0;

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty()	// return (top == -1)
{
	if (top < 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int isFull() 
{
	if (top >= MAX_STACK_SIZE - 1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void push(element item) 
{
	if (isFull()) {
		fprintf(stderr, "Stack is Full.\n");
		return;
	}
	else {
		stack[++top] = item;
		return;
	}
}

element pop() {
	if (isEmpty()) {
		fprintf(stderr, "Stack is Empty.\n");
	}
	else {
		return stack[top--];
	}
}

void peek() {
	printf("top: %d\n", stack[top]);
	return;
}

void printStack() {

	printf("Stack: ");

	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stack[i]);
	}

	printf("\n");
	return;
}

int main()
{
	int select = 1;
	int n = 1;

	while (select != 0) {

		printf("0. 종료하기\n");
		printf("1. Stack 출력\n");
		printf("2. push\n");
		printf("3. pop\n");
		printf("4. peek\n");
		printf("무엇을 하시겠습니까?: ");
		scanf("%d", &select);

		switch (select) {
		case 0:
			return;
		case 1:
			printStack();
			break;
		case 2:
			if (!isFull()) {
				printf("push할 수를 입력하세요: ");
				scanf("%d", &n);
				printf("push (%d)\n", n);
				push(n);
			}
			else {
				printf("Stack is Full.\n");
			}		
			break;
		case 3:
			if (!isEmpty()) {
				printf("pop (%d)\n", pop());
			}
			else {
				printf("Stack is Empty.\n");
			}
			break;
		case 4:
			peek();
			break;
		default:
			printf("잘못된 입력입니다.\n");
		}
	};

	return 0;
}