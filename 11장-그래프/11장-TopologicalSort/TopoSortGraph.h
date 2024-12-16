#pragma once
#include "AdjListGraph.h"
#include "ArrayStack.h"

class TopoSortGraph :	public AdjListGraph
{
public:
	TopoSortGraph(void) { }
	~TopoSortGraph(void) { }

	void insertDirEdge( int u, int v ) {	// 방향성 간선 삽입 연산
		adj[u] = new Node (v, adj[u]);	//
	}

	// 위상정렬을 수행한다.
	void TopoSort( ) {
		ArrayStack	s;

		// 모든 정점의 진입 차수를 계산
		int *inDeg = new int [ size ];

		for( int i=0 ; i<size ; i++ )		// 초기화
			inDeg[i] = 0;

		for( int i=0 ; i<size ; i++ ) {
			Node *node = adj[i];		//정점 i에서 나오는 간선들
			while ( node != NULL ) {
				inDeg[node->getId()]++;
				node = node->getLink();
			}
		}

		// 진입 차수가 0인 정점을 스택에 삽입
		for( int i=0 ; i<size ; i++ )
			if( inDeg[i] == 0 ) s.push( i );

		// 위상 순서를 생성 
		while( s.isEmpty() == false ) {
			int w = s.pop();
			printf(" %c ", getVertex(w));			//정점 출력
			Node *node = adj[w];	//각 정점의 진입 차수를 변경
			while (node != NULL) {
				int u = node->getId();
				inDeg[u]--;				//진입 차수를 감소
				if(inDeg[u] == 0)
					s.push( u );
				node = node->getLink();	// 다음 정점
			}
		}
		printf("\n");
		delete [] inDeg;
	}
};

