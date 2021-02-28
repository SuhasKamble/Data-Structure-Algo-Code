#include <stdio.h>
#include <stdlib.h>
struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct CircularQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct CircularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = value;
    }
}

int dequeue(struct CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        return q->arr[q->f];
    }
}

int main()
{
    struct CircularQueue q;
    q.size = 5;
    q.r = q.f = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 10);
    enqueue(&q, 10);
    enqueue(&q, 10);
    enqueue(&q, 10);
    enqueue(&q, 10);
    enqueue(&q, 10);

    return 0;
}