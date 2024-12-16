#include <iostream>
using namespace std;

int main(){
    
    int my_array[] = {23, 38, 56, 69, 74};

    char my_str[] = {'h', 'e', 'l', 'l', 'o'};

    char *ptr = my_str; // 배열의 이름은 포인터

    cout << *(my_str + 4) << endl;
    cout << ptr[4] << endl;

    return 0;
}