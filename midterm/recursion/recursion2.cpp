// 2차원 배열을 사용하여 재귀 호출로 트리를 그리는 프로그램을 작성하시오. 
// 주어진 배열에서 중간 지점을 기준으로 좌우로 나뉘어 트리를 그리시오.


#include <iostream>
#define ROWS 6
#define COLS 64

// 2차원 배열로 트리 모양을 저장할 공간
char map[ROWS][COLS];

// 트리 배열을 초기화하는 함수
void initTree() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            map[i][j] = '-';
        }
    }
}

// 트리를 재귀적으로 그리는 함수
void drawTree(int row, int left, int right) {
    if (row >= ROWS || left > right) {
        return;
    }

    int mid = (left + right) / 2;
    map[row][mid] = 'X';  // 트리의 현재 위치에 표시

    // 재귀적으로 좌우로 트리 그리기
    drawTree(row + 1, left, mid - 1);
    drawTree(row + 1, mid + 1, right);
}

// 트리 배열을 출력하는 함수
void printTree() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    initTree();
    drawTree(0, 0, COLS - 1);
    printTree();
    return 0;
}