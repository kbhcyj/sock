/*
#pragma warning(disable: 4996)

#include <stdio.h>

int s(int a, int b);
int m(int a, int b);

void main() {
	int results;
	results = s(3, 4);
	
	int resultm;
	resultm = m(5, 2);

	printf("%d\n", results );	//7
	printf("%d\n", resultm );	//3
	return 0;
}

int s(int a, int b) {
	int s;
	s = a + b;
	return s;
}

int m(int a, int b) {
	int m;
	m = a - b;
	return m;
}*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>

char change_A(char);            //소문자로 변환하는 함수 프로토타입 선언
char change_a(char);            //대문자로 변환하는 함수 프로토타입 선언
char input(void);            //문자를 입력하는 함수 프로토타입 선언
void output(char);            //결과값을 출력하는 함수 프로토타입 선언

void main() {
    char result;
    printf("알파벳 대문자 소문자 변환기.\n");
    result = input();        //호출
    if (result >= 65 && result <= 90) {                 //대문자일 경우
        result = change_A(result);        //호출
        output(result);        //호출
    }
    else if (result >= 97 && result <= 122) {                 //소문자일 경우
        result = change_a(result);        //호출
        output(result);        //호출
    }
    else {
        printf("올바른 입력값이 아닙니다.\n");
    }
} char change_A(char A) {
    A += 32;             //아스키 코드값
    return A;
} char change_a(char a) {
    a -= 32;             //아스키 코드값
    return a;
} char input(void) {
    char a;
    scanf("%c", &a);
    return a;
} void output(char result) {
    printf("result:%c", result);
}