#include <stdio.h>

void printArray(int *arr, int n)
{
    printf("Elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void BubbleSort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for pass
    {
        for (int j = 0; j < n - 1 - i; j++) // for comparison
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int arr[100];
    int n;
    printf("Enter the size of the array[max=100]: ");
    scanf("%d", &n);
    printf("Enter the %d elements: \n", n);

    for (int i = 0; i < n; i++)
    {
        printf(">> ");
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    BubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}