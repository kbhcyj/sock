#include<stdio.h>

int main() {
    int arr[100], n, temp;
    printf("입력할 요소 개수 : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int j;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--) arr[j] = arr[j - 1];
        arr[j] = temp;
    }

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}