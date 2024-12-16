#pragma once

// WGraphMST: 최소 신장 트리(MST) 기능이 추가된 가중치 그래프 클래스
#include "MinHeap.h"
#include "WGraph.h"
#include "VertexSets.h"

class WGraphMST : public WGraph
{
public:
	// kruskal의 최소 비용 신장 트리 프로그램
	void Kruskal() {
		MinHeap heap;
		for (int i = 0; i<size - 1; i++) {
			for (int j = i + 1; j<size; j++)
				if (hasEdge(i, j)) {
					heap.insert(getEdge(i, j), i, j);
				}
		}

		VertexSets	set(size);
		int	edgeAccepted = 0;
		while (edgeAccepted < size - 1) {

			HeapNode& e = heap.remove();
			int uset = set.findSet(e.getV1());
			int vset = set.findSet(e.getV2());

			if (uset != vset) {
//				printf("간선 추가 : %c - %c (비용:%d)\n",
//					getVertex(e.getV1()), getVertex(e.getV2()), e.getKey());
				set.unionSets(uset, vset);
				edgeAccepted++;
			}
		}
	}


	// Prim의 최소 비용 신장 트리 프로그램
	void Prim() {
		// 
		bool	selected[MAX_VTXS];
		int		dist[MAX_VTXS];
		for (int i = 0; i<size; i++) {
			dist[i] = INF;
			selected[i] = false;
		}
		dist[0] = 0;

		for (int i = 0; i<size; i++) {
			int u = getMinVertex(selected, dist);

			selected[u] = true;
			if (dist[u] == INF) return;
//			printf("%c ", getVertex(u));

			for (int v = 0; v<size; v++)
				if (getEdge(u, v) != INF)
					if (!selected[v] && getEdge(u, v)< dist[v])
						dist[v] = getEdge(u, v);
		}
//		printf("\n");
	}
	int getMinVertex(bool* selected, int* dist) {
		int minv = 0;
		int mindist = INF;
		for (int v = 0; v<size; v++)
			if (!selected[v] && dist[v]<mindist) {
				mindist = dist[v];
				minv = v;
			}
		return minv;
	}
};
