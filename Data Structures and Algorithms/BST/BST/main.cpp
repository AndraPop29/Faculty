#include<iostream>

using namespace std;

struct bstNode {
	int data;
	bstNode* left;
	bstNode* right;
};
struct bstNode* newNode(bstNode* root, int data)
{
	bstNode* node = new bstNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
struct bstNode* insert(bstNode* root, int data)
{
	if (root == NULL)
	{
		root = newNode(root, data);

	}
	else if (data < root->data)
		insert(root->left, data);
	else if (data > root->data)
		insert(root->right, data);
	return root;
}
bool search(bstNode* root, int data)
{
	if (root == NULL)
		return false;
	else if (data < root->data)
		return search(root->left, data);
	else if (data > root->data)
		return search(root->right, data);
	else if (data == root->data)
		return true;
	
}
struct bstNode* findMin(bstNode* root)
{
	if (root->left == NULL)
		return root;
	else return findMin(root->left);
}
struct bstNode* remove(bstNode* root, int data)
{
	
	if (root == NULL) return NULL;
	else if (data < root->data) root->left=remove(root->left, data);
	else if (data > root->data) root->right=remove(root->right, data);
	else if (data == root->data)
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			return root;
		}
		else if (root->left == NULL)
		{
			bstNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			bstNode* temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			bstNode* temp = findMin(root->right);
			root->data = temp->data;
			root->right=remove(root->right, temp->data);

		}
	}
	return root;
}
int main()
{
	bstNode* root;
	root = NULL;
	root = insert(root, 15);
	root = insert(root, 18);
	root = insert(root, 2);
	if (search(root, 15) == true)
		cout << "Exists";
	else
		cout << "Doesn't exist";
	root = remove(root, 18);


	if (search(root, 18))
		cout << "18 wasn't deleted!";
	system("pause");
	return 0;

}