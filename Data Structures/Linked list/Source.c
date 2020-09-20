//////////////////////////////////////////
//										//	
//	Written by - Shivam Singh			//
//	Github - 1502shivam-singh			//
//	Singly linked list implementation	//
//	Will convert this in a header		//
//										//
//////////////////////////////////////////		

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}node;

//////////////////////////////////////
/*
void exchange(node* ptr1, node* ptr2) {
	int hold = ptr1->data;
	ptr1->data = ptr2->data;
	ptr2->data = hold;
}

node* reverseList(node* head) {		//Slower brute force approach in O(n^2) time and constant space
	node* startHold = head;
	int size = 0, i = 0;
	while (startHold != NULL) {
		size++;
		startHold = startHold->next;
	}
	startHold = head;
	node* Hold2 = NULL;
	while (size>0) {
		Hold2 = startHold;
		for (int i = 0; i<size - 1; i++) {
			Hold2 = Hold2->next;
		}
		exchange(startHold, Hold2);
		size -= 2;
		startHold = startHold->next;
	}
	return head;
}*/

node* reverseList(node* head) {		//Faster approach in O(n) time and constant space to reverse the list
	if (head != NULL) {
		node* h1 = NULL;
		node* sh = head;
		node* pnode = sh->next;
		while (pnode != NULL) {
			sh->next = h1;
			h1 = sh;
			sh = pnode;
			pnode = pnode->next;
		}
		sh->next = h1;
		return sh;
	}
	else { return NULL; }
}

//////////////////////////////////////


node* CreateLL(int* arrayHead, int size);  //Creates a link list of length "size" and with elements of array "arrayHead", and returns pointers to its head node

void __LL_CleanUpR__(node* ptr);	//Recursively cleans up the linkedlist nodes allocated using malloc

void __LL_CleanUpI__(node* ptr);	//Iteratively cleans up the linkedlist nodes allocated using malloc

void destructor(node* head, int* arr, int choice);	//Deallocates all the memory allocated on the heap in the program

node* insertNode(int pos, node* headLL, int val, int size);	//Inserts a node with data "val" at position "pos" (pos value starts from 0)

void traversal(node* head);	//Prints the elements in the linked list

node* deletion(node* head, int pos, int size);	//Deletes a node at position "pos" (pos value starts from 0)



int main() {
	int listSize, val;
	printf("Enter size of linked list\n");
	scanf_s("%d", &listSize);
	int* head = (int*)malloc(listSize*sizeof(int));

	printf("Enter number\n");
	for (int i = 0; i < listSize; i++) {
		scanf_s("%d", &val);
		head[i] = val;
	}

	node* headLL = CreateLL(head, listSize);
	headLL = reverseList(headLL);
	traversal(headLL);
	//headLL = insertNode(0, headLL, 99, listSize);
	//traversal(headLL);
	//headLL = deletion(headLL, 0, listSize);
	//traversal(headLL);
	//destructor(headLL, head, 1);
	
	_getch();
}



node* CreateLL(int* arrayHead, int size) {
	if(size == 0){		//Empty linked list case
		return NULL;
	}
	else {
		node* headLL = (node*)malloc(sizeof(node));
		headLL->next = NULL;
		node* prev = headLL;
		for (int i = 0; i < size; i++) {
			if (i != 0 && i != size - 1) {
				node* pnode = (node*)malloc(sizeof(node));
				pnode->next = NULL;
				pnode->data = arrayHead[i];
				prev->next = pnode;

				prev = pnode;
				pnode = NULL;
			}
			else if (i == size - 1 && size != 1) {
				node* pnode = (node*)malloc(sizeof(node));
				pnode->next = NULL;
				pnode->data = arrayHead[i];
				prev->next = pnode;
				pnode = NULL;
			}
			else {
				prev->data = arrayHead[i];
			}
		}
		prev = NULL;
		return headLL;
	}
}

node* insertNode(int pos, node* headLL, int val, int size) {
	if (size < pos) {		//pos value greater than size case
		printf("Error : position past size value by more than 1");	
		return NULL;
	}
	else {
		if (pos == 0) {		//Insertion at start
			node* Nnode = (node*)malloc(sizeof(node));
			Nnode->next = headLL;
			Nnode->data = val;
			headLL = Nnode;
			Nnode = NULL;
			return headLL;
		}
		else {		//Insertion in middle
			node* store = headLL;
			for (int i = 0; i < pos; i++) {
				if (i == pos - 1) {
					node* Nnode = (node*)malloc(sizeof(node));
					Nnode->next = store->next;
					Nnode->data = val;
					store->next = Nnode;
					Nnode = NULL;
					store = NULL;
				}
				else {
					store = store->next;
				}
			}
			return headLL;
		}
	}
}

void __LL_CleanUpR__(node* ptr) {	//Recursive cleanup function
	if (ptr == NULL) {
		//do nothing
	}
	else {
		if (ptr->next != NULL) {
			__LL_CleanUpR__(ptr->next);
		}
		free(ptr);		//Free the memory pointing to the allocated blocks of linked list
		ptr = NULL;		//Removing dangling pointers
	}
}

void __LL_CleanUpI__(node* ptr) {	//Iterative cleanup function
	node* hold;
	while (ptr != NULL) {
		hold = ptr->next;

		ptr->next = NULL;	
		free(ptr);		//Free the memory pointing to the allocated blocks of linked list
		ptr = NULL;		//Removing dangling pointers

		ptr = hold;
	}
}

void destructor(node* head, int* arr, int choice) {
	free(arr);
	arr = NULL;
	if (choice == 1) {	//recursive of iterative choice
		__LL_CleanUpR__(head);	//Recursive cleanup
	}
	else {
		__LL_CleanUpI__(head);	//Iterative cleanup
	}
}

void traversal(node* head) {
	node* deleteStore = head;

	while (deleteStore != NULL) {
		printf("%d\n", deleteStore->data);
		deleteStore = deleteStore->next;
	}
	deleteStore = NULL;
}

node* deletion(node* head, int pos, int size) {		//Deletes the i-th node in singly linked list (pos values start from 0 as in array)
	if (size < pos || pos < 0) {	//Case when pos greater than size or pos is negative
		printf("Error : position value past size or negative");
		return NULL;
	}
	else {	//Deleting at start
		node* deleteStore = head;
		if (pos == 0) {
			deleteStore = deleteStore->next;
			free(head);
			if (deleteStore == NULL) {
				head = NULL;
			}
			else {
				head = deleteStore;
			}
		}
		else {		//Deleting in the middle
			for (int i = 0; i < pos; i++) {
				if (i == pos - 1) {
					node* Nhold = deleteStore->next;
					deleteStore->next = deleteStore->next->next;
					Nhold->next = NULL;
					free(Nhold);
					Nhold = NULL;
				}
				else {
					deleteStore = deleteStore->next;
				}
			}
		}
		deleteStore = NULL;
		return head;
	}
}