// 연결 리스트를 기반으로 한 큐에 대한 기본적인 동작을 구현하시오. 
// 큐에 요소를 삽입(Enqueue)하고 삭제(Dequeue)한 후, 
// 큐의 상태를 출력하는 프로그램을 작성하시오.

#include <iostream>
using namespace std;

// 노드는 데이터를 저장하고 다음 노드를 가리키는 포인터가짐
class Node {
    Node *link; // 다음 노드를 가리키는 포인터 link
    int data; // 노드가 저장하는 값
    
public:
    // 노드생성자, 값을 지정할수있고 디폴트는 0
    Node(int val = 0): data(val), link(NULL){} 
    // 다음 노드를 가리키는 포인터를 반환
    Node *getLink() { return link; }
    // 다음 노드의 주소를 설정 
    void setLink(Node *next){  link = next; }
    // 이 노드가 가지고있는 데이터 출력
    void display() { cout << "<" << data << ">"; }
};

class LinkedQueue{
    Node *front; // 첫번째 노드를 가리키는 포인터
    Node *rear; // 마지막 노드를 가리키는 포인터
public:
    // 생성자: 처음에 큐가 비어있으므로 front&rear NULL설정
    LinkedQueue():front(NULL), rear(NULL){}
    // 소멸자: 프로그램이 끝날때 안비어있으면 계속 삭제, 비어있을때까지 삭제
    ~LinkedQueue(){while (!isEmpty())
            delete dequeue();
    }

    // 큐가 비어있는지 front는 null
    bool isEmpty() { return front == NULL; }

    // 큐의 끝에 새로운 노드 추가 
    void enqueue(Node *n){
        if(isEmpty()){
            front = rear = n; // 비어있으면 front&rear모두 그 노드를 가리킴
        }else{
            rear->setLink(n); // rear가 가리키는 노드의 link를 새 노드 n으로 설정
            rear = n; // 안비었으면 rear가 그 노드를 가리키게! 
        }
    };

    Node* dequeue(){
        if(isEmpty())
            return NULL; // 비어있다면 null반환(삭제할게 없잖아)

        Node *temp = front; 
        front = front->getLink(); // front
        if (front == NULL) 
            rear = NULL;

        return temp;
    }

    void display(){
        cout << "큐상태 ";
        for (Node *p = front; p != NULL; p = p-> getLink()){
            p->display();
        }
        cout << endl;
    }
};

int main(){
    LinkedQueue que; // LinkedeQueue클래스를 이용하여 que라는 이름으로 생성

    for (int i = 1; i < 10; i++){
        que.enqueue(new Node(i)); // Node 객체를 동적으로 생성하여 큐에 넣는과정
    }

    que.display(); // 큐 현재상태 출력

    delete que.dequeue();
    delete que.dequeue();
    delete que.dequeue();

    que.display();

    return 0;
}