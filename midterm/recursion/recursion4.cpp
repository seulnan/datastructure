// 주어진 문자열이 회문인지(앞뒤가 똑같은지) 재귀 호출을 사용하여
// 확인하는 프로그램을 작성하시오. 반복문을 사용하지 말고, 
// 오직 재귀 호출만을 사용하여 회문 여부를 검사하시오.

#include <iostream>
#include <cstring>

// 문자열이 회문인지 확인하는 재귀 함수
bool isPalindrome(char* str, int left, int right) {
    if (left >= right) {
        return true;  // 중간에 도달하면 회문임
    }

    // 좌우 문자가 다르면 회문이 아님
    if (str[left] != str[right]) {
        return false;
    }

    // 재귀적으로 내부의 부분 문자열을 확인
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    char str[80];
    std::cout << "문자열을 입력하세요: ";
    std::cin.getline(str, 80);

    if (isPalindrome(str, 0, strlen(str) - 1)) {
        std::cout << "입력한 문자열은 회문입니다." << std::endl;
    } else {
        std::cout << "입력한 문자열은 회문이 아닙니다." << std::endl;
    }

    return 0;
}