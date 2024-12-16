// 문자열을 입력받아, 재귀적으로 문자열을 뒤집는 프로그램을 작성하시오. 
// 이때 반복문은 사용하지 않고, 오직 재귀 호출만을 사용하여 문자열을 뒤집으시오.


#include <iostream>
#include <cstring>

// 문자열을 재귀적으로 뒤집는 함수
void reverse(char* str, int left, int right) {
    if (left >= right) {
        return;
    }

    // 문자열의 좌우 문자 교환
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    // 재귀적으로 내부 부분 문자열을 뒤집기
    reverse(str, left + 1, right - 1);
}

int main() {
    char str[80] = "I love data structure! I love koreatech!";
    std::cout << "원래 문자열: " << str << std::endl;

    reverse(str, 0, strlen(str) - 1);

    std::cout << "뒤집힌 문자열: " << str << std::endl;
    return 0;
}