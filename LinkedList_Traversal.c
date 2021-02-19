#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate the dyanamicallt memory to node in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link the head and second node
    head->data = 10;
    head->next = second;

    // Link the second and third node
    second->data = 20;
    second->next = third;

    // Link the head and second node
    third->data = 30;
    third->next = fourth;

    // Link the head to the NULL
    fourth->data = 40;
    fourth->next = NULL;

    linkedListTraversal(head);

    return 0;
}