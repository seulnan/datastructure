#include <time.h>
#include "SortAlgorithms.h"
extern void quickSort2(int v[], int left, int right);

void compareRandomDataSort(int iter) {
	clock_t t0, t1;
	int*	org = new int[MAX_NUM];
	int*	list = new int[MAX_NUM];
	int		n, i;
	double	dSel, dIns, dBub, dShl, dMgr, dHea, dQuk;

	printf("  n      선택     삽입     버블      셸      병합     히프     퀵\n");
	for (n = 1000; n < MAX_NUM; n += 3000) {
		dSel = dIns = dBub = dShl = dMgr = dHea = dQuk = 0.0;

		for (i = 0; i < iter; i++) {
			initRandom(org, n);
			//printf("선택 정렬:\n");
			copyArray(org, list, n);
			t0 = clock();
			selectionSort(list, n);
			t1 = clock();
			dSel += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("삽입 정렬:\n");
			copyArray(org, list, n);
			t0 = clock();
			insertionSort(list, n);
			t1 = clock();
			dIns += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("버블 정렬:\n");
			copyArray(org, list, n);
			t0 = clock();
			bubbleSort(list, n);
			t1 = clock();
			dBub += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("쉘 정렬:\n");
			copyArray(org, list, n);
			t0 = clock();
			shellSort(list, n);

			t1 = clock();
			dShl += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("병합 정렬:\n");
			copyArray(org, list, n);
			t0 = clock();
			mergeSort(list, 0, n - 1);
			t1 = clock();
			dMgr += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("히프 정렬:\n");
			copyArray(org, list, n);
			t0 = clock();
			heapSort(list, n);
			t1 = clock();
			dHea += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("퀵1 정렬:\n");
			copyArray(org, list, n);
			t0 = clock();
			//quickSort(list, 0, n - 1);
			quickSort2(list, 0, n - 1);
			t1 = clock();
			dQuk += (double)(t1 - t0) / CLOCKS_PER_SEC;
		}

		printf("%6d %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f\n", n,
			dSel / iter, dIns / iter, dBub / iter, dShl / iter, dMgr / iter, dHea / iter, dQuk / iter);
	}
	delete[] org;
	delete[] list;
}


void compareWorstDataSort(int iter) {
	clock_t t0, t1;
	int*	org = new int[MAX_NUM];
	int*	list = new int[MAX_NUM];
	int		n, i;
	double	dSel, dIns, dBub, dShl, dMgr, dHea, dQuk;

	printf("  n      선택     삽입     버블      셸      병합     히프     퀵\n");
	for (n = 1000; n < MAX_NUM; n += 1000) {
		dSel = dIns = dBub = dShl = dMgr = dHea = dQuk = 0.0;

		for (i = 0; i < iter; i++) {
			//initRandom(org, n);
			//printf("선택 정렬:\n");
			initRandom(list, n);		// 선택: 랜덤
			t0 = clock();
			selectionSort(list, n);
			t1 = clock();
			dSel += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("삽입 정렬:\n");
			initDescend(list, n);		// 삽입: 역순 최악
			t0 = clock();
			insertionSort(list, n);
			t1 = clock();
			dIns += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("버블 정렬:\n");
			initDescend(list, n);		// 버블: 역순 최악
			t0 = clock();
			bubbleSort(list, n);
			t1 = clock();
			dBub += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("쉘 정렬:\n");
			initRandom(list, n);		// 쉘: 랜덤
			t0 = clock();
			shellSort(list, n);

			t1 = clock();
			dShl += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("병합 정렬:\n");
			initRandom(list, n);		// 병합: 랜덤
			t0 = clock();
			mergeSort(list, 0, n - 1);
			t1 = clock();
			dMgr += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("히프 정렬:\n");
			initRandom(list, n);		// 히프: 랜덤
			t0 = clock();
			heapSort(list, n);
			t1 = clock();
			dHea += (double)(t1 - t0) / CLOCKS_PER_SEC;

			//printf("퀵1 정렬:\n");
			initAscend(list, n);		// 퀵: 정렬된 최악
			t0 = clock();
			quickSort2(list, 0, n - 1);
			//quickSort(list, 0, n - 1);
			//printArray(list, n, "QSort:");
			t1 = clock();
			dQuk += (double)(t1 - t0) / CLOCKS_PER_SEC;
		}

		printf("%6d %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f\n", n,
			dSel / iter, dIns / iter, dBub / iter, dShl / iter, dMgr / iter, dHea / iter, dQuk / iter);
	}
	free(org);
	free(list);
}


void main()
{
	printf("\n[13.(2)] 평균 실행 시간 (Random)\n");
	//compareRandomDataSort(2);
	printf("\n[13.(3)] 최악의 실행 시간\n");
	compareWorstDataSort(1);
}

