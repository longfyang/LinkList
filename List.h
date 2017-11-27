#ifndef LIST_H
#define LIST_H

#include "Iterator.h"

class List {

public:
	List(Link * head = nullptr) : head(head) {}
	~List();
	bool empty() const;
	int size() const;
	Iterator begin() const;
	Iterator end() const;
	void push_back(int x);
	void push_front(int x);
	void insert(Iterator it, int x);
	void pop_back();
	void pop_front();
	Iterator erase(Iterator it);


private:
	Link * head;
	Link * tail;

};

#endif



