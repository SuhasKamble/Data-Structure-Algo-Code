#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int size, int element)
{
    int low, high, mid;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 5, 6, 8, 10, 14, 16, 78};
    int size = sizeof(arr) / sizeof(int);
    int element = 110;
    int searchIndex = linearSearch(arr, size, element);
    printf("The element %d is found at %d", element, searchIndex);
    return 0;
}