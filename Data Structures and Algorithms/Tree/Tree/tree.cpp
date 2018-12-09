#include <stdio.h>
#include <vector>
#include <list>
#include <memory>


template<typename T>
class Tree
{
public:
	struct Node {
		//std::vector<Node> children;
		std::vector<std::unique_ptr<Node> > children;
		//Node* child[MAX];
		Node* child; // child = pointer to array of Node
		T value;
		Node* parent;
	};
	std::unique_ptr<Node> _root;
public:
	class iterator {
		Node* _current;
		friend class Tree<T>;
		iterator(Node* c)
			:_current(c) {}
	public:
		iterator& operator++() {
			if (_current->children.empty()) {
				while (true) {
					Node* parent = _current->parent;
					if (parent == nullptr) {
						_current = parent;
						break;
					}
					auto it = parent->children.begin();
					while (it->get() != _current) ++it;
					++it;
					if (it != parent->children.end()) {
						_current = it->get();
						break;
					}
					_current = parent;
				}
			}
			else {
				_current = _current->children[0].get();
			}

			return *this;
		}
		T& operator*() const {
			return _current->value;
		}
		T* operator->() const {
			return &(_current->value);
		}
		bool operator==(iterator that) const {
			return _current == that._current;
		}
		bool operator!=(iterator that) const {
			return _current != that._current;
		}
	};

	Tree() = default;
	~Tree() = default;
	void setRoot(T value) {
		if (_root == nullptr) {
			_root.reset(new Node);
			_root->value = value;
			_root->parent = nullptr;
		}
	}

	iterator begin() {
		return iterator(_root.get());
	}
	iterator end() {
		return iterator(nullptr);
	}
	iterator root() {
		return iterator(_root.get());
	}
	iterator appendChild(iterator parent, T value) {
		Node* p = new Node;
		parent._current->children.emplace_back(p);
		p->parent = parent._current;
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
		printf("  %d\n", v);
	}
}