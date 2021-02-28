#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int disply(struct queue *q)
{
    if (q->f == q->r)
    {
        printf("No Elements\n");
    }
    else
    {
        for (int i = q->r; i > q->f; i--)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}
int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        int value = q->arr[q->r];
        q->f++;
        return value;
    }
}
int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 10);
    enqueue(&q, 30);
    enqueue(&q, 50);
    dequeue(&q);
    disply(&q);
    return 0;
}