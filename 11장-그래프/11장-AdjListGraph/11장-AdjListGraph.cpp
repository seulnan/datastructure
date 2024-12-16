#include "AdjListGraph.h"

void main()
{
	AdjListGraph g;

	g.load("graph.txt");

	printf("인접 리스트로 표현한 그래프\n");
	g.display();

}