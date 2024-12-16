#include "SrchALGraph.h"

void main()
{
	SrchALGraph g;
	g.load( "graph.txt" );
	printf("±×·¡ÇÁ(graph.txt)\n");
	g.display();

	printf("DFS ==> ");
	g.resetVisited();
	g.DFS( 0 );
	printf("\n");

	printf("BFS ==> ");
	g.resetVisited();
	g.BFS( 0 );
	printf("\n");
}
