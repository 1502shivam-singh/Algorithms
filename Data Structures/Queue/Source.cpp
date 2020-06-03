#include<iostream>
#include<conio.h>
#include<vector>

class Queue {
private:
	std::vector<int> vec;
	int size;
	int use_size;
public:
	Queue(std::vector<int> vec, int size) :vec(vec), size(size) { use_size = size-1; };
	inline void make_queue() { 
		for (int i = 0; i < size; i++) { vec.push_back(0); } 
	}

	void enqueue(int val) {
		if(use_size-1==0){
			std::cout << "Could not add, Queue full";
		}
		else {
			vec[use_size] = val;
			use_size--;
		}
	}

	void dequeue() {
		if (use_size == size-1) {
			std::cout << "Could not remove, Queue empty";
		}
		else {
			vec.pop_back();
			use_size--;
		}
	}

	void print_queue() {
		if (vec.size() == 0) {
			std::cout << "Nothing in queue";
		}
		else {
			for (int i = 0; i < size; i++) {
				std::cout << this->vec[i] << " ";
			}
		}
	}
};

int main() {
	int size;
	std::vector<int> vec;
	std::cout << "Enter the number of elements to be stored in the queue" << std::endl;
	std::cin >> size;
	Queue* entity = new Queue(vec,size);
	entity->make_queue();
	entity->enqueue(6);
	entity->dequeue();
	entity->print_queue();
	_getch();
}