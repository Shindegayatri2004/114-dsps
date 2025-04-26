#include <stdio.h>
#include <string.h>

#define max 5

int queue[max];
int rear = -1;
int front = -1;

void enqueue(int ele)
{
    if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        queue[rear] = ele;
    }
    else if ((rear + 1) % max == front)
    {
        printf("Circular queue full\n");
    } 
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = ele;
    }
}

void dequeue() 
{
    if (rear == -1 && front == -1)
    {
        printf("Circular queue empty\n");
    }
    else if (front == rear)
    {
        printf("Element deleted is %d\n", queue[front]);
        rear = -1;
        front = -1;
    }
    else 
    {
        printf("Element deleted is %d\n", queue[front]);
        front = (front + 1) % max;
    }
}

void display()
{
    if(rear==front)
    {
        printf("queue empty");
    }
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d",queue[i]);
    }
}
int main()
{
    int ele, ch, k;
    do 
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter queue element: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\nDo you want to continue? [Press 1]: ");
        scanf("%d", &k);
    } while (k == 1);
    return 0;
}
