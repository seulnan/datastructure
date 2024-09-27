#include <iostream>

int sumAlgorithmA(int n) {
    int sum = (n * (n + 1)) / 2;
    return sum;

}

int sumAlgorithmB(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int sumAlgorithmC(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum += j;
        }
    }
    return sum;
}


int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    int resultA = sumAlgorithmA(n);
    int resultB = sumAlgorithmB(n);
    int resultC = sumAlgorithmC(n);
    
    std::cout << "Sum of numbers from 1 to " << n << " using Algorithm A: " << resultA << std::endl;
    std::cout << "Sum of numbers from 1 to " << n << " using Algorithm B: " << resultB << std::endl;
    std::cout << "Sum of numbers from 1 to " << n << " using Algorithm C: " << resultC << std::endl;

    return 0;
}