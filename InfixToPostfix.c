#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void display(struct stack *sp)
{
    if (sp->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (int i = sp->top; i > -1; i--)
        {
            printf("%c ", sp->arr[i]);
        }
        printf("\n");
    }
}

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *sp)
{
    if (sp->top >= sp->size)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *sp, int value)
{
    if (isFull(sp))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = value;
    }
}

char pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
}

int isOperator(char op)
{
    if (op == '+' || op == '/' || op == '-' || op == '*')
    {
        return 1;
    }
    return 0;
}

int precendence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track the infix traversal
    int j = 0; // Track the posfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precendence(infix[i]) > precendence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    return postfix;
}

int main()
{
    char *infix = "a+b-x*y";
    printf("The postfix is %s ", infixToPostfix(infix));
    return 0;
}