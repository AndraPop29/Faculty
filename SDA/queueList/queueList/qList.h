#include<iostream>
#include<algorithm>
using namespace std;

#ifndef QLISTA_H
#define QLISTA_H



typedef int TElem;

class Nod;

typedef Nod* PNod;

class Nod
{
public:
	friend class qList;
	friend class TreAVL;
	Nod() : e(-1), next(nullptr){}
	Nod(TElem e, PNod n);
	TElem element();
	PNod nextN();
private:
	TElem e;
	PNod next;
};
//int max(int a, int b) {
//	return (a > b);
//}

class AVLNode;

typedef AVLNode *ANode;

class AVLNode {
public:
	friend class TreAVL;
	AVLNode::AVLNode() {}
	AVLNode::AVLNode(PNod key, ANode left, ANode right, int height)
	{
		this->key = key;
		this->left = left;
		this->right =right;
		this->height = height;
	}
private:
	PNod key;
	ANode left;
	ANode right;
	int height;
};

class TreAVL {
private:
	ANode root;

public:
	friend class qList;
	//TreeAVL(){}
	TreAVL() : root(nullptr) {}

	ANode getRoot() {
		return root;
	}


	void insert(PNod key) {
		root = _insert(root, key);
	}

	int height(ANode node) {
		if (node == nullptr)
			return 0;
		return node->height;
	}

	int getBalance(ANode node) {
		if (node == nullptr)
			return 0;
		return height(node->left) - height(node->right);
	}

	ANode rightRotate(ANode y) {
		ANode x = y->left;
		ANode T2 = x->right;

		// Perform the rotation
		x->right = y;
		y->left = T2;

		// Update the heights
		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		// Return the new root
		return x;
	}

	ANode leftRotate(ANode x) {
		ANode y = x->right;
		ANode T2 = y->left;

		// Perform the rotation
		y->left = x;
		x->right = T2;

		// Update the heights
		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		// Return the new root
		return y;
	}
private:
	ANode _insert(ANode node, PNod key) {
		// 1. Check if node is null
		if (node == nullptr) {
			ANode N = new AVLNode;
			N->key = key;
			N->left = nullptr;
			N->right = nullptr;
			N->height = 1;
			return N;
		}

		// 2. Perform normal BST insertion
		if (key->e < node->key->e)
			node->left = _insert(node->left, key);
		else
			node->right = _insert(node->right, key);

		// 3. Update the height of the ancestor node
		node->height = max(height(node->left), height(node->right)) + 1;

		// 4. Balance
		int balance = getBalance(node);

		// L-L case
		if (balance > 1 && key->e< node->left->key->e)
			return rightRotate(node);

		// R-R case
		if (balance < -1 && key->e > node->right->key->e)
			return leftRotate(node);

		// L-R case
		if (balance > 1 && key->e > node->left->key->e) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// R-L case
		if (balance < -1 && key->e < node->right->key->e) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		// already balanced case
		return node;
	}
	
};
class qList
{
private:
	PNod first;
	TreAVL t;
public:
	//friend class Nod;
	qList();
	void enqueue(TElem e);
	void dequeue();
	bool isEmpty();
	void remove(PNod p);
	PNod search(TElem e);
	void print();
	~qList();
};



#endif