#include<stdio.h>
#pragma warning(disable: 4996)

int main() {
    int arr[100], n, temp;
    printf("�Է��� ��� ���� : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}