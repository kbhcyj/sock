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

char change_A(char);            //�ҹ��ڷ� ��ȯ�ϴ� �Լ� ������Ÿ�� ����
char change_a(char);            //�빮�ڷ� ��ȯ�ϴ� �Լ� ������Ÿ�� ����
char input(void);            //���ڸ� �Է��ϴ� �Լ� ������Ÿ�� ����
void output(char);            //������� ����ϴ� �Լ� ������Ÿ�� ����

void main() {
    char result;
    printf("���ĺ� �빮�� �ҹ��� ��ȯ��.\n");
    result = input();        //ȣ��
    if (result >= 65 && result <= 90) {                 //�빮���� ���
        result = change_A(result);        //ȣ��
        output(result);        //ȣ��
    }
    else if (result >= 97 && result <= 122) {                 //�ҹ����� ���
        result = change_a(result);        //ȣ��
        output(result);        //ȣ��
    }
    else {
        printf("�ùٸ� �Է°��� �ƴմϴ�.\n");
    }
} char change_A(char A) {
    A += 32;             //�ƽ�Ű �ڵ尪
    return A;
} char change_a(char a) {
    a -= 32;             //�ƽ�Ű �ڵ尪
    return a;
} char input(void) {
    char a;
    scanf("%c", &a);
    return a;
} void output(char result) {
    printf("result:%c", result);
}