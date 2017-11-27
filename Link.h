#ifndef LINK_H
#define LINK_H

class Link {

public:
	Link(int value, Link * next = nullptr) 
	: value(value), next(next) {}

private:
	Link * next;
	int value;

	friend class Iterator;
	friend class List;

};

#endif



