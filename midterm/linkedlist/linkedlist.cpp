#include <iostream>
using namespace std;

struct Term {
	int expon;
	float coeff;
	Term(int expo = 0, float coef = 0) : expon(expo), coeff(coef) { }
	void print() {
		if (coeff != 0) {
			if (coeff > 0) cout << "+";
			cout << coeff;
			if (expon != 0)
				cout << "x^" << expon;
		}
	}
};

struct Node {
	Node* link;
	Term data;

	Node(int exp = 0, float coe = 0): data(exp, coe), link(NULL){}

	void display() { data.print(); }

	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};

class LinkedList
{
   Node org;   // 헤드 노드 (헤드 포인터가 아님)
   // org 는 리스트의 첫번째 노드 이전에 존재하는 더미 노드
   // 리스트의 시작을 나타내지만, 실제 데이터를 담진 않음 
   // 데이터를 저장하는 노드가 아니라 연결리스트의 구조를 관리하는 역할

public:
	LinkedList() : org(0) { }
	~LinkedList() { clear(); }

	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.link; }
	bool isEmpty() { return getHead() == NULL; }

	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->link)
			if (n == NULL) break;
		return n; 
	}

	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
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
		cout << "단순연결리스트 항목 수 = "<< size();
		for (Node* p = getHead(); p != NULL; p = p->link)
			p->display();
		cout << endl;
	}
};

class SparsePoly : public LinkedList {

public:
	void read() {
		int expo; // 차수
		float coef; // 계수

		// Term t;
		while (1) {
			cout <<"계수 차수 입력(종료:-1): ";
			cin >> coef >> expo;
			if (expo < 0) {
				display("입력 다항식:");
				return;
			}
			insert(size(), new Node(expo, coef));
		}
	}

	void add(SparsePoly* a, SparsePoly* b) {
		Node* i = a->getHead(), * j = b->getHead();
		Term t;

		for (; i != NULL || j != NULL;) {           //둘 중 뭐라도 남아있다면
			if (i == NULL || ((j != NULL) && (i->data.expon < j->data.expon))) { //i가 비었을 때  / j는 있는데, i보다 차수가 클때
				insert(size(), new Node(*j)); // b의 남은 항 또는 더 큰 지수 항 추가
				j = j->link;
			}
			else if (j == NULL || ((i != NULL) && i->data.expon > j->data.expon)) { //j가 비었을 때  / i는 있는데, j보다 차수가 클때
				insert(size(), new Node(*i)); //a의 남은 항 또는 더 큰 지수 항 추가
				i = i->link;
			}
			else {          //i와j의 차수가 같다면
				t = i->data;
				t.coeff += j->data.coeff;  //i,j의 계수 더하기
				insert(size(), new Node(t.expon, t.coeff)); //새로운 노드 만들어서 추가
				i = i->link;
				j = j->link;
			}
		}
	}
};

int main()
{
	SparsePoly a, b, c;
	a.read();
	b.read();
	c.add(&a, &b);

	a.display(" A = ");
	b.display(" B = ");
	c.display("A+B= ");
}