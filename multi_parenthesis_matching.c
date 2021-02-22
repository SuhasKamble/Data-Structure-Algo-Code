#include <stdio.h>
#include <stdlib.h>
// creating the stack structure
struct stack
{
    int size;
    int top;
    char *arr;
};

// checking for the stack is empty or not
int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

// checking for the stack is full or not
int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}

// pushing the element in the stack
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
        char value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
}

int isMatch(int a, int b)
{
    if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int isParenthesisMatch(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_char;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_char = pop(sp);
            if (!isMatch(popped_char, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp = "{[(1+1)]}";
    if (isParenthesisMatch(exp))
    {
        printf("Parenthesis is matched!");
    }
    else
    {
        printf("Parenthesis is not matched!");
    }
    return 0;
}