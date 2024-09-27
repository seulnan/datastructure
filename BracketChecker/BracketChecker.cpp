#include "ArrayStack.h"

int bracketChecker(const char* filename) {
    int nLine = 1, nChar = 0;
    int bSingle, bDouble, bLineCmt, bMLineCmt;
    char ch, ch2;
    ArrayStack stack;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        error("Error: 파일이 존재하지 않습니다.\n");

    bSingle = bDouble = bLineCmt = bMLineCmt = 0;
    while ((ch = getc(fp)) != EOF) {
        ch2 = getc(fp);
        ungetc(ch2, fp);
        if (ch == '\n') nLine++;
        nChar++;

        if (bSingle || bDouble || bLineCmt || bMLineCmt)
            continue;

        if (ch == '[' || ch == '(' || ch == '{')
            stack.push(ch);
        else if (ch == ']' || ch == ')' || ch == '}') {
            int prev = stack.pop();
            if ((ch == ']' && prev != '[') || (ch == ')' && prev != '(') || (ch == '}' && prev != '{'))
                break;
        }
    }
    fclose(fp);
    printf("[%s] 파일검사 결과:\n", filename);
    if (stack.isEmpty() == 0)
        printf("  오류발견 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
    else
        printf("  괄호정상 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
    return stack.isEmpty();
}

int main() {
    printf("왼쪽괄호 = (((((\n");
    printf("오른쪽괄호 = }}}}\n");
    bracketChecker("ArrayStack.h");
    bracketChecker("BracketChecker.cpp");

    return 0;
}