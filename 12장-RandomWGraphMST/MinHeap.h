#pragma once
#include "HeapNode.h"
#define MAX_ELEMENT	200

class MinHeap
{
	HeapNode node[MAX_ELEMENT];
	int		 size;
public:
	MinHeap() : size(0) { }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode&	getParent(int i) { return node[i / 2]; }
	HeapNode&	getLeft(int i) { return node[i * 2]; }
	HeapNode&	getRight(int i) { return node[i * 2 + 1]; }

	// 삽입 함수
	void insert(int key, int u, int v) {
		if (isFull()) return;

		int i = ++size;

		while (i != 1
			&& key<getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].set(key, u, v);
	}

	// 삭제 함수
	HeapNode remove() {
		if (isEmpty()) return NULL;

		HeapNode root = node[1];
		HeapNode last = node[size--];

		int parent = 1;
		int	child = 2;

		while (child <= size) {
			if (child < size
				&& getLeft(parent).getKey() > getRight(parent).getKey())
				child++;

			if (last.getKey() <= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return root;
	}
};
