#include "WGraphMST.h"
#include "WGraphDijkstra.h"
#include "WGraphFloyd.h"
#include <stdlib.h>
#include <time.h>

double srchMSTAvgTime(WGraph* g, int nVtx, int iter) {
	clock_t t0, t1, t2;
	int i, j, n, ntypes;
	double dSum1 = 0, dSum2 = 0;

	iter = 1;
	ntypes = 200;
	for (n = 0; n < ntypes; n++) {
		g->randomFullWGraph(nVtx, 99);
		for (i = 0; i < iter; i++) {
			t0 = clock();
			((WGraphMST*)g)->Kruskal();
			t1 = clock();
			((WGraphMST*)g)->Prim();
			t2 = clock();

			dSum1 += (double)(t1 - t0) / CLOCKS_PER_SEC;
			dSum2 += (double)(t2 - t1) / CLOCKS_PER_SEC;
		}
	}
	printf(" %15.8f %15.8f ", dSum1 / (iter * ntypes), dSum2 / (iter * ntypes));
	printf("\n");
	return (dSum1 + dSum2) / (iter * ntypes);
}


int		WGraphDijkstra::path[MAX_VTXS];
int		WGraphDijkstra::dist[MAX_VTXS];
int		WGraphDijkstra::found[MAX_VTXS];

int		WGraphFloyd::A[MAX_VTXS][MAX_VTXS];

double srchSPAvgTime(WGraph* g, int nVtx, int iter) {
	clock_t t0, t1, t2;
	int i, j, n, ntypes;
	double dSum1 = 0, dSum2 = 0;

	iter = 1;
	ntypes = 200;
	for (n = 0; n < ntypes; n++) {
		g->randomFullWGraph(nVtx, 99);
		for (i = 0; i < iter; i++) {
			t0 = clock();
			for (j = 0; j < g->getSize(); j++)
				((WGraphDijkstra*)g)->ShortestPath(j);
			t1 = clock();
			((WGraphFloyd*)g)->ShortestPathFloyd();
			t2 = clock();

			dSum1 += (double)(t1 - t0) / CLOCKS_PER_SEC;
			dSum2 += (double)(t2 - t1) / CLOCKS_PER_SEC;
		}
	}
	printf(" %15.8f %15.8f ", dSum1 / (iter * ntypes), dSum2 / (iter * ntypes));
	printf("\n");
	return (dSum1 + dSum2) / (iter * ntypes);
}


void main()
{
	int n;
	WGraph g;
	double	dA, dB;
	srand((unsigned int)time(NULL));

	printf("\n[12.(1)] Random Weighted Graph\n");
	g.randomFullWGraph(7, 99);
	g.display();

	g.randomFullWGraph(5, 99);
	g.display();

	printf("\n[12.(2)] MST :  Kruskal         Prim\n");

	for (n = 5 ; n < 100 ; n += 5) {
		printf("%-3d\t", n);
		srchMSTAvgTime(&g, n, 20);
	}

	printf("\n[12.(3)] SP :   Dijkstra        Floyd\n");
	for (n = 5; n < 100; n += 5) {
		printf("%-3d\t", n);
		srchSPAvgTime(&g, n, 20);
	}

}