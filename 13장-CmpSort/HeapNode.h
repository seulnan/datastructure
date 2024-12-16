#pragma once
#include <stdio.h>
struct HeapNode
{
	int		key;
	HeapNode(int key = 0) : key(key) { }
	~HeapNode(void) { }
	void setKey(int k) { key = k; }
	int	 getKey() { return key; }
	void display() { printf("\t%d", key); }
};

