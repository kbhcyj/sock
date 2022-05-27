#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // 소스코드에 ifdef를 이용하여 define으로 _CRT_SECURE_NO_WARNINGS를 선언
//#pragma warning(disable: 4996)를 사용해도 무방하다. (4996은 에러코드)

#include <stdio.h>

int main(void){
	int num;

	printf("num값 입력: ");
	int temp = scanf("%d", &num); // int temp는 에러를 방지하기 위해 반환값 저장 -> 메모리 낭비
	printf("num: %d\n", num);
	printf("num: %d\n", temp);

	return 0;
}