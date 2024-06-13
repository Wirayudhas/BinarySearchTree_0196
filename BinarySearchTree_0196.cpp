#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//constructor
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};
class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = nullptr; //initializing ROOT to Null
	}

	void insert(string element) // insert a node in binary search
	{
		Node* newNode = new Node(element, nullptr, nullptr); // Allocate memory for the new node
		newNode->info = element; // Assign value to the data field of the new node
		newNode->leftchild = nullptr;
		newNode->rightchild = nullptr;

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode);

		if (parent == nullptr) // if the parents NUll (tree is empty)
		{
			ROOT = newNode; // Mark the new node as ROOT
			return; // EXIT
		}

		if (element < parent->info) // if the value in the data field of the new node is less that of the
		{
			parent->leftchild = newNode; // make the left child of the parent point to the new node
		}

		else if (element > parent->info) // if the value in the data field of the new node is greater than that
		{
			parent->rightchild = newNode; // make the right child of the parent point to the new node
		}

	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		// This is function search the currentNode of the specified Node as well as the current Node of its parent
		currentNode = ROOT;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

