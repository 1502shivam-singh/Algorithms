#include<iostream>
#include<conio.h>
#include<vector>

template<typename T>

class Linkedlist {

/* Steps-> 1)First create list object
	2)Make user input in it (number of inputs as an vector and inputs)
	3)Create LL

	modules -
	LL object structure
	loop to create the LL
*/

private:	

	struct linked_list{
		T val;
		linked_list* next;
	};

	std::vector<T> vec;
	int blocks=vec.size();

public:
	
	Linkedlist(std::vector<T> vec) :vec(vec) {};
	
	linked_list* make_LL_node(int i);

	linked_list* make_LL();

};

template<typename T>

typename Linkedlist<T>::linked_list* Linkedlist<T>::make_LL_node(int i){
	linked_list* block=new linked_list();
	block->val = vec[i];
	block->next = nullptr;
	return block;
}

template<typename T>

typename Linkedlist<T>::linked_list* Linkedlist<T>::make_LL(){
	std::vector<linked_list*> ptrs;
	ptrs.push_back(make_LL_node(0));
	for (int i = 0; i < blocks; i++) {
		if (i == 0) {}
		else{
			ptrs.push_back(make_LL_node(i));
			ptrs[i]->next = ptrs[i - 1];
		}
	}
	return ptrs[blocks-1];
}
int main() {
	int count;
	int value;
	std::vector<int> storage;
	std::cout << "Enter count of numbers you want to store : ";
	std::cin >> count;
	std::cout << "\n\nEnter list of numbers to store in the linked list" << std::endl;
	for (int i = 0; i < count; i++) {
		std::cin >> value;
		storage.push_back(value);
	}
	std::cout << "\n\n";
	for (int i = 0; i < count; i++) {
		std::cout << storage[i];
	}
	Linkedlist<int>* list = new Linkedlist<int>(storage); //Creation of linked list
	auto head=list->make_LL();
	while (head != nullptr) {
		std::cout << head->val<<" ";
		head = head->next;
	}
	_getch();
}
