// 순환 연결 리스트에서 주어진 위치에 새로운 노드를 삽입하고, 
// 특정 위치의 노드를 삭제하는 함수를 구현하시오. 
// 또한, 리스트의 상태를 출력하는 프로그램을 작성하시오.

#include <iostream>
#pragma once
#include <stdio.h>
#include "Node.h"

// 연결 리스트의 Node 클래스
struct Node {
    int data;       // 노드가 저장할 데이터
    Node* link;     // 다음 노드를 가리킬 포인터

    // 생성자
    Node(int val = 0) : data(val), link(NULL) {}

    // 다음 노드를 반환하는 함수
    Node* getLink() {
        return link;
    }

    // 다음 노드를 설정하는 함수
    void setLink(Node* next) {
        link = next;
    }

    // 노드의 데이터를 출력하는 함수
    void display() {
        printf("<%2d> ", data);
    }

    // 다음 노드를 삽입하는 함수
    void insertNext(Node* n) {
        if (n != NULL) {
            n->link = link;
            link = n;
        }
    }

    // 다음 노드를 삭제하는 함수
    Node* removeNext() {
        Node* removed = link;
        if (removed != NULL) {
            link = removed->link;
        }
        return removed;
    }
};

// 연결 리스트를 구현한 LinkedList 클래스
class LinkedList {
    Node* head;   // 리스트의 첫 번째 노드를 가리키는 포인터

public:
    // 생성자: 리스트는 빈 상태로 시작
    LinkedList() : head(NULL) {}

    // 소멸자: 리스트를 비우고 메모리 해제
    ~LinkedList() {
        clear();
    }

    // 리스트가 비어 있는지 확인하는 함수
    bool isEmpty() {
        return head == NULL;
    }

    // 리스트의 크기를 반환하는 함수
    int size() {
        int count = 0;
        for (Node* p = head; p != NULL; p = p->getLink()) {
            count++;
        }
        return count;
    }

    // 리스트의 특정 위치에 있는 노드를 반환하는 함수
    Node* getEntry(int pos) {
        if (pos < 0) return NULL;
        Node* n = head;
        for (int i = 0; i < pos && n != NULL; i++) {
            n = n->getLink();
        }
        return n;
    }

    // 리스트의 특정 위치에 노드를 삽입하는 함수
    void insert(int pos, Node* n) {
        if (pos == 0) { // 첫 번째에 삽입
            n->setLink(head);
            head = n;
        } else {
            Node* prev = getEntry(pos - 1);
            if (prev != NULL) {
                prev->insertNext(n);
            }
        }
    }

    // 리스트의 특정 위치에 있는 노드를 삭제하는 함수
    Node* remove(int pos) {
        if (isEmpty()) return NULL;

        Node* removed;
        if (pos == 0) { // 첫 번째 노드를 삭제
            removed = head;
            head = head->getLink();
        } else {
            Node* prev = getEntry(pos - 1);
            if (prev != NULL) {
                removed = prev->removeNext();
            } else {
                return NULL;
            }
        }
        return removed;
    }

    // 리스트의 특정 위치의 노드를 교체하는 함수
    void replace(int pos, Node* n) {
        Node* prev = getEntry(pos - 1);
        if (prev != NULL) {
            Node* oldNode = prev->removeNext();
            prev->insertNext(n);
            delete oldNode;
        }
    }

    // 리스트를 초기화하고 모든 노드를 삭제하는 함수
    void clear() {
        while (!isEmpty()) {
            delete remove(0);
        }
    }

    // 리스트의 현재 상태를 출력하는 함수
    void display(const char* msg = "List") {
        printf("%s: ", msg);
        for (Node* p = head; p != NULL; p = p->getLink()) {
            p->display();
        }
        printf("\n");
    }
};

int main() {
    LinkedList list;

    // 리스트에 요소 삽입
    list.insert(0, new Node(10));
    list.insert(0, new Node(20));
    list.insert(1, new Node(30));
    list.insert(list.size(), new Node(40));
    list.insert(2, new Node(50));

    // 리스트 상태 출력
    list.display("List 초기 상태");

    // 리스트에서 특정 요소 삭제
    list.remove(2);
    list.display("List 요소 삭제 후");

    // 특정 요소 교체
    list.replace(1, new Node(90));
    list.display("List 요소 교체 후");

    // 리스트 초기화
    list.clear();
    list.display("List 초기화 후");

    return 0;
}

int main() {
    CircularList list;

    // 요소 삽입 (insert)
    list.insert(0, new Node(10));
    list.display("List(i1)");
    list.insert(0, new Node(20));
    list.display("List(i2)");
    list.insert(1, new Node(30));
    list.display("List(i3)");
    list.insert(0, new Node(40));
    list.display("List(i4)");
    list.insert(2, new Node(50));
    list.display("List(i5)");

    // 요소 삭제 (remove)
    list.remove(2);
    list.display("List(d2)");
    list.remove(1);
    list.display("List(d1)");

    // 리스트 초기화 (clear)
    list.clear();
    list.display("List(clear)");

    return 0;
}