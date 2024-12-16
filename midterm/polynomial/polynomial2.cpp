
// 문제 설명: 두 개의 희소 다항식을 입력받아, 
// 두 다항식의 덧셈을 수행하는 프로그램을 작성하시오. 
// 희소 다항식은 각 항의 계수와 차수만을 저장하므로, 
// 두 다항식의 각 항을 비교하여 결과를 계산해야 합니다.
#include <iostream>
#define MAX_TERMS 80

struct Term {
    int expon;
    float coeff;
};

class SparsePoly {
    int nTerms;
    Term term[MAX_TERMS];

public:
    SparsePoly() : nTerms(0) {}

    void read() {
        nTerms = 0;
        while (true) {
            std::cout << "Enter coefficient and exponent (-1 for exponent to end): ";
            std::cin >> term[nTerms].coeff >> term[nTerms].expon;
            if (term[nTerms].expon < 0) break;
            nTerms++;
        }
    }

    void print() {
        for (int i = 0; i < nTerms; i++) {
            std::cout << term[i].coeff << "x^" << term[i].expon;
            if (i != nTerms - 1) std::cout << " + ";
        }
        std::cout << std::endl;
    }

    SparsePoly add(SparsePoly a, SparsePoly b) {
        SparsePoly result;
        int i = 0, j = 0;
        while (i < a.nTerms || j < b.nTerms) {
            if (i == a.nTerms || (j < b.nTerms && a.term[i].expon < b.term[j].expon)) {
                result.term[result.nTerms++] = b.term[j++];
            } else if (j == b.nTerms || (i < a.nTerms && a.term[i].expon > b.term[j].expon)) {
                result.term[result.nTerms++] = a.term[i++];
            } else {
                result.term[result.nTerms].expon = a.term[i].expon;
                result.term[result.nTerms++].coeff = a.term[i++].coeff + b.term[j++].coeff;
            }
        }
        return result;
    }
};

int main() {
    SparsePoly a, b, sum;
    a.read();
    b.read();
    sum = sum.add(a, b);
    std::cout << "Sum of the two sparse polynomials: ";
    sum.print();
    return 0;
}