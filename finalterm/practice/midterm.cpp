#include <iostream>
using namespace std;

// 노드 구조체 정의
struct Node {
    int data;       // 노드의 데이터
    Node* next;     // 다음 노드를 가리키는 포인터
};

// 연결 리스트 클래스 정의
class LinkedList {
    Node* head;     // 리스트의 첫 노드를 가리키는 포인터

public:
    LinkedList() : head(nullptr) {} // 생성자 (빈 리스트 초기화)

    // 1. 특정 위치에 값 삽입
    void insert(int pos, int n) {
        Node* newNode = new Node{n, nullptr};
        if (pos == 0) { // 첫 번째 위치에 삽입
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            for (int i = 0; i < pos - 1 && curr; i++) {
                curr = curr->next;
            }
            if (curr) {
                newNode->next = curr->next;
                curr->next = newNode;
            } else {
                cout << "Invalid position!" << endl;
            }
        }
    }

    // 2. 리스트 출력
    void display(const string& str) {
        cout << str << ": ";
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // 3. 리스트에서 최대값 찾기
    int find_max() {
        if (!head) return -1; // 빈 리스트일 경우
        int maxVal = head->data;
        Node* curr = head->next;
        while (curr) {
            if (curr->data > maxVal) maxVal = curr->data;
            curr = curr->next;
        }
        return maxVal;
    }

    // 4. 부분 리스트의 합 계산
    int sublist_sum(int i, int j) {
        int sum = 0;
        Node* curr = head;
        for (int pos = 0; curr && pos <= j; pos++) {
            if (pos >= i) sum += curr->data;
            curr = curr->next;
        }
        return sum;
    }

    // 5. 부분 리스트 반전
    void reverse_sublist(int i, int j) {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        Node *sublistStart = nullptr, *sublistEnd = nullptr, *beforeSublist = nullptr;

        for (int pos = 0; curr && pos <= j; pos++) {
            if (pos == i - 1) beforeSublist = curr;
            if (pos == i) sublistStart = curr;
            if (pos == j) sublistEnd = curr;

            if (pos >= i && pos <= j) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            } else {
                curr = curr->next;
            }
        }

        if (beforeSublist) beforeSublist->next = sublistEnd;
        if (sublistStart) sublistStart->next = curr;
        if (i == 0) head = sublistEnd; // 서브리스트가 첫 번째일 경우
    }

    // 6. 배열 삽입
    void insert_array_at_position(int i, int a[], int n) {
        for (int k = 0; k < n; k++) {
            insert(i + k, a[k]);
        }
    }
};

int main() {
    LinkedList list;

    // 삽입
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(3, 40);
    list.display("Initial list");

    // 최대값 찾기
    cout << "Max value: " << list.find_max() << endl;

    // 부분 리스트 합
    cout << "Sum of sublist (1, 3): " << list.sublist_sum(1, 3) << endl;

    // 부분 리스트 반전
    list.reverse_sublist(1, 3);
    list.display("List after reversing sublist (1, 3)");

    // 배열 삽입
    int arr[] = {50, 60, 70};
    list.insert_array_at_position(2, arr, 3);
    list.display("List after inserting array at position 2");

    return 0;
}
