#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // �ҽ��ڵ忡 ifdef�� �̿��Ͽ� define���� _CRT_SECURE_NO_WARNINGS�� ����
//#pragma warning(disable: 4996)�� ����ص� �����ϴ�. (4996�� �����ڵ�)

#include <stdio.h>

int main(void){
	int num;

	printf("num�� �Է�: ");
	int temp = scanf("%d", &num); // int temp�� ������ �����ϱ� ���� ��ȯ�� ���� -> �޸� ����
	printf("num: %d\n", num);
	printf("num: %d\n", temp);

	return 0;
}