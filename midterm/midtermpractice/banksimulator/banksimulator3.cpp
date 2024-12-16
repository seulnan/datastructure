#include <iostream>

struct Customer {
    int id;
    int tArrival;
    int tService;

    Customer(int i = 0, int tArr = 0, int tServ = 0) : id(i), tArrival(tArr), tService(tServ) {}
};

#define MAX_QUEUE_SIZE 5

class CustomerQueue {
    int front, rear;
    Customer data[MAX_QUEUE_SIZE];

public:
    CustomerQueue() : front(0), rear(0) {}

    bool isEmpty() { return front == rear; }

    bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

    void enqueue(Customer& val) {
        if (isFull()) {
            std::cout << "Queue is full! Cannot add customer " << val.id << ".\n";
        } else {
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

    for (int i = 1; i <= 7; ++i) {  // 7명의 고객 시도 (큐는 5명만 수용 가능)
        Customer customer(i, 0, i * 2);
        queue.enqueue(customer);
    }

    while (!queue.isEmpty()) {
        Customer current = queue.dequeue();
        std::cout << "Customer " << current.id << " is being served.\n";
    }

    return 0;
}