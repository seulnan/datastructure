#include <iostream> 
#define MAX_TERMS 80
using namespace std;


struct Term{
    int expon; //차수
    float coeff; // 항의 계수
};

class SparsePoly{
    int nTerms; 
    Term term[MAX_TERMS]; // 구조체에 배열설정? 하는문법

    public:
        SparsePoly():nTerms(0){}

        void read(){
            nTerms = 0;
            while(true){
                cout << "Enter coefficient and exponent (-1 for exponent to end): ";
                cin >> term[nTerms].coeff >> term[nTerms].expon;
                if (term[nTerms].expon < 0) // 사용자가 차수에 -1을 입려갛면 입력을 종료
                    break;
                nTerms++; // 항 개수 증가
        }
        }

        void print(){
            for (int i = 0; i < nTerms; i++ ){
                cout << term[i].coeff << "x^" << term[i].expon;
                if(i != nTerms -1 ) // 마지막항이 아니라면 +출력해서 항들을 이어줌
                    cout << "+";
            }
            cout << endl; //이게왜있어야하지? 식을 프린트하고 줄넘김필요하니까
        }

        SparsePoly add(SparsePoly a, SparsePoly b){
            SparsePoly result;
            int i = 0, j = 0;
            while (i<a.nTerms || j < b.nTerms){
                if (i == a.nTerms || (j < b.nTerms && a.term[i].expon < b.term[j].expon)) {
                result.term[result.nTerms++] = b.term[j++];
            }else if (j == b.nTerms || (i < a.nTerms && a.term[i].expon > b.term[j].expon)) {
                result.term[result.nTerms++] = a.term[i++];
            }else {
                result.term[result.nTerms].expon = a.term[i].expon;
                result.term[result.nTerms++].coeff = a.term[i++].coeff + b.term[j++].coeff;
            }
        }
        return result;
    }
};

int main(){
    SparsePoly a, b, sum;
    a.read();
    b.read();
    sum = sum.add(a, b);
    cout << "두 희소 다항식 합:";
    sum.print();
    return 0;
}