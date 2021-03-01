#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int n)
{
    int key, j;
    for (int i = 0; i < n - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int A[100];
    int n;
    printf("Enter the size of the array[max=100]: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}