#include<iostream>
#include<conio.h>
#include<vector>

/*
	Psuedo code 
	BSTs 
	class{
		object{
		pointers ->
		head, left, right;
		Type data;
		}

		functions->
		addNode(data);
		node* makehead();
		node* maketree();
		}

	Implementation{
		class Tree{
		private:
		std::vector<Type> vec;
			struct node{  info,Constructors	};
		public:	
			Two Constructors --
				Tree():{};	//For creating only head
				Tree(std::vector<Type> vec):this.vec{vec}{};	//For Creating whole tree
			
			node* makehead();	//Added

			node* maketree();	//Added
		
			addnode(data);		//Added

			deletenode(ptr);	//To be added
		}
	}

*/


class Tree {
private:
	std::vector<int> vec;
	struct node { //info, Constructors 
		int data;
		node* left=nullptr;
		node* right=nullptr;
		node* head = nullptr;
		node(int data) :data(data) {};
	};
	std::vector<node*> ptr_store;
	node* head = nullptr;
	int ptr_s_size=ptr_store.size();

public:
	Tree() {};	//For creating only head
	Tree(std::vector<int> vec) : vec(vec){};	//For Creating whole tree

	node* makehead(int data);	//Added

	node* maketree();		//Added

	void addnode( int data );	//Added

	void deletenode(int pos);	//To be added

	~Tree() {
		delete head;
	}
};

Tree::node* Tree::makehead( int data )
{
	this->ptr_store.push_back(new node(data));
	return ptr_store[0];
}

Tree::node* Tree::maketree()
{
	this->head=makehead(this->vec[0]);
	ptr_store.push_back(head);
	for (int i = 1; i < this->vec.size(); i++) {
		addnode(vec[i]);
		//some stuff
	}
	return head;
}

void Tree::addnode( int data )
{
	node* tailptr = nullptr;
	ptr_store.push_back(new node(data));
	node* heading_ptr = ptr_store[0];
	while (heading_ptr != nullptr) {
		if (data >= heading_ptr->data) {
			tailptr = heading_ptr;
			heading_ptr = heading_ptr->right;
		}
		else {
			tailptr = heading_ptr;
			heading_ptr = heading_ptr->left;
		}
	}
	if (data >= tailptr->data) {
		tailptr->right=ptr_store[ptr_s_size - 1];
		ptr_store[ptr_s_size - 1]->head = tailptr;
	}
	else{
		tailptr->left = ptr_store[ptr_s_size - 1];
		ptr_store[ptr_s_size - 1]->head = tailptr;
	}
}

void Tree::deletenode(int pos)
{
}

int main() {
	std::vector<int> vec{1, 2, 3, 4, 5, 6};
	Tree* tree = new Tree(vec); //Creation of Tree object
	auto head=tree->maketree();
	tree->addnode(-1);
	tree->addnode(-2);
	tree->addnode(0);
	tree->~Tree();
	_getch();
}
