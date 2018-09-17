#include<iostream>
#include<vector>
#include<list>
#include<memory>

using namespace std;

template<typename T>
class Tree {
public:
	struct Node {
		vector<Node*> children;
		Node* child;//child=pointer to array of a Node
		T value;
		Node* parent;
	};
	Node* root;
public:
	class iterator {
		Node* current;
		friend class Tree<T>;
		iterator(Node* c): current(c){}
	public:
		iterator& operator++()
		{
			if (current->children.empty()) {
				while (true)
				{
					Node* parent = current->parent;
					if (parent == nullptr)
					{
						current = parent;
						break;
					}
					auto it = parent->children.begin();
					while (it->get() != current)++it;
					++it;
					if (it != parent->children.end()) {
						current = it->get();
						break;
					}
					current = parent;
				}
			}
			else
				current = current->children[0].get();

			return *this;
		}
	};

	Tree(){}
	~Tree(){}
	void setRoot(T value)
	{
		if (root == nullptr)
		{
			root.reset(new Node);
			root->value = value;
			root->parent = nullptr;
		}

	}
	iterator root()
	{
		return iterator(root.get());
	}
	iterator begin() {
		return iterator(root.get());
	}
	iterator end() {
		return iterator(nullptr);
	}
	iterator appendChild(iterator parent, T value) {
		Node* p = new Node;
		parent.current->children.emplace_back(p);
		p->parent = parent.current;
		p->value = value;
		return iterator(p);
	}
};
int main()
{
	Tree<int> tree;
	printf("sizeof(Node) = %d\n", sizeof(Tree<int>::Node));
	tree.setRoot(42);
	Tree<int>::iterator root = tree.root();
	tree.appendChild(root, 1);
	Tree<int>::iterator second = tree.appendChild(root, 2);
	tree.appendChild(root, 3);

	tree.appendChild(second, 20);
	tree.appendChild(second, 30);


	for (int v : tree) {
		cout << v;
	}
}