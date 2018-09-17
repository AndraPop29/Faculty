#include<iostream>
using namespace std;

template<class T>
class DLL {
	struct Node {
		T key;
		Node *next, *prev;
		Node() : key(NULL), next(NULL), prev(NULL) {}
		Node(T _key, Node *_prev, Node *_next) : key(_key), next(_next), prev(_prev) {}

	};
public:
	class iterator {
	private:
		Node *cur;
	public:
		iterator() : cur(NULL) {}
		iterator(Node *_cur) : cur(_cur) {}
		iterator& operator ++ () {
			cur = cur->next;
			return *this;
		}
		T& operator *() {
			return cur->key;
		}
		iterator& operator --() {
			cur = cur->prev;
			return *this;
		}
		inline bool operator == (const iterator &other)const {
			return cur == other.cur;
		}
		inline bool operator != (const iterator &other)const {
			return cur != other.cur;
		}
		inline bool isValid() {
			return cur != NULL;
		}
	};
private:
	Node *head, *tail;
	int cnt;
public:
	DLL() {
		head = tail = NULL;
	}
	iterator begin() {
		return iterator(head);
	}
	iterator end() {
		return NULL;
	}
	void insertFront(T key) {
		if (!remove(key))
			++cnt;
		Node *cur = new Node(key, NULL, NULL);
		if (head == NULL) {
			head = tail = cur;
			return;
		}
		cur->next = head;
		head->prev = cur;
		head = cur;
	}
	void insertBack(T key) {
		if (!remove(key))
			++cnt;
		Node *cur = new Node(key, NULL, NULL);
		if (tail == NULL) {
			head = tail = cur;
			return;
		}
		tail->next = cur;
		cur->prev = tail;
		tail = cur;
	}
	inline bool remove(T key)
	{
		Node *cur = head;
		while (cur) {
			if (cur->key = key) {
				if (cur->prev = NULL) {//cur is head
					head = cur->next;
					if (!head)
						head = tail = NULL;
				}
				else {
					cur->prev->next = cur->next;
					if (cur->next == NULL)//then cur is tail
						tail = cur->prev;
					if (!tail)
						head = tail = NULL;
				}
				delete cur;
				return 1;
			}
		cur = cur->next;
	}
	return 0;
}
inline int size() {
	return cnt;
}
inline bool isEmpty() {
	return head == tail == NULL;
}
inline void print() {
	cerr << "list contains:\n";
	for (iterator it = this->begin(); it != this->end(); ++it) {
		cerr << *it << ' ';
	}
	cerr << '\n';
}
};

int main() {
	DLL <int> l;
	//l.insertBack(3);
	l.insertFront(2);
	//l.insertBack(4);
	//l.insertFront(1);
	//l.insertBack(5);
	l.print();
	//l.insertBack(1);
	//l.print();
	//l.insertFront(1);

	/*DLL <int> v;
	v.insertBack(1);
	v.print();
	v.insertBack(1);
	v.print();
	v.insertFront(1);
	v.insertBack(2);
	v.insertFront(3);
	v.print();*/
	system("pause");
	return 0;
}
