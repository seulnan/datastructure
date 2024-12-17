#include "MaxHeap.h"
#include <stdlib.h>

// 주함수 
void main()
{
	MaxHeap	heap;

	// 삽입
	heap.insert( 10 );
	heap.insert( 5 );
	heap.insert( 30 );
	heap.insert( 8 );
	heap.insert( 9 );
	heap.insert( 3 );
	heap.insert( 7 );
	heap.display();

	// 삭제
	heap.remove();
	heap.display();
	heap.remove();
	heap.display();

	// 정렬
	int data[10];
	for( int i=0 ; i<10 ; i++ )
		data[i] = rand() % 100;

	printf("\n정렬전: ");
	for( int i=0 ; i<10 ; i++ )
		printf( "%3d", data[i]);

	heapSort(data,10);

	printf("\n정렬후: ");
	for( int i=0 ; i<10 ; i++ )
		printf( "%3d", data[i]);
	printf("\n");
}
