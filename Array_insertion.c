#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int index, int element, int capacity)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {1, 4, 7, 8, 79};
    int size = 5, index = 3, element = 5, capacity = 100;
    display(arr, size);
    indInsertion(arr, size, index, element, capacity);
    size += 1;
    display(arr, size);

    return 0;
}