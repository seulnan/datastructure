#pragma once
#include "AdjMatGraph.h"
#include <stdlib.h>
#define INF		9999

class WGraph : public AdjMatGraph
{
public:
	WGraph() { }
	~WGraph() {  }

	bool hasEdge(int i, int j) { return (getEdge(i, j)<INF); }

	void insertEdge(int u, int v, int weight) {
		if (weight == INF) weight = INF;
		setEdge(u, v, weight);
		setEdge(v, u, weight);
	}


	void load(char *filename) {
		FILE *fp = fopen(filename, "r");
		if (fp != NULL) {
			int n, val;
			fscanf(fp, "%d", &n);
			for (int i = 0; i<n; i++) {
				char	str[80];
				int		val;
				fscanf(fp, "%s", str);
				insertVertex(str[0]);
				for (int j = 0; j<n; j++) {
					fscanf(fp, "%d", &val);
					insertEdge(i, j, val);
				}
			}
			fclose(fp);
		}
	}

	void randomFullWGraph(int nVtx, int maxW=1000) {
		int i, j, n, r, c;

		reset();
		for (i = 0; i < nVtx; i++) {
			insertVertex('A' + i);
			adj[i][i] = 0;
		}
		// fully connected graph
		for (i = 0; i<nVtx; i++)
			for (j = 0; j < i; j++)
				insertEdge(i, j, (rand() % maxW + 1));
	}

};
