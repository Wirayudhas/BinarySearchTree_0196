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

		