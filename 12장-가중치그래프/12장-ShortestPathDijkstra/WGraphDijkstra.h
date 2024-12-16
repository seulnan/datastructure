#pragma once
#include "WGraph.h"

class WGraphDijkstra : public WGraph
{
	int		path[MAX_VTXS];	
	int		dist[MAX_VTXS];	
	int		found[MAX_VTXS];
public:
	WGraphDijkstra(void) { }
	~WGraphDijkstra(void){ }

	void PrintDistance() {
		for( int i=0 ; i<size ; i++)
			printf("%5d", dist[i]);
		printf("\n");
	}
	void PrintPath( int start, int end ) {  
		printf("[최단경로: %c<-%c] %c", getVertex(start), getVertex(end), getVertex(end));
		while (path[end] != start) {
			printf("-%c", getVertex(path[end]));
			end = path[end];
		}
		printf("-%c\n", getVertex(path[end]));
	}

	int chooseVertex() {
		int min		= INF;
		int minpos	= -1;
		for( int i=0 ; i<size ; i++ )
			if( dist[i]< min && ! found[i] ){
				min = dist[i];
				minpos=i;
			}
		return minpos;
	}

	void ShortestPath( int start ) {

		for( int i=0 ; i<size ; i++) {
			dist[i] = getEdge(start,i);
			path[i] = start;
			found[i] = 0;
		}
		found[start] = 1;		
		dist[start] = 0;		

		for( int i=0 ; i<size ; i++ ){
			printf("Step%2d:", i+1);
			PrintDistance();
			int u = chooseVertex();
			found[u] = 1;

			for( int w=0 ; w<size ; w++) {
				if( found[w] == 0 ) {
					if( dist[u] + getEdge(u,w) < dist[w] ) {
						dist[w] = dist[u] + getEdge(u,w);
						path[w] = u;
					}
				}
			}
		}
	}
};


