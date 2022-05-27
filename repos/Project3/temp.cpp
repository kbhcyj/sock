#pragma warning(disable: 4996)
#include <stdio.h>

int main() {
	printf("값을 입력하시오.\n");
	int num;
	int	*p;
	p = &num;
	*p = 5;
	printf("num값은 %d, 변수 num의 주소는 %d입니다.\n", *p, p);	//변수 num의 값은 *p와 같다.

	return 0;
}