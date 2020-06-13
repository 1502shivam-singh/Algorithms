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
		node(int data) :data(data) {};
	};
public:
		Tree() {};	//For creating only head
	Tree(std::vector<int> vec) : vec(vec){};	//For Creating whole tree

	node* makehead();

	node* maketree();

	void addnode(int data);

	void deletenode(int pos);
};

//Definition of functions to be implemented

Tree::node * Tree::makehead()
{
	return nullptr;
}

Tree::node * Tree::maketree()
{
	return nullptr;
}

void Tree::addnode(int data)
{
}

void Tree::deletenode(int pos)
{
}
