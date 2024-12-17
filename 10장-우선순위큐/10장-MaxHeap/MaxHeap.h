#pragma once
#include "HeapNode.h"
#define MAX_ELEMENT	200

class MaxHeap
{
	HeapNode node[MAX_ELEMENT];
	int		 size;				
public:
	MaxHeap( ) : size(0) { }
	bool isEmpty()	{ return size == 0; }
	bool isFull()	{ return size == MAX_ELEMENT-1; }

	HeapNode&	getParent(int i){ return node[i/2]; }
	HeapNode&	getLeft(int i)	{ return node[i*2]; }
	HeapNode&	getRight(int i)	{ return node[i*2+1];}

	// 삽입 함수
	void insert( int key ) {
		if( isFull() ) return;

		int i = ++size;			

		while( i!=1							
			&& key>getParent(i).getKey()) {	
			node[i] = getParent(i);			
			i /= 2;							
		}
		node[i].setKey( key );				
	}

	// 삭제 함수
	HeapNode remove() { 
		if( isEmpty() ) return NULL;

		HeapNode root = node[1];		
		HeapNode last = node[size--];	

		int parent	= 1;				
		int	child	= 2;				

		while( child <= size ){			

		  if( child < size
		   && getLeft(parent).getKey() < getRight(parent).getKey())
			  child++;

		  if( last.getKey() >= node[child].getKey() ) break;

		  node[parent] = node[child];
		  parent = child;
		  child *= 2;
		}
		node[parent] = last;
		return root;
	} 
	HeapNode find() { return node[1]; }

	void display( ) {
		for(int i=1, level=1 ; i<= size ; i++){
			if( i == level ) {
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
	    printf("\n-------------------------------------------");
	}
};

// 우선 순위 큐인 힙을 이용한 정렬
inline void heapSort( int a[], int n)
{
	MaxHeap h;
	for(int i=0 ; i<n ; i++ )
		h.insert(a[i]);

	for(int i=n-1 ; i>=0 ;i-- )
		a[i] = h.remove().getKey();
}
