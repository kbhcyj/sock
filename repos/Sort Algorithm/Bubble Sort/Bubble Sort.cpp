#include<stdio.h>

int main() {
    int arr[100], n, temp;
    printf("입력할 요소 개수 : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}