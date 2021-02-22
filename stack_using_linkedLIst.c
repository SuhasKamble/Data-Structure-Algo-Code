#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void stackTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *push(struct Node *top, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Stack Overflow");
    }
    else
    {
        ptr->next = top;
        ptr->data = data;
        top = ptr;
        return top;
    }
}

struct Node *pop(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack Undeflow\n");
    }
    else
    {
        struct Node *ptr = top;
        top = top->next;
        free(ptr);
        return top;
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = pop(top);
    stackTraversal(top);
    return 0;
}