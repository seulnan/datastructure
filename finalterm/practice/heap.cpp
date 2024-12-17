#include <iostream>
#include <stdio.h>

#define MAX_ELEMENT 200

// HeapNode 클래스
struct HeapNode {
    int key;
    HeapNode(int key = 0) : key(key) {}
    ~HeapNode(void) {}
    void setKey(int k) { key = k; }
    int getKey() { return key; }
    void display() { printf("\t%d", key); }
};

// MaxHeap 클래스
class MaxHeap {
    HeapNode node[MAX_ELEMENT];
    int size;

public:
    MaxHeap() : size(0) {}

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT - 1; }

    HeapNode& getParent(int i) { return node[i / 2]; }
    HeapNode& getLeft(int i) { return node[i * 2]; }
    HeapNode& getRight(int i) { return node[i * 2 + 1]; }

    // 삽입 연산
    void insert(int key) {
        if (isFull()) {
            printf("Heap is full. Cannot insert.\n");
            return;
        }

        int i = ++size;

        while (i != 1 && key > getParent(i).getKey()) {
            node[i] = getParent(i); // 부모 노드를 현재 위치로 복사
            i /= 2;  // 부모 노드의 위치로 이동
        }
        node[i].setKey(key);  // 최종 위치에 새로운 키를 삽입
    }

    // 삭제 연산
    HeapNode remove() {
        if (isEmpty()) {
            printf("Heap is empty. Cannot remove.\n");
            return HeapNode(-1);
        }

        HeapNode root = node[1]; // 1. 루트 노드(최댓값)를 저장
        HeapNode last = node[size--]; // 2. 마지막 노드를 가져와 힙 크기 감소

        int parent = 1; // 3. 부모 노드의 인덱스를 루트로 설정
        int child = 2; // 4. 자식 노드의 인덱스는 왼쪽 자식으로 시작

        // 재배치
        while (child <= size) { // 5. 자식 노드가 존재할 때까지 반복
            if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
                child++; // 더 큰 자식 노드 선택 (왼쪽 vs 오른쪽)

            if (last.getKey() >= node[child].getKey()) break; // last가 자식보다 크면 종료
 
            node[parent] = node[child]; // 자식을 부모 자리로 이동
            parent = child; // 부모 노드를 아래로 이동 (레벨 한단계로 더 내려가서 반복하겠다는 뜻)
            child *= 2;  // 왼쪽 자식 노드로 이동
        }
        node[parent] = last; // 마지막 노드를 최종 위치에 삽입
        return root; // 삭제된 루트 노드 반환
    }

    void display() {
        for (int i = 1, level = 1; i <= size; i++) {
            if (i == level) {
                printf("\n");
                level *= 2;
            }
            node[i].display();
        }
        printf("\n-------------------------------------------");
    }

    // heapSort 함수 (원본 그대로)
    void heapSort(int a[], int n) {
    int i;
    MaxHeap h;

    for (i = 0; i < n; i++)
        h.insert(a[i]);

    for (i = n - 1; i >= 0; i--)
        a[i] = h.remove().key;
    }
};

int main() {
    MaxHeap heap;

    // 삽입 테스트
    heap.insert(10);
    heap.insert(5);
    heap.insert(30);
    heap.insert(8);
    heap.insert(9);
    heap.insert(3);
    heap.insert(7);
    heap.display();

    // 삭제 테스트
    heap.remove();
    heap.display();
    heap.remove();
    heap.display();

    // 힙 정렬 테스트
    int arr[] = { 15, 20, 30, 40, 10, 12, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before HeapSort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    heapSort(arr, n); // 원본 heapSort 함수 사용

    printf("After HeapSort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
