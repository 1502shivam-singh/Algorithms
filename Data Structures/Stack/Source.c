#include <stdio.h>
#include <stdlib.h>

/*
Creating a stack data structure -
	components -
		1) Stack item - a struct in this case (a primitive data type would also work)
		2) a pointer that stores address of top item.
		3) Three functions push, pop and peek.
	
	Stack would be a dynamic array on which the items would be pushed 
	Create a new dynamic array everytime on push and copy elements from previous and delete previous array.
*/

typedef struct StackItem
{
	int data;
}item;

void freeStack(item* remPtr) {
	free(remPtr);
}
	
item* ptrP = NULL;
item* ptrR = NULL;
item* peek = NULL;
int size = 0;

void push(int value) {
	size++;
	ptrP = malloc(size*sizeof(item));
	if (ptrR != NULL) {
		for (int i = 0; i < size - 1; i++) {
			ptrP[i].data = ptrR[i].data;
		}
	}
	ptrP[size - 1].data = value;
	peek = &ptrP[size - 1];
	if (ptrR != NULL) {
		freeStack(ptrR);
	}
	ptrR = ptrP;
	ptrP = NULL;
}

void pop() {
	if (size > 0) {
		ptrR = realloc(ptrR, (size - 1) * sizeof(item));	//shrinks the array by 1
		if (ptrR == NULL) {
			free(ptrR);
		}
		else {
			size--;
			if (size > 0) {
				peek = &ptrR[size - 1];
			}
			else {
				peek = NULL;
			}
		}
	}
	else {
		printf("Stack empty");
	}
}

int Peek() {
	if (peek != NULL) {
		return peek->data;
	}
	else {
		printf("stack-empty");
		return -1;
	}
}

int main() {
	push(1);
	push(2);
	push(3);
	printf("%d\n", Peek());		//prints 3 to console
	pop();						//pops 3 from stack			
	printf("%d\n", Peek());		//prints 2 to console
	pop();						//pops 2 from stack
	printf("%d\n", Peek());		//prints 1 to the console
	pop();						//pops 1 from stack
	pop();						//stack-emptied, so prints "stack-empty" to the console
	push(123);					//pushes 123 to the stack
	pop();						//pops 2 from stack		
	pop();						//stack-emptied, so prints "stack-empty" to the console
	pop();						//stack-emptied, so prints "stack-empty" to the console
}
