#include <stdio.h>
void productArray(int arr[], int n, int prod[]) {
    if (n == 1) {
        prod[0] = 0;
        return;
    }

    int left[n], right[n];
    left[0] = 1;
    for (int i = 1; i < n; i++)
        left[i] = arr[i - 1] * left[i - 1];
    right[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--)
        right[j] = arr[j + 1] * right[j + 1];

  
    for (int i = 0; i < n; i++)
        prod[i] = left[i] * right[i];
}

int main() {
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prod[n];

    productArray(arr, n, prod);

    for (int i = 0; i < n; i++)
        printf("%d ", prod[i]);
    printf("\n");

    return 0;
}
