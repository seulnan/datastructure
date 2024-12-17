#pragma once
// WGraphFloyd.h: Floyd �˰������� �ִ� ��� Ž�� ����� �߰��� �׷���
#include "WGraph.h"
class WGraphFloyd : public WGraph
{
public:
	static int	A[MAX_VTXS][MAX_VTXS];		// �ִܰ�� �Ÿ�
	void ShortestPathFloyd() {
		for (int i = 0; i<size; i++)
			for (int j = 0; j<size; j++)
				A[i][j] = getEdge(i, j);

		for (int k = 0; k<size; k++) {
			for (int i = 0; i<size; i++)
				for (int j = 0; j<size; j++)
					if (A[i][k] + A[k][j] < A[i][j])
						A[i][j] = A[i][k] + A[k][j];
			//printA();
		}
	}
	void printA() {
		printf("====================================\n");
		for (int i = 0; i<size; i++) {
			for (int j = 0; j<size; j++) {
				if (A[i][j] == INF) printf(" INF ");
				else printf("%4d ", A[i][j]);
			}
			printf("\n");
		}
	}
};