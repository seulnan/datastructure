#include <iostream>
#include <stdio.h>

#define MAX_ELEMENT 200

struct HeapNode{
    int key;
    HeapNode(int key=0):key(key){}
    ~HeapNode(void){}
    void setKey(int k) { key = k; }
    int getKey() { return key; }
    void display() { printf("\t%d", key); }
};

class MaxHeap{
    HeapNode node[MAX_ELEMENT]; // 최대 힙을 표현하기 위해 HeapNode 객체 배열을 사용
    int size; // 현재 힙에 저장된 노드의 개수

public:
    MaxHeap(): size(0){}

    HeapNode &getParent(int i) { return node[i / 2]; }
    HeapNode &getLeft(int i) { return node[i * 2]; }
    HeapNode &getRight(int i) { return node[i * 2+1]; }

    void insert(int key)
    {
        int i = ++size;

        while (i != 1 && key>getParent(i).getKey()){
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].setKey(key);
    }

    void display(){}

    HeapNode remove(){
        HeapNode root = node
    }

};
int main()
{
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

    // 힙 정렬 실행
    heap.heapSort();

    return 0;
}
