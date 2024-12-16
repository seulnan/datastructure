#include <iostream>
using namespace std;

class Stack {
private:
    int topIndex;     // 스택의 현재 top을 가리키는 인덱스
    int capacity;     // 스택의 최대 용량
    int* stackArray;  // 스택을 저장할 배열

public:
    // 생성자: 스택의 크기를 정함
    Stack(int size) {
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;  // 초기에는 스택이 비어있으므로 -1
    }

    // 소멸자: 동적 배열을 해제
    ~Stack() {
        delete[] stackArray;
    }

    // 스택에 값을 추가 (push)
    void push(int value) {
        if (isFull()) {
            cout << "Error: 스택이 가득 찼습니다.\n";
        } else {
            stackArray[++topIndex] = value;
        }
    }

    // 스택에서 값을 제거하고 반환 (pop)
    int pop() {
        if (isEmpty()) {
            cout << "Error: 스택이 비어 있습니다.\n";
            return -1;  // 오류를 나타내는 값 반환
        } else {
            return stackArray[topIndex--];
        }
    }

    // 스택의 최상단 값을 반환 (pop하지 않고 확인)
    int top() {
        if (isEmpty()) {
            cout << "Error: 스택이 비어 있습니다.\n";
            return -1;  // 오류를 나타내는 값 반환
        } else {
            return stackArray[topIndex];
        }
    }

    // 스택이 비었는지 확인
    bool isEmpty() {
        return topIndex == -1;
    }

    // 스택이 가득 찼는지 확인
    bool isFull() {
        return topIndex == capacity - 1;
    }

    // 스택의 현재 크기 반환
    int size() {
        return topIndex + 1;
    }
};

// 테스트용 main 함수
int main() {
    Stack myStack(5);  // 크기 5의 스택 생성

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "스택의 최상단 값: " << myStack.top() << endl;

    cout << "스택에서 pop된 값: " << myStack.pop() << endl;
    cout << "스택에서 pop된 값: " << myStack.pop() << endl;

    if (myStack.isEmpty()) {
        cout << "스택이 비어 있습니다.\n";
    } else {
        cout << "스택에 값이 남아 있습니다.\n";
    }

    return 0;
}