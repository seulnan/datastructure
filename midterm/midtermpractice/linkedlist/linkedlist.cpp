#include <iostream>
using namespace std;

struct Term{
    int expon; // 차수
    float coeff; // 계수
    Term(int expo=0, float coef= 0): expon(expo), coeff(coef){}
    void print(){
        if(coeff!=0){
            if(coeff>0) cout << "+"; // 계수가 양수면 앞에 플러스가 있고
            cout << coeff; //계수출력, 하지만 음수면 앞에 마이너스있으니까 차수출력안해도됨
            if(expon!=0) //차수가 0이아니면
                cout << "x^" << expon;
        }
    }
};

struct Node {
    Node *link; //link라는 Node를 가리키는 포인터 저장
    Term data; // data라는 변수는 term구조체타입을 데이터로 저장

    Node(int expo=0, float coef=0):data(expo, coef),link(NULL){}
    
    void display() { data.print(); }

    void insertNext(Node*n){
        if(n!=NULL){ // 비어있거나 맨앞일때
            n->link = link;
            link = n;
        }
    }
    
    Node* removeNext(){
        Node *removed = link;
        if(removed!=NULL)
            link = removed->link;
        return removed;
    }
};

class LinkedList
{
    Node org;

public: 
    LinkedList(): org(0,0){}
    ~LinkedList() { clear(); }

    void clear(){while(!isEmpty())
            delete remove(0);
    }
    Node *getHead() { return org.link; }
    bool isEmpty() { return getHead() == NULL; }

    Node* getEntry(int pos){
        Node *n = &org;
        for (int i = -1; i < pos; n = n-> link)
            if(n==NULL)
                break;

        return n;
    }

    void insert(int pos, Node* n) {
    if (isEmpty()) {
        org.link = n;  // 리스트가 비어 있을 때
    } else {
        Node* p = getHead();
        while (p->link != NULL) {
            p = p->link;  // 리스트의 끝까지 이동
        }
        p->insertNext(n);  // 마지막에 새 노드 추가
    }
}

    Node* remove(int pos){
        Node *prev = getEntry(pos - 1);
        return prev->removeNext();
    }

    int size(){
        int count = 0;
        for (Node *p = getHead(); p != NULL; p = p->link)
            count++;
        return count;
    }

    void display(const char *str="다항식"){
        cout << str << size() << endl;
        cout << "단순연결리스트항목수 = ";
        for (Node *p = getHead(); p != NULL; p = p->link)
            p->display();
        cout << endl;
    }
};

class SparsePoly: public LinkedList{

public:
    void read(){
        int expo;
        float coef;

        while(true){
            cout << "계수&차수 입력(종료:-1):\n";
            cin >> coef >> expo;
            if(expo<0){
                display("입력다항식:");
                return;
            }
            insert(size(), new Node(expo, coef));
        }
    }

    void add(SparsePoly*a, SparsePoly*b){
        Node *i = a->getHead(), *j = b->getHead();
        Term t;

        for (; i != NULL || j != NULL;){
            if (i == NULL || (j != NULL) && (i->data.expon) < (j->data.expon)){
                insert(size(), new Node(*j));
                j = j->link;
            }
            else if(j==NULL || (i!=NULL)&& (i->data.expon)>(j->data.expon)){
                insert(size(), new Node(*i));
                i = i->link;
            }
            else{
                t = i->data;
                t.coeff += j->data.coeff;
                insert(size(), new Node(t.expon, t.coeff));
                i = i->link;
                j = j->link;
            }
        }
        
    }
};

int main(){

    SparsePoly a, b, c;
    a.read();
    b.read();
    c.add(&a, &b);

    a.display("A=");
    b.display("B= ");
    c.display("A+B=");
}