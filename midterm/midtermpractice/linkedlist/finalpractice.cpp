#include <iostream>
using namespace std;

struct Term{
    int chasu;
    float guesu;

    Term(int cha = 0, float gue =0): chasu(cha), guesu(gue){}
};

struct Node{
    Node *link;
    Term data;

    Node(int chasu=0, float guesu=0): data(chasu, guesu), link(NULL){}

    void insertNext(Node*n){
        if(n!=NULL){
            n->link = link;
            link = n;
        }
    }

    Node*removeNext(){
        Node *removed = link;
        if(removed!=NULL){
            link = removed->link;
        }
        return removed;
    }
};

class LinkedList{
    Node org;

public:
    LinkedList():org(0,0){}
    ~LinkedList() { clean(); }

    void clean(){
        while(!isEmpty()){
            delete remove(0);
        }
    }

    Node *getHead() { return org.link; }
    bool isEmpty() { return getHead() == NULL; }

    Node*getEntry(int pos){
        Node *n = &org;
        for (int i = -1; i < pos; n= n->link){
            if(n == NULL)
                break;
        }
        return n;
    }

    void insert(int pos, Node*){
        if(isEmpty()){
            org.link = n;
        }else{
            Node *p = getHead();
            while(p->link !=NULL){
                p = p->link;
            }
            p->insertNext(n);
        }
    }

    Node*remove(int pos){
        Node *prev = getEntry(pos - 1);
        prev -> removeNext();
    }

    int size(){
        int count = 0;
        for (Node *p = getHead(); p != NULL; p= p->link){
            count++;
        }
        return count;
    }

    void display(const char * str ="다항식"){
        cout << str;
        for (Node*p = getHead(); p != NULL; p= p->link){
            if(p!=getHead()&&p->data.guesu>0){
                cout << "+";
            }
            cout << p->data.guesu << "x^" << p->data.chasu;
        }
        cout << endl;
    }
};

void Poly_Print(LinkedList&poly, const char * name){
    poly.display(name);
}

void Poly_Add(LinkedList& A, LinkedList& B,LinkedList& C){
    Node *p = A.getHead();
    Node *q = B.getHead();
    Term t;

    while(p !=NULL || q!=NULL){
        if(p==NULL || (q !=NULL && q->data.chasu> p->data.chasu)){
            C.insert(C.size(), new Node(q->data.chasu, q->data.guesu));
            q = q->link;
        }else if(q==NULL || ( p!=NULL && p->data.chasu> q->data.chasu)){
            C.insert(C.size(), new Node(p->data.chasu, p->data.guesu));
            p = p->link;
        }else{
            t = p->data.chasu;
            t.guesu += q->data.guesu;
            if(t.guesu != 0){
                C.insert(C.size(), new Node(t.chasu, t.guesu));
            }
            p = p->link;
        }
    }
}

int main(){
    LinkedList A, B, C;

    cout << "다항식 a입력:";
    while(true){
        float guesu;
        int chasu;
        cin >> guesu >> chasu;
        if(chasu <0 )
            break;
        A.insert(A.size(), new Node(chasu, guesu));
    }

    Poly_Print(A, "A:");

    cout << "다항식 B입력:";
    while(true){
        float guesu;
        int chasu;
        cin >> guesu >> chasu;
        if (chasu < 0)
            break;
        B.insert(B.size(), new Node(chasu, guesu));
    }

    Poly_Print(B, "B:");

    Poly_Add(A, B, C);

    Poly_Print(C, "C= A+B: ");
   
    if(!C.isEmpty()){
        Node *higher = C.getHead();
        cout<< ""
    }

    return 0;
}