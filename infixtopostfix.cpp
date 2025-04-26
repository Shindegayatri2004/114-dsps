#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char x)
{
    top += 1;
    stack[top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else 
    {
        return -1;
    }
}

int main()
{
    char infix_exp[100];
    char c, x;
    int i;

    printf("Enter the infix equation: ");
    scanf("%s", infix_exp);

    printf("THE POSTFIX EXPRESSION IS: ");
    for (i = 0; i < strlen(infix_exp); i++)
    {
        c = infix_exp[i];
        if (precedence(c) > 0)
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
                printf("%c", pop());
            }
            push(c);
        }
        else if (c == ')')
        {
            x = pop();
            while (x != '(')
            {
                printf("%c", x);
                x = pop();
            }
        } 
        else if (c == '(')
        {
            push(c);
        }
        else 
        {
            printf("%c", c);
        }
    }
    while (top != -1)
    {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}

