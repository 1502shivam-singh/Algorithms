#include<iostream>
#include<vector>

/*
Class structure : 
	 1) Max heapify function 
	 2) New Max heap creator 
 	 3) Heapsort()
	 {
	New Max heap creator{Max heapify function};
		for(n.....2)
		swap top node in heap with last;
		New Max heap creator{ MHF }		   
	}
*/

class heap {    //max heap class
private:
	std::vector<int> vec;
	int size = vec.size();
	int heap_size = size;
	
public:
// Main functions 
	heap(std::vector<int> vector) :vec{ vector } {};
	void Max_heapify(std::vector<int>& heap, int pos,int heapsize);   //Max heapify
	void Heap_creator(std::vector<int>& heap,int heapsize){   //Heap Creator
	void HeapSort(std::vector<int>& structure);

// Utility functions
	int left(int i);
	int right(int i);
	int parent(int i);
	int maxoff(std::vector<int>& vec,int n1, int n2,int n3,int heapsize);
  
	~heap(){
		delete this;
	}
};

// Utility functions for the heap class 	
int heap::left(int i) { 
	if ((2 * i + 1) <= size - 1) {
		return 2 * i + 1;
	}
}

int heap::right(int i) {
	if ((2 * i + 2) <= size - 1) {
		return (2 * i + 2);
	}
}
		
int heap::parent(int i) {
	if(i==0){
		return 0;
	}
	else if (i%2==0) {
		return i/2 - 1;
	}
	else { return i/2; }
}
		
int heap::maxoff(std::vector<int>& vec,int n1, int n2,int n3,int heapsize) {
	if (((vec[n1] >= vec[n2])&&(n1<heapsize&&n2<heapsize))&&((vec[n1] >= vec[n3])&&(n1<heapsize&&n3<heapsize))) { return n1; }
	else if ((vec[n2] >= vec[n3])&&(n2<heapsize&&n3<heapsize)) { return n2; }
	else if(n3<=heapsize) return n3;
}	
	
// Definitions of the base functions declared in the heap class
	
void heap::Max_heapify(std::vector<int>& heap, int pos,int heapsize){   //Max heapify function definition 
	int l = heap::left(pos);
	int r = heap::right(pos);
	int new_pos = heap::maxoff(heap,l, r, pos,heapsize);
	if (new_pos != pos) {
		int hold = heap[new_pos];
		heap[new_pos] = heap[pos];
		heap[pos] = hold;
		heap::Max_heapify(heap, new_pos,heapsize);
	}
}

void heap::HeapSort(std::vector<int>& structure) {
	Heap_creator(structure,heap::size);
	int store;
	for (int i = heap::size-1; i >= 1; i--) {
		store=structure[i];
		structure[i] = structure[0];
		structure[0] = store;
		heap::heap_size--;
		heap::Max_heapify(structure, 0,heap::heap_size);
	}
}

void heap::Heap_creator(std::vector<int>& heap,int heapsize){   //Heap Creator
	for (int i = ((size - 1) / 2) ; i >= 0; i--) {
		Max_heapify(heap, i,heapsize);
	}
}

int main() {
	int count;
	int value;
	std::vector<int> vec;
	std::cout << "Enter count of numbers you want to sort : ";
	std::cin >> count;
	std::cout << "\n\nEnter list of numbers to be sorted : Algorithm - Heapsort Ascending "<<std::endl;
	for (int i = 0; i < count; i++) {
		std::cin >> value;
		vec.push_back(value);
	}
	std::cout << "\n\n";
	heap* Heap = new heap(vec); //Creation of heap object
	Heap->HeapSort(vec);
	for (int i = 0; i < count;i++) {
		std::cout << vec[i] << " ";
	}
	std::cin.get();
}



