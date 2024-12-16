// 파일 입출력을 사용하지 않고,
// 문자열을 입력받아 괄호가 제대로 짝을 이루고 있는지 확인하는 프로그램을 작성하시오.

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
    return stack.isEmpty();
}

void main() {
    const char* testExpression = "{[()]}";  // 테스트할 문자열

    if (checkBrackets(testExpression)) {
        // 출력
    } else {
        // 출력
    }
}