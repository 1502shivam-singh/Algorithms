#include<iostream>
#include<conio.h>
#include<vector>

void mergesort(std::vector<int>&,int,int); 
//Description-- 1) divides the array into to part recursively, 2) Calls the merge function recursively on each sub-array, 3)Sorted array obtained  

void merge(int, int, int, std::vector<int>& );
//Description-- Combines to arrays on the basis of comparison. Each array can be considered a stack and every time the logic choses the bigger number or smaller number (Depending upon the sort, here smaller) from the two numbers on the top the stack and pushes it in a vector. Continuously doing this creates an ascending order array consisting the two considered sub-arrays.

int main() {
	int size,val;
	std::vector<int> vec;
	std::cout << "Enter the number of elements to be sorted" << std::endl;
	std::cin >> size;
	std::cout << "Enter the values" << std::endl;
	for (int i = 0;i < size;i++) {
		std::cin >> val;
		vec.push_back(val);
	}
	mergesort(vec, 0, size - 1);
	for (int i = 0;i < size;i++) {
		std::cout << vec[i]<<" ";
	}
	_getch();
}
void merge(int start, int mid , int end,std::vector<int>& vec) {
	std::vector<int> left;
	std::vector<int> right;
	for (int i = start;i <= mid;i++) {
		left.push_back(vec[i]);
	}
	for (int i = mid+1 ;i <=end ;i++) {
		right.push_back(vec[i]);
	}
	int i = 0,k=start,j = 0;
	while (i != mid-start+1 && j != end-mid) {
	if (left[i] <= right[j]) {
			vec[k] = left[i];
			i++; k++;
		}
		else{
			vec[k] = right[j];
			j++;k++;
		}
	}
	if (i == mid - start + 1) {
		for (;k <= end;k++) { vec[k] = right[j]; j++; }
	}
	else {
		for (;k <=end ;k++) { vec[k] = left[i]; i++; }
	}
}
void mergesort(std::vector<int>& vec,int start,int end) {
	if (end > start) {
		int mid = (start + end) / 2;
		mergesort(vec , start, mid);
		mergesort(vec, mid + 1,end);
		merge(start, mid, end, vec);
	}
}
