// 문제 설명: 
// 1. 주어진 고객 큐를 이용하여 고객이 도착하고
// 각 고객이 서비스되는 과정을 구현하시오.
// 2. 새로운 고객이 도착하면 큐에 추가되고, 
// 현재 서비스 중인 고객이 끝나면 큐에서 제거하여 
// 다음 고객을 처리하는 과정을 반복하는 코드를 작성하시오.


#include <iostream>

struct Customer {
    int id;
    int tArrival; // 도착한 시간
    int tService; // 서비스 받는 시간

    Customer(int i = 0, int tArr = 0, int tServ = 0) : id(i), tArrival(tArr), tService(tServ) {}
};

#define MAX_QUEUE_SIZE 100

class CustomerQueue {
    int front, rear;
    Customer data[MAX_QUEUE_SIZE];

public:
    CustomerQueue() : front(0), rear(0) {}

    bool isEmpty() { return front == rear; }

    bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

    void enqueue(Customer& val) {
        if (!isFull()) {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    Customer& dequeue() 
        if (!isEmpty()) {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
        throw std::runtime_error("Queue is empty");
};

int main() {
    CustomerQueue queue;
    int currentTime = 0, serviceTime = 0;

    for (int i = 1; i <= 5; ++i) {
        Customer customer(i, currentTime, i * 2);  // 고객 ID, 도착 시간, 서비스 시간
        queue.enqueue(customer);
    }

    while (!queue.isEmpty()) {
        if (serviceTime == 0) {
            Customer current = queue.dequeue();
            serviceTime = current.tService;
            std::cout << "Customer " << current.id << " is being served.\n";
        }
        serviceTime--;
        currentTime++;
    }

    return 0;
}