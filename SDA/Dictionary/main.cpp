
#include "dictionar.h"
#include <iostream>
#include <memory>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

using namespace std;

void createDictionary(Dictionary& d) {
	d.add(2, 21);
	d.add(4, 41);
	d.add(25, 51);
	d.add(14,141);
	d.add(88, 111);
	d.add(22, 22);
	d.add(58, 1);
	d.add(72, 9);
	d.add(122, 5);
}

void displayDictionary(const Dictionary& d) {
	Iterator it = d.iterator();
	while (it.hasNext()) {
        TPair e = it.element();
		cout << '('<<e.c<<','<<e.v<<')'<<endl;
		it.next();
	}
}

void searches(const Dictionary& d) {
	auto val = d.search(88);
	cout << "Value for key 88: " << val << endl;
	val = d.search(11);
	cout << "Value for key 11: " << val << endl;
	val = d.search(4);
	cout << "Value for key 4: " << val << endl;
	val = d.search(14);
	cout << "Value for key 14: " << val << endl;
	val = d.search(13);
	cout << "Value for key 13: " << val << endl;
}

void removeFromDictionary(Dictionary& d) {
	TPair removed = d.remove(2);
	cout << "Removed pair (" << removed.c << " " << removed.v << ")" << endl;
 	displayDictionary(d);
	removed = d.remove(58);
	cout << "Removed pair (" << removed.c << " " << removed.v << ")" << endl;
	displayDictionary(d);
	removed = d.remove(5);
	cout << "Removed pair (" << removed.c << " " << removed.v << ")" << endl;
	displayDictionary(d);


}

int main() {
	{
		Dictionary d;
		createDictionary(d);
		//displayDictionary(d);
		//searches(d);
		//removeFromDictionary(d);
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
