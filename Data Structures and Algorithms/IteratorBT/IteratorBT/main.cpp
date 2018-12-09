//Binary Search Tree Program

#include <iostream>
#include <cstdlib>
using namespace std;
struct tree_node
{
	tree_node* left;
	tree_node* right;
	tree_node* parent;
	int data;
};
class BinarySearchTree
{
private:

	tree_node* root;

public:
	/** Returns a preorder iterator for this tree. */
	//public LinkedTreeIterator preorderIterator() {
		//return new PreorderIterator();
	//}
	/*** inner class for a preorder iterator ***/
	friend class PreorderIterator;
	class PreorderIterator {
	private:
		tree_node* nextNode;
	public:
		PreorderIterator() {
			// The traversal starts with the root node.
			nextNode = root;
		}
		inline bool hasNext() {
			return (nextNode != NULL);
		}
		inline int next() {
			if (nextNode == NULL)
				cout << "gata";
			// Store a copy of the key to be returned.
			int key = nextNode->data;

			// Advance nextNode.
			if (nextNode->left != NULL)
				nextNode = nextNode->left;
			else if (nextNode->right != NULL)
				nextNode = nextNode->right;
			else {
				// We've just visited a leaf node.
				// Go back up the tree until we find a node
				// with a right child that we haven't seen yet.
				tree_node* parent = nextNode->parent;
				tree_node* child = nextNode;
				while (parent != NULL &&
					(parent->right == child || parent->right == NULL)) {
					child = parent;
					parent = parent->parent;

					if (parent == NULL)
						nextNode = NULL; // the traversal is complete
					else
						nextNode = parent->right;
				}
				return key;
			}
		}
	};

	BinarySearchTree()
	{
		root = NULL;
	}

	bool isEmpty() const { return root == NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	void insert(int);
	void remove(int);
};


// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert(int d)
{
	tree_node* t = new tree_node;
	tree_node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	
	parent = NULL;

	// is this a new tree?
	if (isEmpty()) root = t;
	else
	{
		//Note: ALL insertions are as leaf nodes
		tree_node* curr;
		curr = root;
		// Find the Node's parent
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}

		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
		t->parent = parent;
	}
}


void BinarySearchTree::print_inorder()
{
	inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
	if (p != NULL)
	{
		if (p->left) inorder(p->left);
		cout << " " << p->data << " ";
		if (p->right) inorder(p->right);
	}
	else return;
}

void BinarySearchTree::print_preorder()
{
	preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
	if (p != NULL)
	{
		cout << " " << p->data << " ";
		if (p->left) preorder(p->left);
		if (p->right) preorder(p->right);
	}
	else return;
}

void BinarySearchTree::print_postorder()
{
	postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
	if (p != NULL)
	{
		if (p->left) postorder(p->left);
		if (p->right) postorder(p->right);
		cout << " " << p->data << " ";
	}
	else return;
}

int main()
{
	BinarySearchTree b;
	int ch, tmp, tmp1;
	while (1)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Operations " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insertion/Creation " << endl;
		cout << " 2. In-Order Traversal " << endl;
		cout << " 3. Pre-Order Traversal " << endl;
		cout << " 4. Post-Order Traversal " << endl;
		cout << " 5. Removal " << endl;
		cout << " 6. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << " Enter Number to be inserted : ";
			cin >> tmp;
			b.insert(tmp);
			break;
		case 2: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_inorder();
			break;
		case 3: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_preorder();
			break;
		case 4: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " --------------------" << endl;
			b.print_postorder();
			break;
		case 5: cout << " Enter data to be deleted : ";
			cin >> tmp1;
			//b.remove(tmp1);
			break;
		case 6:
			return 0;

		}
	}
}