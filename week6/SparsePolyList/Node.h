#pragma once
#include <iostream>
using namespace std;

struct Term {
	int expon;
	float coeff;
	Term(int expo = 0, float coef = 0) : expon(expo), coeff(coef) { }
	void print() {
		if (coeff != 0) {
			if (coeff > 0) cout << "+";
			cout << coeff;
			if (expon != 0)
				cout << "x^" << expon;
		}
	}
};

struct Node {
	Node* link;
	Term data;

	Node(int exp = 0, float coe = 0): data(exp, coe), link(NULL){}

	void display() { data.print(); }

	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};



