#pragma once

struct Node
{

};

template< typename T >
class DoublyLinkedList
{
private:
	// Data Members
	int noOfNodes;
	Node< T > *head,
		*tail;

public:
	// Constructor
	DoublyLinkedList();

	// Destructor
	~DoublyLinkedList();

	// Get Methods
	int getNoOfNodes() const;
	Node<T> *getHead() { return *head; }
	Node<T>* getTail() { return *tail; }
	// Insert Methods
	bool insertAtHead(T data);
	bool insertAtTail(T data);

	// Delete Methods
	bool deleteAtHead();
	bool deleteAtTail();
	void deleteAllNodes();

	// Predicate Methods
	bool isEmpty() const;

	// Print List
	void outputList();

private:
	// Set Methods
	bool setNoOfNodes(int);

	// Utility Methods
	Node< T > * createNode(T data);
	bool insertAtHead(Node< T > *node);
	bool insertAtTail(Node< T > *node);
	bool insertBefore(Node< T > *node, Node< T > *newNode);
	bool insertAfter(Node< T > *node, Node< T > *newNode);
	bool deleteNode(Node< T > *node);


};

// Default Constructor

template< typename T >
DoublyLinkedList< T >::DoublyLinkedList() : noOfNodes(0), head(NULL), tail(NULL)
{
	return;
}

// Destructor

template< typename T >
DoublyLinkedList< T >::~DoublyLinkedList()
{
	deleteAllNodes();

	return;
}

// Get Methods

template< typename T >
int DoublyLinkedList< T >::getNoOfNodes() const
{
	return noOfNodes;
}

// Set Methods

template< typename T >
bool DoublyLinkedList< T >::setNoOfNodes(int no)
{
	bool exitStatus = false;

	if (no >= 0)
	{
		noOfNodes = no;
		exitStatus = true;
	}
	return exitStatus;
}

// Insert Methods

template< typename T >
bool DoublyLinkedList< T >::insertAtHead(T data)
{
	return insertAtHead(createNode(data));
}

template< typename T >
bool DoublyLinkedList< T >::insertAtTail(T data)
{
	return insertAtTail(createNode(data));
}

// Delete Methods

template< typename T >
bool DoublyLinkedList< T >::deleteAtHead()
{
	return deleteNode(head);
}

template< typename T >
bool DoublyLinkedList< T >::deleteAtTail()
{
	return deleteNode(tail);
}

template< typename T >
void DoublyLinkedList< T >::deleteAllNodes()
{
	while (head)
		deleteAtHead();
	return;
}

// Predicate Methods

template< typename T >
bool DoublyLinkedList< T >::isEmpty() const
{
	return (getNoOfNodes() == 0);
}


// Utility Methods

template< typename T >
Node< T > * DoublyLinkedList< T >::createNode(T data)
{
	Node< T > *pNew = new Node< T >(data);
	pNew->prev = NULL;
	pNew->next = NULL;

	return pNew;
}

template< typename T >
bool DoublyLinkedList< T >::insertAtHead(Node< T > *newNode)
{
	bool exitStatus = false;

	if (newNode)
	{
		if (head)
			exitStatus = insertBefore(head, newNode);
		else
		{
			head = newNode;
			tail = newNode;
			newNode->pre = NULL;
			newNode->next = NULL;
			exitStatus = setNoOfNodes(getNoOfNodes() + 1);
		}
	}

	return exitStatus;
}

template< typename T >
bool DoublyLinkedList< T >::insertAtTail(Node< T > *newNode) {
	bool exitStatus = false;

	if (newNode)
	{
		if (tail)
			exitStatus = insertAfter(tail, newNode);
		else
			exitStatus = insertAtHead(newNode);

	}

	return exitStatus;
}

template< typename T >
bool DoublyLinkedList< T >::insertBefore(Node< T > *node, Node< T > *newNode) {
	bool exitStatus = false;

	if (node && newNode)
	{
		newNode->prev = node->prev;
		newNode->next = node;

		if (node->prev)
			node->prev->next = newNode;
		else
			head = newNode;

		node->prev = newNode;

		exitStatus = setNoOfNodes(getNoOfNodes() + 1);
	}

	return exitStatus;
}


template< typename T >
bool DoublyLinkedList< T >::insertAfter(Node< T > *node, Node< T > *newNode) {
	bool exitStatus = false;

	if (node && newNode) {
		newNode->prev = node;
		newNode->next = node->next;

		if (node->next)
			node->next->prev = newNode;
		else
			tail = newNode;

		node->next = newNode;

		exitStatus = setNoOfNodes(getNoOfNodes() + 1);
	}

	return exitStatus;
}


template< typename T >
bool DoublyLinkedList< T >::deleteNode(Node< T > *node) {
	bool exitStatus = false;
	if (node) {
		if (node->prev)
			node->prev->next = node->next;
		else
			head = node->next;

		if (node->next)
			node->next->prev = node->prev;
		else
			tail = node->prev;

		delete node;

		exitStatus = setNoOfNodes(getNoOfNodes() - 1);
	}

	return exitStatus;
}


// Test Methods

template< typename T >
void DoublyLinkedList< T >::outputList()
{
	Node< T > *pCur = head;

	while (pCur)
	{
		cout << pCur->data << endl;
		pCur = pCur->next;
	}
	return;
}