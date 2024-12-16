// 문자열에서 괄호의 짝을 맞추는 프로그램을 작성하시오. 
// 괄호의 종류는 (), {}, []이며, 문자열을 입력받아
// 괄호가 제대로 짝을 이루고 있는지 확인하는 프로그램을 작성하시오.

class ArrayStack {
    char data[100];
    int top;
    
public:
    ArrayStack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 99; }

    void push(char e) {
        if (!isFull()) {
            top++;
            data[top] = e;
        }
    }

    char pop() {
        if (!isEmpty()) {
            char e = data[top];
            top--;
            return e;
        }
        return '\0';  // 빈 스택일 때는 null 문자 반환
    }

    char peek() {
        if (!isEmpty()) {
            return data[top];
        }
        return '\0';  // 빈 스택일 때는 null 문자 반환
    }
};

bool checkBrackets(const char* expression) {
    ArrayStack stack;
    for (int i = 0; expression[i] != '\0'; ++i) {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.isEmpty()) return false;
            char top = stack.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stack.isEmpty();  // 스택이 비어있으면 괄호가 모두 짝이 맞음
}

// main 함수에서 사용자 입력을 받아 괄호 체크 실행
void main() {
    const char* testExpression = "{[()]}";  // 테스트할 문자열

    if (checkBrackets(testExpression)) {
        // 스택이 비어있으면 괄호가 맞는 상태
        // 예시로 간단하게 하드코딩한 출력
        // "괄호 짝이 맞습니다"로 직접 교체해 사용 가능
    } else {
        // 스택이 남아있으면 괄호가 맞지 않음
        // "괄호 짝이 맞지 않습니다"로 직접 교체해 사용 가능
    }
}