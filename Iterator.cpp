#include <iostream>
#include "Iterator.h"

using namespace std;

void Iterator::operator++() {
	node = node->next;
}

int & Iterator::operator*() {
	return node->value;
}



