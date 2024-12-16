// 스택에서 학생의 학번을 검색하여, 
// 해당 학번의 학생이 스택에 존재하는지 확인하는 프로그램을 작성하시오. 
// 학생이 존재하면 해당 학생의 정보를 출력하고, 
// 존재하지 않으면 “학생을 찾을 수 없습니다.“라는 메시지를 출력하시오.

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

// 학번으로 학생을 검색하는 함수
Node* searchById(LinkedStack& stack, int id) {
    for (Node* p = stack.peek(); p != NULL; p = p->getLink()) {
        if (p->Student::id == id) {  // 학생의 학번을 비교
            return p;
        }
    }
    return NULL;
}

int main() {
    LinkedStack stack;

    // 스택에 학생 정보 삽입
    stack.push(new Node(2015130007, "홍길동", "컴퓨터공학과"));
    stack.push(new Node(2015130100, "이수연", "전자공학과"));
    stack.push(new Node(2015130135, "김영희", "기계공학과"));

    // 학번으로 학생 검색
    int searchId = 2015130100;
    Node* result = searchById(stack, searchId);
    if (result) {
        std::cout << "학생 정보를 찾았습니다." << std::endl;
        result->display();
    } else {
        std::cout << "학생을 찾을 수 없습니다." << std::endl;
    }

    return 0;
}