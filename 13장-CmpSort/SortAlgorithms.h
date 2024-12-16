#include <stdio.h>
#include <stdlib.h>
//#define MAX_NUM	85000
#define MAX_NUM	400000

extern void initRandom(int list[], int n);
extern void initAscend(int list[], int n);
extern void initDescend(int list[], int n);
extern void copyArray(int src[], int dst[], int n);
extern void printArray(int arr[], int n, char *str);

extern void insertionSort(int list[], int n);
extern void selectionSort(int list[], int n);
extern void bubbleSort(int list[], int n);
extern void shellSort(int list[], int n);
extern void mergeSort(int list[], int left, int right);
extern void heapSort(int list[], int n);
extern void quickSort(int list[], int left, int right);

