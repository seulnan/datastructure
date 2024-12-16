// 큐가 비어 있는지 확인하는 isEmpty() 함수를 구현하고,
// 비어 있는 상태에서의 삽입과 삭제 동작을 테스트하는 프로그램을 작성하시오. 
// 큐가 비었을 때 dequeue() 호출 시 NULL을 반환하도록 하시오.

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

    // 큐가 비어 있는지 확인
    if (que.isEmpty()) {
        std::cout << "큐가 비어 있습니다." << std::endl;
    }

    // 비어있는 큐에서 dequeue 시도
    Node* node = que.dequeue();
    if (node == NULL) {
        std::cout << "큐가 비어 있어 삭제할 요소가 없습니다." << std::endl;
    }

    // 요소 삽입 후 다시 확인
    que.enqueue(new Node(10));
    que.enqueue(new Node(20));
    que.display();

    return 0;
}