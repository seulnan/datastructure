#pragma once
#include "AdjListGraph.h"
#include "CircularQueue.h"

class SrchALGraph : public AdjListGraph
{
	bool	visited[MAX_VTXS];		
public:
	void resetVisited() {			
		for( int i=0 ; i<size ; i++ )
			visited[i] = false;
	}
	bool isLinked(int u, int v) {
		for( Node *p=adj[u] ; p!=NULL ; p=p->getLink() )
			if( p->getId() == v ) return true;
		return false;
	}

	// ±íÀÌ ¿ì¼± Å½»ö 
	void DFS( int v) {
		visited[v] = true;			
		printf("%c ", getVertex(v));

		for( Node *p=adj[v] ; p!=NULL ; p=p->getLink())
			if(visited[p->getId()] == false)
				DFS(p->getId());
	}

	// ³Êºñ ¿ì¼± Å½»ö
	void BFS( int v ) {
		visited[v] = true;				
		printf("%c ", getVertex(v));	

		CircularQueue que;
		que.enqueue( v );				

 		while(!que.isEmpty()){
 			int v = que.dequeue();		
			for( Node *w=adj[v] ; w!=NULL ; w=w->getLink() ) {
				int id = w->getId();	
				if(!visited[id]){		
   					visited[id] = true;	
					printf("%c ", getVertex(id));
					que.enqueue(id);	
				}
			}
		}
	}
};


