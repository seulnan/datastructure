// 두 개의 다항식을 입력받아, 두 다항식의 덧셈을 수행하는 프로그램을 작성하시오. 
// 덧셈 결과를 출력하는 함수를 구현하시오.

#include <iostream>
#define MAX_DEGREE 80

class Polynomial {
    int degree;
    float coef[MAX_DEGREE];

public:
    Polynomial() : degree(0) {
        for (int i = 0; i < MAX_DEGREE; i++) {
            coef[i] = 0;
        }
    }

    void read() {
        std::cout << "Enter the degree of the polynomial: ";
        std::cin >> degree;
        std::cout << "Enter the coefficients (from highest to lowest degree): ";
        for (int i = degree; i >= 0; i--) {
            std::cin >> coef[i];
        }
    }

    void print() {
        for (int i = degree; i > 0; i--) {
            std::cout << coef[i] << "x^" << i << " + ";
        }
        std::cout << coef[0] << std::endl;
    }

    Polynomial add(Polynomial a, Polynomial b) {
        Polynomial result;
        result.degree = std::max(a.degree, b.degree);

        for (int i = 0; i <= result.degree; i++) {
            result.coef[i] = a.coef[i] + b.coef[i];
        }

        return result;
    }
};

int main() {
    Polynomial a, b, sum;
    a.read();
    b.read();
    sum = sum.add(a, b);
    std::cout << "Sum of the two polynomials: ";
    sum.print();
    return 0;
}