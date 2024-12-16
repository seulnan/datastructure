// 연결 리스트를 기반으로 한 큐에 대한 기본적인 동작을 구현하시오. 
// 큐에 요소를 삽입(Enqueue)하고 삭제(Dequeue)한 후, 
// 큐의 상태를 출력하는 프로그램을 작성하시오.

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

// main 함수 (05장-LinkedQueueMain.cpp 파일)
int main() {
    LinkedQueue que;
    
    // 큐에 요소 삽입
    for (int i = 1; i < 10; i++) {
        que.enqueue(new Node(i));
    }

    // 큐 상태 출력
    que.display();

    // 큐에서 요소 삭제
    delete que.dequeue();
    delete que.dequeue();
    delete que.dequeue();

    // 큐 상태 출력
    que.display();

    return 0;
}