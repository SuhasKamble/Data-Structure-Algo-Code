#include <stdio.h>
int stack[100], size, choice, top, value;
void push();
void pop();
void display();

int main()
{
    top = -1;
    printf("Welcome to Stack Using Arrays\n");
    printf("Enter the size of the stack[MAX=100]: ");
    scanf("%d", &size);
    printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit ");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;
        case 4:
            printf("Exited..");
            break;

        default:
            printf("Invalid input, Please try again!");
            break;
        }
    } while (choice != 4);
    return 0;
}
void push()
{
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("No elements in the stack\n");
    }
    else
    {
        for (int i = top; i > -1; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
