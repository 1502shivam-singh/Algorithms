#include<iostream>
#include<conio.h>
#include<vector>
#include<stdlib.h>
#include<time.h>

/*
Algorithm -

QuickSort(Arr&,last){
	function Partition(Arr&,last);
	QuickSort(Arr&,last_left);
	QuickSort(Arr&,last_right);
}

Partition algo. needs swapper(for lomuto partition)



Partition function(){
//loop start .. end;
	if->vec[start]>=vec[end];
	{swapper(start,end);}
	else{Do nothing;]
	}
*/

void QuickSort(std::vector<int>& vec, int p, int r);
int Partition(std::vector<int>&, int, int);
void swap(int& a, int& b);

int main() {
	srand(time(0));
	int count;
	int value;
	std::vector<int> vec;
	std::cout << "Enter count of numbers you want to sort : ";
	std::cin >> count;
	std::cout << "\n\nEnter list of numbers to be sorted : Algorithm - Quicksort Ascending " << std::endl;
	for (int i = 0; i < count; i++) {
		std::cin >> value;
		//value = rand();
		vec.push_back(value);
	}
	std::cout << "\n\n";
	QuickSort(vec, 0, count - 1);
	for (int i = 0; i < count; i++) {
		std::cout << vec[i]<<" ";
	}
	_getch();
}

void QuickSort(std::vector<int>& vec, int p, int r) {
	if (p < r) {
		int q = Partition(vec, p, r);
		QuickSort(vec, p, q - 1);
		QuickSort(vec, q + 1, r);
	}
}

int Partition(std::vector<int>& vec, int p, int r)
{
	int x = vec[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (vec[j] <= x) {
			i++;
			swap(vec[i], vec[j]);
		}
	}
	swap(vec[i + 1], vec[r]);
	return i + 1;
}

void swap(int& a, int& b) {
	int store;
	store = a;
	a = b;
	b = store;
}
