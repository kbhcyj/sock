#pragma warning(disable: 4996)
#include <stdio.h>

int main() {
	printf("���� �Է��Ͻÿ�.\n");
	int num;
	int	*p;
	p = &num;
	*p = 5;
	printf("num���� %d, ���� num�� �ּҴ� %d�Դϴ�.\n", *p, p);	//���� num�� ���� *p�� ����.

	return 0;
}