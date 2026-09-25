#include <stdio.h>

int binary_search(int arr[], int size, int num);

int main() {
    int arr[] = {45, 78, 21, 1, 90, 5, 12, 29, 7, 34};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Sorting the array using selection sort
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = i + 1; j < arr_size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int num;
    printf("Enter the number to search: ");
    scanf("%d", &num);

    binary_search(arr, arr_size, num);
}

int binary_search(int arr[], int size, int num) {
    int first = 0;
    int last = size - 1;

    while (first <= last) {
        int mid = (first + last) / 2;
        if (arr[mid] == num) {
            printf("%d is found at %dth index\n", num, mid);
            return 0;
        } else if (arr[mid] < num) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }

    printf("%d is absent\n", num);
    return 0;
}
