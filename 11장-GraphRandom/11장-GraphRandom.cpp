#include "ConnectedComponentGraph.h"
#include <stdlib.h>
#include <time.h>

void randomGraph(AdjMatGraph* g, int nVtx, int nEdge) {
	int i, n, r, c;

	g->reset();
	for (i = 0; i<nVtx; i++)
		g->insertVertex('A' + i);

	for (n = 0; n < nEdge; n++) {
		r = rand() % nVtx;
		c = rand() % nVtx;
		if (r != c && g->getEdge(r,c) == 0) {
			g->insertEdge2(r, c);
		}
		else n--;
	}
}
void randomConnectedGraph(ConnectedComponentGraph* g, int nVtx, int nEdge) {
	int r, c;

	randomGraph(g, nVtx, nEdge);

	while (g->findConnectedComponent() > 1) {
		r = rand() % nVtx;
		c = rand() % nVtx;
		if (r != c && g->getEdge(r,c) == 0)
			g->insertEdge2(r, c);
	}
}

int findBridge(ConnectedComponentGraph* g) {
	int i, j;
	int count = 0;
	g->resetVisited();

	for (i = 0; i < g->getSize(); i++) {
		for (j = 0; j < i; j++) {
			if (g->getEdge(i,j) != 0) {
				g->setEdge(i, j, 0);
				g->setEdge(j, i, 0);

				g->resetVisited();
				if (g->findConnectedComponent()>1) {
					printf(" Bridge%d: %c-%c\n", count+1, g->getVertex(i), g->getVertex(j));
					count++;
				}
				g->setEdge(i, j, 1);
				g->setEdge(j, i, 1);
			}
		}
	}
	return count;
}

double srchDFSAvgTime(int nVtx, int iter) {
	clock_t t0, t1;
	ConnectedComponentGraph g;
	int i, k;
	double dSum = 0;

	for (k = 0; k < 5; k++) {

		randomConnectedGraph(&g, nVtx, (int)(nVtx*1.5));

		for (i = 0; i < iter; i++) {
			g.resetVisited();
			t0 = clock();
			g.DFS(i%nVtx);
			t1 = clock();
			dSum += (double)(t1 - t0) / CLOCKS_PER_SEC;
		}
	}
	return dSum / (iter*5);
}


void main()
{
	int n;
	ConnectedComponentGraph g;

	srand((unsigned int)time(NULL));
	fprintf(stdout, "(11.1-1) randomGraph()\n");
	randomGraph(&g, 6, 4);
	g.display(stdout);

	printf("\n(11.1-2) 연결된 성분 개수\n");
	g.findConnectedComponent();
	g.printComponents();

	fprintf(stdout, "\n(11.1-3) randomConnectedGraph()\n");
	randomConnectedGraph(&g, 6, 6);
	g.display(stdout);

	g.findConnectedComponent();
	g.printComponents();

	printf("\n(11.2) Bridge 검사\n");
	findBridge(&g);

	printf("\n(11.3) 깊이 우선 탐색\n");
	for (n = 5; n < MAX_VTXS; n+=5) {
		printf("%4d %lf\n", n, srchDFSAvgTime(n, 10));
	}
}