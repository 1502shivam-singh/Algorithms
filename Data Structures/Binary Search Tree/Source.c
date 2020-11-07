#include <stdio.h>  
#include <stdlib.h>    

//Represent a node of binary search tree  
struct node {
	int data;
	struct node *left;
	struct node *right;
};

//Represent the root of binary search tree  
struct node *root = NULL;

///////////////// Deleting a node in a binary search tree //////////////////////////////////

struct node* deleteNode(struct node* root, int k)
{
	// Base case 
	if (root == NULL)
		return root;

	// Recursive calls for ancestors of node to be deleted 
	if (root->data > k) {
		root->left = deleteNode(root->left, k);
		return root;
	}
	else if (root->data < k) {
		root->right = deleteNode(root->right, k);
		return root;
	}

	// We reach here when root is the node to be deleted. 

	// If one of the children is empty 
	if (root->left == NULL) {
		struct node* temp = root->right;
		free(root);
		root = NULL;
		return temp;
	}
	else if (root->right == NULL) {
		struct node* temp = root->left;
		free(root);
		root = NULL;
		return temp;
	}

	// If both children exist 
	else {

		struct node* succParent = root;

		// Find successor 
		struct node* succ = root->right;
		while (succ->left != NULL) {
			succParent = succ;
			succ = succ->left;
		}
    
		if (succParent != root)
			succParent->left = succ->right;
		else
			succParent->right = succ->right;

		// Copy Successor Data to root 
		root->data = succ->data;

		// Delete Successor and return root 
		free(succ);
		succ = NULL;
		return root;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

//createNode() will create a new node  
struct node* createNode(int data) {
	//Create a new node  
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	//Assign data to newNode, set left and right child to NULL  
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

///////////////// Inserting a node in a binary search tree //////////////////////////////////

void insertNode(struct node* head, int insertData) {
	//Create a new node  
	struct node *newNode = createNode(insertData);
	if (root == NULL) {
		root = newNode;
		return;
	}
	struct node* hold = NULL;
	while (head!=NULL) {
		if (insertData >= head->data) {
			hold = head;
			head = head->right;
		}
		else {
			hold = head;
			head = head->left;
		}
	}
	if (hold->data >= insertData) {
		hold->left = newNode;
	}
	else {
		hold->right = newNode;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////  Inorder traversal in binary search tree ////////////////////////////////// 

void inorderTraversal(struct node *node) {
	//Check whether tree is empty  
	if (root == NULL) {
		printf("Tree is empty\n");
		return;
	}
	else {

		if (node->left != NULL)
			inorderTraversal(node->left);
		printf("%d ", node->data);
		if (node->right != NULL)
			inorderTraversal(node->right);

	}
}
/////////////////////////////////////////////////////////////////////////////////////////////

struct node* searchNode = NULL;

///////////////// Searching a node in the binary search tree - Recursive and iterative both //
struct node* TreeSearchI(struct node* head, int key) {	// iterative version for TreeSearch in BST
	while (head != NULL ) {
		if (key == head->data) {
			searchNode = head;
			break;
		}
		else if (key > head->data) {
			head = head->right;
		}
		else{
			head = head->left;
		}
	}
	if (searchNode != NULL) {
		printf("\n%d Element found\n", key);
	}
	else {
		printf("\n%d Element not found\n", key);
	}
	return searchNode;
}

struct node* TreeSearchR(struct node* head, int key) {	// recursive version for TreeSearch in BST
	if (head == NULL) { printf("\n%d Element not found\n", key); return searchNode; }
	else if (key == head->data) {
		searchNode = head;
		printf("\n%d Element found\n", key);
		return searchNode;
		}
	if (key > head->data) { return TreeSearchR(head->right, key); }
	else{ return TreeSearchR(head->left, key); }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

	//Add nodes to the binary search tree  
	insertNode(root, 1);
	//1 will become root node of the tree  
	printf("Binary tree after insertion: inorder traversal\n");
	//Binary after inserting nodes  
	inorderTraversal(root);

	insertNode(root, 0);
	insertNode(root, 6);
	//0 will become left child and 6 will become right child of root node 1  
	printf("\nBinary tree after insertion: inorder traversal\n");
	//Binary after inserting nodes  
	inorderTraversal(root);

	insertNode(root, 8);
	insertNode(root, 5);
	insertNode(root, 3);
	insertNode(root, 2);
	insertNode(root, 4);
	insertNode(root, 11);

	struct node* search = TreeSearchR(root, 10);

	//8 will become right child and 5 will become left child of node 6  
	printf("\nBinary tree after insertion: inorder traversal\n");
	//Binary after inserting nodes  
	inorderTraversal(root);
	root = deleteNode(root, 0);	// deleting 0 from the BST
	printf("\nBinary tree after deletion of 0: inorder traversal\n");
	inorderTraversal(root);

	root = deleteNode(root, 5);	// deleting 5 from the BST
	printf("\nBinary tree after deletion of 5: inorder traversal\n");
	inorderTraversal(root);

	root = deleteNode(root, 3);	// deleting 3 from the BST
	printf("\nBinary tree after deletion of 3: inorder traversal\n");
	inorderTraversal(root);

	root = deleteNode(root, 11); // deleting 11 from the BST
	printf("\nBinary tree after deletion of 11: inorder traversal\n");
	inorderTraversal(root);

}
