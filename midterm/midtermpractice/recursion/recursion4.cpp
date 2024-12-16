// 주어진 문자열이 회문인지(앞뒤가 똑같은지) 재귀 호출을 사용하여
// 확인하는 프로그램을 작성하시오. 반복문을 사용하지 말고, 
// 오직 재귀 호출만을 사용하여 회문 여부를 검사하시오.

#include <iostream>
#include <cstring>
using namespace std;

bool isPalin(char * str, int left, int right){
    if(left>=right){
        return true;
    }

    if(str[left]!=str[right]){
        return false;
    }

    return isPalin(str, left + 1, right - 1);
}

int main(){
    char str[80];
    cout << "문자열을 입력: ";
    cin >> getline(str, 80);

    if(isPalin(str,0,strlen(str)-1)){
        cout << "입력한 문자열은 회문입니다." << endl;
    }else{
        cout << "입력한 문자열은 회문이 아닙니다." << endl;
    }
    return 0;
}