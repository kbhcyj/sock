#define _CRT_SECURE_NO_WARNINGS
//#pragma warnings(disable: 4996)

#include <stdio.h>

int main(void)
{
	int age, count;
	double weight, hight;
	//printf("Enter age.\n");
	//scanf("%d", &age);
	//printf("Age = %d", age);
	printf("Enter weight, hight.\n");
	scanf("%ld, %ld", &weight, &hight);
	printf("weight, hight = %ld, %ld", weight, hight);

	return 0;
}