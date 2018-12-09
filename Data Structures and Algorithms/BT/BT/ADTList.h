#pragma once
template <typename T>
class Iterator;

template <typename T>
class ListIteratorADT {

public:
	virtual bool IsEmpty() = 0;
	virtual int getLength() = 0;
	virtual Iterator<T>* iterator() = 0;
};