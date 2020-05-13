#include<iostream>
#include<conio.h>
#include<vector>

//ALGO : 1) Max heapify function ,2) New Max heap creator 
// 3), Heapsort(){	New Max heap creator{Max heapify function};
//					for(n.....2)
//						swap top node in heap with last;
//						New Max heap creator{ MHF }		   }

class heap {
private:
	std::vector<int> vec;
	int size = vec.size();
	int heap_size = size;
	
public:
	heap(std::vector<int> vector) :vec{ vector } {};

	void Max_heapify(std::vector<int>& heap, int pos,int heapsize);//,int(*left)(int),int(*right)(int),int(*maxoff)(int,int,int));

	void Heap_creator(std::vector<int>& heap,int heapsize){//, void(*Max)(std::vector<int>, int, int(*a)(int), int(*b)(int), int(*c)(int, int, int)), int(*right)(int), int(*left)(int), int(*maxoff)(int, int, int)) {
		for (int i = ((size - 1) / 2) + 1; i >= 0; i--) {
			Max_heapify(heap, i,heapsize);//, right, left, maxoff);
		}
	}

	void HeapSort(std::vector<int>& structure);//, int(*right)(int), int(*left)(int), int(*maxoff)(int, int, int));

	int left(int i) { 
		if ((2 * i + 1) <= size - 1) {
			return 2 * i + 1;
		}
		else {}//throw; }
	}

	int right(int i) {
		if ((2 * i + 2) <= size - 1) {
			return 2 * i + 2;
		}
		else {}//throw; }
	}

	int parent(int i) {
		if ((i/2 + 1) <= size - 1) {
			return i/2 + 2;
		}
		else {}//throw; }
	}
	int maxoff(int n1, int n2,int n3,int heapsize) {
		if (((vec[n1] > vec[n2])&&(n1<heapsize&&n2<heapsize))&&((vec[n1] > vec[n3])&&(n1<heapsize&&n3<heapsize))) { return n1; }
		else if ((vec[n2] > vec[n3])&&(n2<heapsize&&n3<heapsize)) { return n2; }
		else if(n3<heapsize) return n3;
		else {}
	}
};


void heap::Max_heapify(std::vector<int>& heap, int pos,int heapsize){//,int(*right)(int),int(*left)(int),int(*maxoff)(int,int,int)) {
	int l = heap::left(pos);
	int r = heap::right(pos);
	int new_pos = heap::maxoff(l, r, pos,heapsize);
	if (new_pos != pos) {
		int hold = vec[new_pos];
		vec[new_pos] = vec[pos];
		vec[pos] = hold;
		heap::Max_heapify(heap, new_pos,heapsize);//, right, left, maxoff);
	}
	else{}
}

void heap::HeapSort(std::vector<int>& structure) {
	Heap_creator(structure,heap::heap_size);
	int store;
	for (int i = heap::size-1; i >= 0; i--) {
		store=structure[i];
		structure[0] = structure[i];
		structure[i] = store;
		heap::heap_size--;
		heap::Max_heapify(structure, 0,heap::heap_size);
	}
}
int main() {
	std::vector<int> vec{3,4,10,0,1,2};
	heap* Heap = new heap(vec);
	Heap->HeapSort(vec);
	int size = vec.size();
	for (int i = 0; i <size ;i++) {
		std::cout << vec[i] << " ";
	}
	Heap->~heap();
	_getch();
}



//(std::vector<int> heap, void(*Max)(std::vector<int>, int, int(*)(int), int(*)(int), int(*)(int, int, int)), int(*right)(int), int(*left)(int), int(*maxoff)(int, int, int))
