#pragma once
#include "LinkedList.h"


struct MinPriorityQueue : public LinkedList {

	void insert(int val) {
		Node* prv = &(org);
		while (prv->link != NULL && prv->link->data < val)
			prv = prv->link;
		prv->insertNext(new Node(val));
	}
	int remove() {
		Node* n = org.link;
		if (n == NULL) return -1;

		org.link = n->link;
		int data = n->data;

		free(n);
		return data;
	}

	int find() {
		if (org.link != NULL)
			return org.link->data;
		else return -1;
	}
	void display() {
		Node* n = org.link;
		printf("PQueue(Min): ");
		for (; n != NULL; n = n->link) {
			printf("%3d ", n->data);
		}
		printf("\n");
	}
};
