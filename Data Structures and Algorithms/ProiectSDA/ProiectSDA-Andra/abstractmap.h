#pragma once

#ifndef ABSTRACTMAP_H
#define ABSTRACTMAP_H

template <typename Object>
class AbstractMap {
public:

	virtual void put(const Object& c) = 0;

	virtual void remove(int index) = 0;

	virtual int getSize() const = 0;

	virtual bool isEmpty() = 0;




};


#endif // ABSTRACTMAP_H