#include <iostream>

struct Customer {
    int id;
    int tArrival;
    int tService;

    Customer(int i = 0, int tArr = 0, int tServ = 0) : id(i), tArrival(tArr), tService(tServ) {}
};

#define MAX_QUEUE_SIZE 100

class CustomerQueue {
    int front, rear;
    Customer data[MAX_QUEUE_SIZE];

public:
    CustomerQueue() : front(0), rear(0) {}

    bool isEmpty() { return front == rear; }

    void enqueue(Customer& val) {
        if ((rear + 1) % MAX_QUEUE_SIZE != front) {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    Customer& dequeue() {
        if (!isEmpty()) {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
        throw std::runtime_error("Queue is empty");
    }
};

int main() {
    CustomerQueue queue;
    int totalWaitTime = 0, currentTime = 0;

    for (int i = 1; i <= 5; ++i) {
        Customer customer(i, currentTime, i * 2);
        queue.enqueue(customer);
        currentTime += 1;  // 각 고객은 1 단위 시간에 도착
    }

    currentTime = 0;
    while (!queue.isEmpty()) {
        Customer current = queue.dequeue();
        int waitTime = currentTime - current.tArrival;
        totalWaitTime += waitTime;
        currentTime += current.tService;
        std::cout << "Customer " << current.id << " waited " << waitTime << " units of time.\n";
    }

    std::cout << "Total wait time: " << totalWaitTime << " units.\n";
    return 0;
}