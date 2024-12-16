#pragma once

#include "Node.h"
class LinkedList
{
   Node org;   // 헤드 노드 (헤드 포인터가 아님)
   // org 는 리스트의 첫번째 노드 이전에 존재하는 더미 노드
   // 리스트의 시작을 나타내지만, 실제 데이터를 담진 않음 
   // 데이터를 저장하는 노드가 아니라 연결리스트의 구조를 관리하는 역할

public:
	LinkedList() : org(0) { }
	~LinkedList() { clear(); }

	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.link; }
	bool isEmpty() { return getHead() == NULL; }

	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->link)
			if (n == NULL) break;
		return n; 
	}

	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->link)
			count++;
		return count;
	}

	void display(const char* str = "다항식") {
		cout << str;
		cout << "단순연결리스트 항목 수 = "<< size();
		for (Node* p = getHead(); p != NULL; p = p->link)
			p->display();
		cout << endl;
	}
};