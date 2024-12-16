#include "WGraphDijkstra.h"

void main()
{
	WGraphDijkstra g;

	g.load( "graph_sp.txt" );
	printf("최단경로 탐색을 위한 그래프: graph_sp.txt\n");
	g.display();

	printf("Shortest Path By Dijkstra Algorithm\n");
	g.ShortestPath( 0 );

	for( int i=1 ; i<7 ; i++ )
		g.PrintPath(0,i);
}

