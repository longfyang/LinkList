#include <iostream>
#include <cassert>
#include "List.h"
#include "Iterator.h"

using namespace std;

List::~List() {
     	Link * node = head;
	Link * temp = node->next;
	if (head == nullptr) {
		return;
	}
	if (node->next == nullptr) {
		delete node;
		return;
	}
	while (temp->next != nullptr) {
		delete node;
		node = temp;
		temp = temp->next;
	}
	delete node;
	delete temp;

}

bool List::empty() const {
	if (head == nullptr) {
		return true;
	} else return false;
}

int List::size() const {
	int count = 0;
	if (head == nullptr) {
		return count;
	}
	Link * node = head;
	while (node != nullptr) {
		node = node->next;
		count++;
	}
	return count;
}

Iterator List::begin() const {
	return Iterator(head);
}

Iterator List::end() const {
	return Iterator(nullptr);
}

void List::push_back(int x) {
	if (head == nullptr) {
		head = new Link(x);
		return;
	}
	Link * node = head;
	while (node->next != nullptr) {
		node = node->next;
	}
	node->next = new Link(x);
}

void List::push_front(int x) {
	if (head == nullptr) {
		head = new Link(x);
		return;
	}
	Link * node = new Link(x);
	Link * node_temp = head;
	node->next = node_temp;
	head = node;
}

void List::insert(Iterator it, int x) {
	if (head == nullptr) {
		head = new Link(x, head);
		return;
	}
	Link * node = head;
	while (node->next != it.node) {
		node = node->next;
	}
	node->next = new Link(x, it.node);
}

void List::pop_back() {
	Link * node = head;
	if (head == nullptr) {
		return;
	}
	if (node->next == nullptr) {
		delete node;
		head = nullptr;
		return;
	}
	Link * node_temp = node->next;
	while (node_temp->next != nullptr) {
		node_temp = node_temp->next;
	}
	while (node->next != node_temp) {
		node = node->next;
	}
	delete node_temp;
	node->next = nullptr;
}

void List::pop_front() {
	Link * node_temp = head;
	if (head == nullptr) {
		return;
	}
	if (node_temp->next == nullptr) {
		delete node_temp;
		head = nullptr;
		return;
	}
	Link * node = node_temp->next;
	delete node_temp;
	head = node;

}

Iterator List::erase(Iterator it) {
	if (head == nullptr) {
		return Iterator(nullptr);
	}
	Link * node = head;
	Link * node_temp = it.node;
	if (node->next == nullptr) {
		delete node;
		return Iterator(nullptr);
	}
	while (node->next != node_temp) {
		node = node->next;
	}
	node->next = node->next->next;
	++it;
	delete node_temp;
	return Iterator(it);
}





