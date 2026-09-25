#include <stdio.h>

void printarray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int partition(int *arr, int low, int high)
{
    int i = low + 1;
    int j = high;
    int pivot = arr[low];

    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}
void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quicksort(arr, low, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, high);
    }
}
int main()
{
    int arr[] = {3, 5, 2, 13, 12, 1};
    int size = 6;

    printf("before sorting\n");
    printarray(arr, size);
    quicksort(arr, 0, 5);
    printf("after sorting\n");
    printarray(arr, size);

    return 0;
}