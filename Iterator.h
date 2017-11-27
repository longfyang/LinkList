#ifndef ITERATOR_H
#define ITERATOR_H

#include "Link.h"

class Iterator {

public:
	Iterator(Link * node) : node(node) {}
	void operator++();
	int & operator*();

private:
	Link * node; 

	friend class List;

};

#endif



