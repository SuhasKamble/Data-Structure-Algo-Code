#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void indDeletion(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5, index = 2, capacity = 100;
    display(arr, size);
    indDeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}