#pragma once
template <typename T>
class Iterator {

public:
	/*Getter of the next iterator in the ordered list */
	virtual void next() = 0;

	/*Getter of the previous iterator in the ordered list */
	virtual void prev() = 0;

	/*Initializes the iterator with the first element
	of the ordered list*/
	virtual void beginIt() = 0;

	/*Verifies if the iterator is at the last element.
	Output: boolean value*/
	virtual bool isDone() = 0;

	/*Adds an element on the current position
	Input: val - type T*/
	virtual void add(T val) = 0;

	/*Removes the element of the current position
	and the value of the iterator becomes the next one*/
	virtual void remove() = 0;

	/*Getter of the element from the current position
	Output: Object of type T*/
	virtual T getElem() = 0;

	/*Setter of the element on the current position
	Input : object of type T*/
	virtual void setElem(T val) = 0;

	//virtual ~Iterator() {}

};