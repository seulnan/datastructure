// 순환 연결 리스트에서 리스트의 크기를 반환하는 size() 함수를 구현하고, 
// 리스트가 순환하는 구조를 확인할 수 있도록 출력하는 프로그램을 작성하시오. 
// 리스트는 순환하는 구조를 갖고 있으며, 
// 마지막 요소는 다시 첫 번째 요소를 가리켜야 합니다.

#include <iostream>

// Node 클래스와 CircularList 클래스 정의는 첨부된 코드와 동일

int main() {
    CircularList list;

    // 요소 삽입
    list.insert(0, new Node(10));
    list.insert(0, new Node(20));
    list.insert(1, new Node(30));
    list.insert(0, new Node(40));
    list.insert(2, new Node(50));

    // 리스트 크기 출력
    printf("리스트 크기: %d\n", list.size());

    // 리스트 상태 출력 (순환 확인)
    list.display("List(순환 확인)");

    return 0;
}