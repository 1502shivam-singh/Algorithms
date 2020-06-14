#include<iostream>
#include<conio.h>
#include<vector>

/*
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
			
			node* makehead();	

			node* maketree();
		
			addnode(data);

			deletenode(ptr);
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

public:
	Tree() {};	//For creating only head
	Tree(std::vector<int> vec) : vec(vec){};	//For Creating whole tree

	node* makehead(int data);

	node* maketree();

	void addnode(int data);

	void deletenode(int pos);

	~Tree() {
		delete head;
	}
};

Tree::node* Tree::makehead(int data)
{
	this->ptr_store.push_back(new node(data));
	return ptr_store[0];
}

Tree::node* Tree::maketree()
{
	this->head=makehead(this->vec[0]);
	ptr_store.push_back(head);
	for (int i = 1; i < this->vec.size(); i++) {
		ptr_store.push_back(new node(vec[i]));
		addnode(vec[i]);
		//some stuff
	}
	return head;
}

void Tree::addnode(int data)
{

}

void Tree::deletenode(int pos)
{
}
