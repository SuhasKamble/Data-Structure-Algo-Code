#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *sp, int i)
{
    int arrInd = sp->top - i + 1;
    if (arrInd < 0)
    {
        printf("Invalid Position");
        return -1;
    }
    return sp->arr[arrInd];
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}

void display(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("No elements in the stack\n");
    }
    else
    {
        printf("The elements are : ");
        for (int i = ptr->top; i > -1; i--)
        {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    push(sp, 10);
    push(sp, 20);
    push(sp, 30);
    push(sp, 40);

    // for (int i = 1; i < sp->top + 2; i++)
    // {
    //     printf("The value at position is %d is %d\n", i, peek(sp, i));
    // }

    printf("Thr top element in the stack is %d\n", stackTop(sp));
    printf("Thr bottom element in the stack is %d\n", stackBottom(sp));
    // display(sp);
    return 0;
}

// Note:
// All Operation of the stack requires constant time i.e O(1);
