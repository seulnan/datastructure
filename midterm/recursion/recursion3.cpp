// Ackermann 함수를 재귀적으로 구현하고, 
// m과 n에 대해 Ackermann 함수의 결과를 출력하는 프로그램을 작성하시오.

#include <iostream>

// Ackermann 함수 구현
int Ackermann(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return Ackermann(m - 1, 1);
    return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main() {
    std::cout << "Ackermann 함수 값 출력:\n";

    // Ackermann 함수의 값 출력
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << "Ackermann(" << i << "," << j << ") = " << Ackermann(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}