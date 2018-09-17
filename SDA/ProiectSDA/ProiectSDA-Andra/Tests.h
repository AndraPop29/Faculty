#pragma once

#include <cassert>
#include "DynVector.h"
#include "Hashtable.h"
#include "abstractmap.h"
#include <iostream>

using namespace std;

template<class Object>

class Tests {
public:
	Tests() {};
	void Tests::testAll()
	{
		//tests for adding an element to the map
		DynamicVector<Object> m;
		mapE el;
		el.c = "a1b1";
		el.v = "ab";
		mapE el1;
		el.c = "a2b3";
		el.v = "aabbb";
		m.put(el1);
		assert(m.getSize() == 1);
		m.put(el);
		assert(m.getSize() == 2);

		m.remove(0);
		assert(m.getSize() == 1);
		m.remove(0);
		assert(m.getSize() == 0);
		assert(m.isEmpty() == true);

		//tests for checking if 2 keys have as values anagrams of the same word
		Hashtable h;
		assert(h.isValid("a1b3c1", "b3a1c1") == 1);
		assert(h.isValid("a3b1", "c1v3") == 0);
		assert(h.isValid("a4b2", "b2a4") == 1);

		h.add("a1b3c1", "abbbc");
		assert(h.search("a1b3c1") == "abbbc");

		h.remove("a1b3c1");
	}

	


	
};