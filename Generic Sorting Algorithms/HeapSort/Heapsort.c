#include<stdio.h>
#include<stdlib.h>

/*
	Utility functions -
	left(int* arr, int pos) => returns 2*pos+1;
	right(int* arr, int pos) => returns 2*pos+2;
	parent(int* arr, int pos) => returns pos % 2 ? pos/2 -1: pos/2;
	int maxoff(int a, int b, int c) => returns greatest of [a,b,c];
*/

int left(int* arr, int pos) { return 2 * pos + 1; }
int right(int* arr, int pos) { return 2 * pos + 2; }
int parent(int* arr, int pos) { return pos % 2 ? pos / 2 - 1 : pos / 2; }
int maxoff(int* arr, int a, int b, int c) 
{
	if (arr[a] >= arr[b] && arr[a] >= arr[c]) { return a; }
	else if (arr[b] >= arr[c]) { return b; }
	else { return c; }
}
/*
	Building max-heap -
	maxHeapify(int* arr, int pos, int size) => compares the three numbers in the subtree of the binary heap and makes the heap
	buildHeap(int* arr, int size) => Calls max-heapify succesively in backward fashion
*/

void maxHeapify(int* arr, int pos, int size)
{
	int max = 0;
	if (left(arr, pos) > size) {
		max = -1;
	}
	else if (right(arr, pos) > size) {
		max = arr[pos] > arr[left(arr, pos)] ? pos : left(arr, pos);
	}
	else {
		max = maxoff(arr, pos, left(arr, pos), right(arr, pos));
	}
	if (max != pos && max != -1) {
		int hold = arr[pos];
		arr[pos] = arr[max];
		arr[max] = hold;
		maxHeapify(arr, max, size);
	}
}

void buildHeap(int* arr, int size) 
{
	for (int i = size/2; i >= 0; i--) {
		maxHeapify(arr, i, size);
	}
}

void heapSort(int* arr, int size) {
	int holdSize = size;
	for (int i = size; i >= 0; i--) 
	{
		buildHeap(arr, size);
		int hold = arr[size];
		arr[size] = arr[0];
		arr[0] = hold;
		size--;
	}
}

int main() 
{
	int size;
	printf("Enter the number of elements in the array\n");
	scanf_s("%d", &size);
	int* arr = malloc(sizeof(int)*size);
	printf("Enter the elements in the array\n");
	for (int i = 0; i < size; i++) 
	{
		scanf_s("%d", &arr[i]);
	}
	heapSort(arr, size-1);
	printf("\nArray after sorting through heapsort algorithm is :\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}