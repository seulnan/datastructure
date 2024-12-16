// 두 개의 다항식을 입력받아, 두 다항식의 곱셈을 수행하는 프로그램을 작성하시오
// 다항식의 곱셈은 각 항의 계수와 차수를 계산하여 결과 다항식을 구합니다.


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

    Polynomial mult(Polynomial a, Polynomial b) {
        Polynomial result;
        result.degree = a.degree + b.degree;

        for (int i = 0; i <= a.degree; i++) {
            for (int j = 0; j <= b.degree; j++) {
                result.coef[i + j] += a.coef[i] * b.coef[j];
            }
        }

        return result;
    }
};

int main() {
    Polynomial a, b, product;
    a.read();
    b.read();
    product = product.mult(a, b);
    std::cout << "Product of the two polynomials: ";
    product.print();
    return 0;
}