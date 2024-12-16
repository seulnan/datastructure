#include "SrchAMGraph.h"

void main()
{
	SrchAMGraph g;
	g.load( "graph.txt" );
	printf("인접 행렬로 표현한 그래프\n");
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