// 연결 리스트 기반의 스택에 학생 정보를 삽입(푸시)하고, 
// 스택에서 요소를 제거(팝)한 후 스택의 상태를 출력하는 프로그램을 작성하시오. 
// 또한, 스택의 현재 상태를 출력하는 함수를 작성하시오.

#include <iostream>

#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_STRING 100

// 학생 정보를 담고 있는 Student 클래스
class Student {
    int id;                    // 학생의 학번
    char name[MAX_STRING];      // 학생 이름
    char dept[MAX_STRING];      // 학과명

public:
    // 생성자
    Student(int i = 0, const char* nam = "", const char* dep = "") { 
        set(i, nam, dep);
    }

    // 학생 정보를 설정하는 함수
    void set(int i, const char* nam, const char* dep) {
        id = i;
        strcpy(name, nam);
        strcpy(dept, dep);
    }

    // 학생 정보를 출력하는 함수
    void display() {
        printf("학번: %-15d 이름: %-10s 학과: %-20s\n", id, name, dept);
    }

    // 학생의 학번을 반환하는 함수
    int getId() {
        return id;
    }
};

// 연결 리스트의 Node 클래스
class Node : public Student {
    Node* link;  // 다음 노드를 가리키는 포인터

public:
    // 생성자
    Node(int id = 0, const char* name = "", const char* dept = "") 
        : Student(id, name, dept), link(NULL) {}

    // 다음 노드를 반환하는 함수
    Node* getLink() {
        return link;
    }

    // 다음 노드를 설정하는 함수
    void setLink(Node* p) {
        link = p;
    }
};
int main() {
    LinkedStack stack;

    // 스택에 학생 정보 삽입 (push)
    stack.push(new Node(2015130007, "홍길동", "컴퓨터공학과"));
    stack.push(new Node(2015130100, "이수연", "전자공학과"));
    stack.push(new Node(2015130135, "김영희", "기계공학과"));

    // 스택 상태 출력
    stack.display();

    // 스택에서 데이터 삭제 (pop) 후 상태 출력
    Node* node = stack.pop();
    std::cout << "[Pop된 노드]" << std::endl;
    node->display();
    delete node;

    // 스택 상태 출력
    stack.display();

    return 0;
}