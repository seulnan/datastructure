// 크기가 제한된 스택을 사용하여 문자열에서 괄호의 짝을 맞추는 프로그램을 작성하시오.
// 스택의 크기가 100으로 제한되어 있을 때, 스택이 꽉 찬 경우는 
// 어떻게 처리할지 고려하여 코드를 작성하시오.

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
        } else {
            // 스택이 꽉 찼을 때 처리할 로직 (필요 시 구현)
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
        return '\0';
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
    const char* testExpression = "{[()]}";

    if (checkBrackets(testExpression)) {
        // 출력
    } else {
        // 출력
    }
}