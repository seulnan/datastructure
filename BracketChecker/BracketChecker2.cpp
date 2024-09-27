#include "ArrayStack.h"

int bracketChecker( char* filename ) {
	int nLine = 1, nChar = 0;
	int bSingle, bDouble, bLineCmt, bMLineCmt;
	char	ch, ch2;
	ArrayStack	stack;

	FILE *fp = fopen( filename, "r" );
	if( fp == NULL )
		error("Error: 파일 존재하지 않습니다.\n");


	bSingle = bDouble = bLineCmt = bMLineCmt = 0;
	while ((ch = getc(fp)) != EOF) {
		ch2 = getc(fp);
		ungetc(ch2, fp);
		if( ch == '\n' ) nLine++;
		nChar++;

		// hello {
		/* [[[ */
		if (bLineCmt && ch == '\n') { bLineCmt = 0; }
		if (bMLineCmt && ch=='*' && ch2=='/') { bMLineCmt = 0; }
		if (ch == 39) { bSingle = 1 - bSingle; }
		if (ch == 34) { bDouble = 1 - bDouble; }
		if (bLineCmt == 0 && ch == '/' && ch2 == '/') bLineCmt = 1;
		if (bMLineCmt== 0 && ch == '/' && ch2 == '*') bMLineCmt = 1;

		if (bSingle || bDouble || bLineCmt || bMLineCmt)
			continue;

		if( ch == '[' || ch == '(' || ch == '{' )
			stack.push(ch);
		else if( ch == ']' || ch == ')' || ch == '}' ) {
			int prev = stack.pop();
			if( ( ch == ']' && prev != '[' )
				||  ( ch == ')' && prev != '(' )
				||  ( ch == '}' && prev != '{' ) ) break;
		}
	}
	fclose(fp);
	printf("[%s] 파일 검사결과:\n", filename );
	if( stack.isEmpty()==0 )
		printf("  오류발견 (라인수=%d, 문자수=%d)\n\n", nLine,nChar );
	else 
		printf("  괄호정상 (라인수=%d, 문자수=%d)\n\n", nLine,nChar);
	return stack.isEmpty();
}
int main()
{
	printf("왼쪽 괄호 = (((((\n");
	printf("오른쪽 괄호 = }}}}\n");
	bracketChecker("ArrayStack2.h");
	bracketChecker("BracketChecker2.cpp");

	return 0;
}