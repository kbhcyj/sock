#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int num, i = 0;
	int sum = 0; //합 결과
	int Evensum = 0; //짝수합 결과
	int Oddsum = 0; //홀수합 결과
	int fact = 1;

	printf("20210814 최예제\n");
	printf("정수를 입력하시오: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		sum += i;
	}
	printf("1부터 %d까지의 합은 %d입니다.\n", num, sum);

	for (i = 2; i <= num; i += 2)
	{
		Evensum += i;
	}

	for (i = 1; i <= num; i += 2)
	{
		Oddsum += i;
	}

	printf("1부터 %d까지의 짝수합은 %d입니다.\n", num, Evensum);
	printf("1부터 %d까지의 홀수합은 %d입니다.\n", num, Oddsum);

	i = 0;
	while (i < num)
	{
		i++;
		fact *= i;
	}
	printf("%d!은 %d입니다.", num, fact);
}