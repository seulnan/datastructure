// 스택에 동적으로 할당된 모든 학생 노드를 안전하게 삭제하는 
// 소멸자(~LinkedStack())를 작성하시오. 
// 프로그램 종료 시, 스택에 남아 있는 모든 노드를 메모리에서 해제하시오.


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

    // 스택에 학생 정보 삽입
    stack.push(new Node(2015130007, "홍길동", "컴퓨터공학과"));
    stack.push(new Node(2015130100, "이수연", "전자공학과"));
    stack.push(new Node(2015130135, "김영희", "기계공학과"));

    stack.display();

    // 메모리 해제를 위해 프로그램 종료 시 소멸자가 호출됨
    // 소멸자는 스택에 남아 있는 모든 노드를 안전하게 메모리에서 해제합니다.
    return 0;
}