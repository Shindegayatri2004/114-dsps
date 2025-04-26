#include <stdio.h>
int stack[10];
int top = -1;

void push(int x);
void pop();
int dec_to_binary(int num);

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    dec_to_binary(num);
    printf("\n");
    return 0;
}

int dec_to_binary(int num)
{
    if (num == 0) 
    {
        printf("Binary equivalent: 0");
        return 0;
    }

    while (num > 0)
    {
        int rem = num % 2;
        push(rem);
        num = num / 2;
    }

    printf("Binary equivalent: ");
    while (top != -1) {
        printf("%d", stack[top]);
        pop();
    }

    return 0;
}

void push(int x) 
{
    top++;
    stack[top] = x;
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    top--;
}


