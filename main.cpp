#include <iostream>
#include <cassert>
#include "List.h"
#include "Iterator.h"
#include "Link.h"

using namespace std;

void test1() {

	List a;
	assert(a.empty() == true);
	assert(a.size() == 0);
	a.push_back(2);
	a.push_back(4);
	a.push_back(8);
	assert(a.size() == 3);

	Iterator it = a.begin();
	assert(*it == 2);
	++it;
	assert(*it == 4);
	++it;
	assert(*it == 8);

	it = a.begin();
	++it;
	++it;
	a.insert(it, 6);
	assert(a.size() == 4);
	it = a.begin();
	cout << *it << endl;
	++it;
	cout << *it << endl;
	++it;
	cout << *it << endl;
	++it;
	cout << *it << endl;
}

void test2() {

	List b;
	b.push_back(5);
	assert(b.size() == 1);
	b.pop_back();
	assert(b.empty() == true);
	assert(b.size() == 0);

	b.push_back(1);
	b.push_back(3);
	b.push_back(5);
	b.push_back(7);
	b.push_back(9);

	assert(b.size() == 5);

	b.pop_back();
	assert(b.size() == 4);

	Iterator it = b.begin();
	cout << *it << endl;
	++it; 
	cout << *it << endl;
	++it;
	cout << *it << endl;
	++it;
	cout << *it << endl;
}

void test3() {

	List c;
	c.push_back(10);
	c.pop_front();
	assert(c.size() == 0);

	c.push_back(10);
	c.push_back(20);
	c.push_back(30);
	c.push_back(40);
	c.push_back(50);

	c.pop_front();
	assert(c.size() == 4);

	Iterator it = c.begin();
	cout << *it << endl;
	++it;
	cout << *it << endl;
	++it;
	cout << *it << endl;
	++it;
	cout << *it << endl;
	
	c.push_front(10);
	assert(c.size() == 5);

	it = c.begin();
	cout << "push_front value should be 10: " <<*it << endl;
}

void test4() {

	List d;
	assert(d.size() == 0);
	d.push_back(100);
	d.push_back(200);
	d.push_back(300);
	d.push_back(400);
	d.push_back(500);
	assert (d.size() == 5);
	
	Iterator it = d.begin();
	++it;
	++it;
	d.erase(it);
	assert(d.size() == 4);
	it = d.begin();
	cout << *it << endl;
	++it;
	cout << *it << endl;
	++it;
	cout << *it << endl;
	++it; 
	cout << *it << endl;
}

int main () {

	test1();
	cout << "all tests1 passed" << endl;

	test2();
	cout << "all tests2 passed" << endl;

	test3();
	cout << "all tests3 passed" << endl;

	test4();
	cout << "all tests4 passed" << endl;

	return 0;
}



