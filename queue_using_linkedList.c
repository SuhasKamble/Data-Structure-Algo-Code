#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int *next;
};
struct Node *f = NULL;
struct Node *r = NULL;

void traversal(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("No Element\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("Element %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    traversal(f);
    enqueue(70);
    enqueue(10);
    enqueue(40);
    enqueue(80);
    traversal(f);
    printf("Dequeuig the element %d ", dequeue());
    return 0;
}