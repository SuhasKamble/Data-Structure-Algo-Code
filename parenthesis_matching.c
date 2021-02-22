#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

void stackTraversal(struct stack *sp)
{
    if (sp->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (int i = sp->top; i > -1; i--)
        {
            printf("%d ", sp->arr[i]);
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
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *sp, char value)
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

int pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char popped_char = sp->arr[sp->top];
        sp->top--;
        return popped_char;
    }
}

int isParenthesisMatch(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    // traversing the exp
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {

        return 0;
    }
}
int main()
{
    char *exp = "((1+1)";
    if (isParenthesisMatch(exp))
    {
        printf("Parenthes is Matched");
    }
    else
    {
        printf("Parenthes is not matched");
    }

    return 0;
}