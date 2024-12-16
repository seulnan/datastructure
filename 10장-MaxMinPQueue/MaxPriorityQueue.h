#pragma once
#include <stdio.h>
#define MAX_ELEMENT	10000

struct MaxPriorityQueue {
	int		elem[MAX_ELEMENT];
	int		size;


	MaxPriorityQueue() { size = 0;  }

	void insert(int val) {
		elem[size++] = val;
	}
	int remove() {
		int i, max, iMax;
		max = elem[0];
		iMax = 0;
		for (i = 1; i < size; i++) {
			if (max < elem[i]) {
				max = elem[i];
				iMax = i;
			}
		}
		for (i = iMax; i < size - 1; i++)
			elem[i] = elem[i + 1];
		size--;
		return max;
	}

	int find() {
		int i, max, iMax;
		max = elem[0];
		iMax = 0;
		for (i = 1; i < size; i++) {
			if (max < elem[i]) {
				max = elem[i];
				iMax = i;
			}
		}
		return max;
	}
	void display() {
		int i, max, iMax;
		printf("PQueue(Max): ");
		for (i = 0; i < size; i++) {
			printf("%3d ", elem[i]);
		}
		printf("\n");
	}
};
