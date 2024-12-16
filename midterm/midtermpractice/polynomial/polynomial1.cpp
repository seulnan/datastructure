#include <iostream>
using namespace std;
#define MAXDEGREE 80

class Polynomial {
    int degree;
    float coef[MAXDEGREE];

    public: 
        Polynomial(): degree(0){
            for (int i = 0; i < MAXDEGREE; i++){
                coef[i] = 0;
            }
        }

        void read(){
            cout << "차수입력:";
            cin >> degree;
            cout << "차수에 대한 계수입력:";
            for (int i = degree; i >= 0; i--){
                cin >> coef[i];
            }
        }
        
        void print(){
            for (int i = degree; i > 0; i--){
                cout << coef[i] << "x^" << i << "+";
            }
            cout << coef[0] << endl;
        }

        Polynomial add(Polynomial a, Polynomial b){ // Polynomial 클래스의 멤버함수 add, polynomial 객체 반환
            Polynomial result;
            result.degree = max(a.degree, b.degree); // 두 다항식 중 더 큰 차수를 결과의 차수로 설정합니다.
            for (int i = 0; i <= result.degree; i++){
                result.coef[i] = a.coef[i] + b.coef[i];

            }
            return result;
        }
};

int main(){
    Polynomial a, b, sum; // class polynomial을 이용해서 a, b, sum 객체 생성
    a.read();
    b.read();
    sum = sum.add(a, b); // add 멤버함수이용
    cout << "두 다항식 합:";
    sum.print();
    return 0;
}