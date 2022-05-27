#include<stdio.h>

int main() {
    int arr[100], n, temp;
    printf("입력할 요소 개수 : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i; j < n; j++) if (arr[j] < arr[min]) min = j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}