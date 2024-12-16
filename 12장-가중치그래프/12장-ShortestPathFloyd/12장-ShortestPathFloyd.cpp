#include "WGraphFloyd.h"

void main()
{
	WGraphFloyd g;
	g.Load( "graph-Floyd.txt" );
	g.Print( "graph-Floyd.txt" );
	printf("Shortest Path By Floyd Algorithm\n");
	g.ShortestPathFloyd( ) ;
}

