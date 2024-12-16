#include <iostream>
using namespace std;

// Term 구조체: 다항식의 하나의 항을 표현 (계수와 차수)
struct Term {
    int expon; // 차수
    float coeff; // 계수
    Term(int expo = 0, float coef = 0) : expon(expo), coeff(coef) {}
};

// Node 구조체: 연결 리스트의 노드를 표현
struct Node {
    Node* link; // 다음 노드를 가리키는 포인터
    Term data; // 다항식의 항 (계수와 차수)

    Node(int expo = 0, float coef = 0) : data(expo, coef), link(NULL) {}

    void insertNext(Node* n){
        if(n != NULL){ // 비어있거나 맨 앞일때
            n->link = link;
            link = n;
        }
    }
    
    Node* removeNext(){
        Node *removed = link;
        if(removed != NULL)
            link = removed->link;
        return removed;
    }
};

// LinkedList 클래스: 연결 리스트로 다항식을 관리
class LinkedList {
    Node org; // 연결 리스트의 시작 노드

public:
    LinkedList() : org(0, 0) {}
    ~LinkedList() { clear(); }

    void clear() {
        while (!isEmpty())
            delete remove(0);
    }

    Node* getHead() { return org.link; }
    bool isEmpty() { return getHead() == NULL; }

    Node* getEntry(int pos) {
        Node* n = &org;
        for (int i = -1; i < pos; n = n->link)
            if (n == NULL)
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

    Node* remove(int pos) {
        Node* prev = getEntry(pos - 1);
        return prev->removeNext();
    }

    int size() {
        int count = 0;
        for (Node* p = getHead(); p != NULL; p = p->link)
            count++;
        return count;
    }

    void display(const char* str = "다항식") {
        cout << str;
        for (Node* p = getHead(); p != NULL; p = p->link) {
            if (p != getHead() && p->data.coeff > 0)
                cout << "+"; // 양수인 항목 앞에 '+' 추가
            cout << p->data.coeff << "x^" << p->data.expon;
        }
        cout << endl;
    }
};

// Poly_Print 함수: 다항식을 출력하는 함수
void Poly_Print(LinkedList& poly, const char* name) {
    poly.display(name);
}

// Poly_Add 함수: 두 다항식을 더해서 새로운 다항식 C를 만드는 함수
void Poly_Add(LinkedList& A, LinkedList& B, LinkedList& C) {
    Node* p = A.getHead();
    Node* q = B.getHead();
    Term t;

    while (p != NULL || q != NULL) {
        if (p == NULL || (q != NULL && p->data.expon < q->data.expon)) {
            // B의 항을 결과 리스트 C에 추가
            C.insert(C.size(), new Node(q->data.expon, q->data.coeff));
            q = q->link;
        } else if (q == NULL || (p != NULL && p->data.expon > q->data.expon)) {
            // A의 항을 결과 리스트 C에 추가
            C.insert(C.size(), new Node(p->data.expon, p->data.coeff));
            p = p->link;
        } else {
            // A와 B의 차수가 같을 때, 두 계수를 더해서 C에 추가
            t = p->data;
            t.coeff += q->data.coeff;
            if (t.coeff != 0) {
                C.insert(C.size(), new Node(t.expon, t.coeff));
            }
            p = p->link;
            q = q->link;
        }
    }
}

int main() {
    LinkedList A, B, C;

    // 다항식 A 입력
    cout << "다항식 A를 입력하세요 (계수 차수):" << endl;
    while (true) {
        float coeff;
        int expon;
        cin >> coeff >> expon;
        if (expon < 0) break;
        A.insert(A.size(), new Node(expon, coeff));
    }

    // 다항식 A 출력
    Poly_Print(A, "A = ");

    // 다항식 B 입력
    cout << "다항식 B를 입력하세요 (계수 차수):" << endl;
    while (true) {
        float coeff;
        int expon;
        cin >> coeff >> expon;
        if (expon < 0) break;
        B.insert(B.size(), new Node(expon, coeff));
    }

    // 다항식 B 출력
    Poly_Print(B, "B = ");

    // 다항식 A와 B를 더해서 C를 만듦
    Poly_Add(A, B, C);

    // 다항식 C 출력
    Poly_Print(C, "C = A+B = ");
    
    // C의 첫 번째 항 (최고 차수 항) 및 그 계수 출력
    if (!C.isEmpty()) {
        Node* highestNode = C.getHead();  // 첫 번째 노드를 가져옴
        cout << "C의 최고차수는 " << highestNode->data.expon << "이고, 그 항의 계수는 " << highestNode->data.coeff << "이다." << endl;
    } else {
        cout << "C는 비어 있습니다." << endl;
    }

    return 0;
}