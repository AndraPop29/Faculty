#include<iostream>
#include "qList.h"

using namespace std;

int main()
{
	qList q;
	q.enqueue(3);
	q.enqueue(10);
	q.enqueue(7);
	q.enqueue(10);

	//TreeAVL t;
	//PNod p = new Nod(2, NULL);
	//t.insert(p);
	//cout << t.getRoot()->key->element();
	//q.dequeue();
	//cout << (q.isEmpty()==false);
	
	q.print();

	system("pause");
	return 0;
}