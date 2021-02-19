#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedTraversal(struct Node *ptr)
{
    printf("Elements are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// case 1
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = head;
    return ptr;
}
// case 2
struct Node *indertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// case 3
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
// case 4
struct Node *insertAfterNode(struct Node *head, struct Node *prevData, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = prevData;
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = NULL;

    linkedTraversal(head);
    head = insertAfterNode(head, second, 13);
    linkedTraversal(head);

    return 0;
}