// 일반 연결 리스트에서 특정 위치의 노드를 다른 노드로 교체하는 replace() 함수를 구현하고, 
// 모든 노드를 삭제하여 리스트를 초기화하는 프로그램을 작성하시오. 
// 노드 교체 후, 리스트의 상태를 출력하는 프로그램을 작성하시오.

#include <iostream>

// Node 클래스와 LinkedList 클래스 정의는 첨부된 코드와 동일

int main() {
    LinkedList list;

    // 요소 삽입
    list.insert(0, new Node(10));
    list.insert(0, new Node(20));
    list.insert(1, new Node(30));
    list.insert(list.size(), new Node(40));
    list.insert(2, new Node(50));
    list.display();

    // 특정 위치의 요소 교체 (replace)
    list.replace(1, new Node(90));
    list.display("List(교체 후)");

    // 리스트 초기화 (clear)
    list.clear();
    list.display("List(초기화 후)");

    return 0;
}