#pragma once
#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph
{
	int		label[MAX_VTXS];	// 정점의 색상
	int		count;
public:
	ConnectedComponentGraph() { }

	void labelDFS(int v, int color) {
		visited[v] = true;
		label[v] = color;
		//printf("%c ", getVertex(v));

		for (int w = 0; w<size; w++)
			if (isLinked(v, w) && visited[w] == false)
				labelDFS(w, color);
	}

	int findConnectedComponent(bool bReset = true) {
		count = 0;
		if (bReset) resetVisited();
		for (int i = 0; i<size; i++)
			if (visited[i] == false) {
				labelDFS(i, ++count);
			}
		return count;
	}

	void printComponents() {
		int i;
		printf("그래프 연결성분 개수 = %d\n", count);
		for (i = 0; i<size; i++)
			printf("%c=%d ", vertices[i], label[i]);
		printf("\n");
	}
};

