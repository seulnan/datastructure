#include "LinkedList.h"

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
