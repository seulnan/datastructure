// 문제 설명: 
// 1. 주어진 고객 큐를 이용하여 고객이 도착하고
// 각 고객이 서비스되는 과정을 구현하시오.
// 2. 새로운 고객이 도착하면 큐에 추가되고, 
// 현재 서비스 중인 고객이 끝나면 큐에서 제거하여 
// 다음 고객을 처리하는 과정을 반복하는 코드를 작성하시오.

#include <iostream>
using namespace std;

struct Customer
{
    int id, tArrival, tService;

    Customer(int i =0, int tArr =0, int tServ = 0): id(i), tArrival(tArr), tService(tServ){}
};

#define MAX_QUEUE_SIZE 100

class CustomerQueue{
    int front, rear;
    // customer구조체를 이용하여 data 배열 선언, 사용할땐 data[index].tArrival
    Customer data[MAX_QUEUE_SIZE];

public:
    CustomerQueue(): front(0), rear(0) {}

    bool isEmpty() { return front == rear; }

    bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

    void enqueue(Customer& val){
        if (!isFull()) {  //삽입이니까 비어있는지 확인해야됨 안비어있다면?
            rear = (rear + 1) % MAX_QUEUE_SIZE; //rear한칸늘리고
            data[rear] = val; //customer객체 참조해서 삽입하려는 데이터 rear에 넣기
        }
    }

    Customer& dequeue(){
        if(!isEmpty()){
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front]; //삭제하고 새로운 front return 
        }
        throw runtime_error("큐는 비어있다");
    }
};

int main(){
    CustomerQueue queue;
    int currentTime = 0, serviceTime = 0;

    for (int i = 1; i <= 5; ++i){
        Customer customer(i, currentTime, i * 2);
        queue.enqueue(customer);
    }

    while(!queue.isEmpt()){
        if(serviceTime == 0){
            Customer customer = queue.dequeue();   // CustomerQueue클래스를 이용해서 큐에서 디큐해서 current에 담기             
            serviceTime = customer.tService;
            // new customer가 current에 담김 new tService를 다시 servicetime에 넣기
            cout << "customer" << customer.id << "is being served." << customer.tArrival << "에 도착해서" << customer.tService<< "동안 걸렸다\n";
        }
        serviceTime--; //서비스타임 줄이고
        currentTime++; //현재시간 늘리고
    }
}