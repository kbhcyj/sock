#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int num, i = 0;
	int sum = 0; //�� ���
	int Evensum = 0; //¦���� ���
	int Oddsum = 0; //Ȧ���� ���
	int fact = 1;

	printf("20210814 �ֿ���\n");
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		sum += i;
	}
	printf("1���� %d������ ���� %d�Դϴ�.\n", num, sum);

	for (i = 2; i <= num; i += 2)
	{
		Evensum += i;
	}

	for (i = 1; i <= num; i += 2)
	{
		Oddsum += i;
	}

	printf("1���� %d������ ¦������ %d�Դϴ�.\n", num, Evensum);
	printf("1���� %d������ Ȧ������ %d�Դϴ�.\n", num, Oddsum);

	i = 0;
	while (i < num)
	{
		i++;
		fact *= i;
	}
	printf("%d!�� %d�Դϴ�.", num, fact);
}