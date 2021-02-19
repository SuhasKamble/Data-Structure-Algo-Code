#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int size_of_array;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int size_of_array, int used_size)
{
    a->size_of_array = size_of_array;
    a->used_size = used_size;
    a->ptr = (int *)malloc(size_of_array * sizeof(int));
}

void setArray(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element %d: ", i);
        scanf("%d", &(a->ptr[i]));
    }
}

void showArray(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("The value at %d is %d\n", i, a->ptr[i]);
    }
}
int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    setArray(&marks);
    showArray(&marks);

    return 0;
}