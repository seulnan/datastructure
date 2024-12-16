#pragma once

#include "Node.h"
class CircularList
{
	Node*	tail;	// 맨 마지막 노드의 포인터

public:
	CircularList() : tail(NULL) { }
	~CircularList() { clear(); }

	void clear() {
		while (!isEmpty()) delete remove(0);
	}
	Node* getHead() { return (tail != NULL) ? tail->link : NULL; }
	Node* getTail() { return tail; }
	bool isEmpty() { return getHead() == NULL; }

	Node* getEntry(int pos) {
		if (isEmpty()) return NULL;
		Node* n = getHead();
		for (int i = 0; i < pos; i++, n = n->link);
		return n;
	}

	void insert(int pos, Node *n) {
		Node* prev = (pos<=0) ? tail : getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
		else {
			tail = n;
			n->link = tail;
		}
	}

	Node* remove(int pos) {
		if (isEmpty()) return NULL;
		if (tail->link == tail) {
			Node* ret = tail;
			tail = NULL;
			return ret;
		}
		if (pos == 0)
			return tail->removeNext();
		else 
			return getEntry(pos - 1)->removeNext();
	}

	int size() {
		if (isEmpty()) return 0;
		int count = 1;
		for (Node *p = getHead(); p != tail; p = p->link)
			count++;
		return count;
	}

	void display(const char* str = "리스트" ) {
		printf("%s", str);
		printf("[원형연결리스트 항목 수 = %2d] : ", size());
		for (Node *p = getHead(); p != NULL; p = p->getLink()) {
			p->display();
			if (p == tail)
				break;
		}
		printf("\n");
	}
};