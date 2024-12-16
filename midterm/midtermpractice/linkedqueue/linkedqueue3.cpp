// 큐에 삽입된 노드들을 동적으로 할당하고, 
// 프로그램 종료 시 모든 동적 할당된 노드를 안전하게 
// 해제하는 프로그램을 작성하시오. 
// 소멸자(~LinkedQueue())에서 큐에 남아 있는 모든 노드를 삭제하도록 하시오.

#include <iostream>

// Node 클래스 정의 (Node.h 파일)
class Node {
    Node* link;
    int data;
public:
    Node(int val = 0) : data(val), link(NULL) {}
    Node* getLink() { return link; }
    void setLink(Node* next) { link = next; }
    void display() { std::cout << "<" << data << "> "; }
};

// LinkedQueue 클래스 정의 (LinkedQueue.h 파일)
class LinkedQueue {
    Node* front;
    Node* rear;
public:
    LinkedQueue() : front(NULL), rear(NULL) {}
    ~LinkedQueue() { while (!isEmpty()) delete dequeue(); }

    bool isEmpty() { return front == NULL; }

    // 요소 삽입 함수
    void enqueue(Node* n) {
        if (isEmpty()) {
            front = rear = n;
        } else {
            rear->setLink(n);
            rear = n;
        }
    }

    // 요소 삭제 함수
    Node* dequeue() {
        if (isEmpty()) return NULL;
        Node* temp = front;
        front = front->getLink();
        if (front == NULL) rear = NULL;
        return temp;
    }

    // 큐의 현재 상태를 출력하는 함수
    void display() {
        std::cout << "[큐 상태]: ";
        for (Node* p = front; p != NULL; p = p->getLink()) {
            p->display();
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedQueue que;

    // 큐에 요소 삽입
    for (int i = 1; i <= 5; i++) {
        que.enqueue(new Node(i));
    }

    que.display();

    // 메모리 해제를 위한 큐 소멸자 테스트
    // 프로그램이 종료될 때 소멸자가 호출되어 모든 동적 할당된 메모리가 해제됩니다.
    return 0;
}