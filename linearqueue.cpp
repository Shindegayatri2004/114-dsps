#include<stdio.h>
#include<string.h>
#define max 5
int queue[max];
int rear=-1;
int front=-1;
void enqueue(int ele)
{
    if(rear==max-1)
    {
        printf("queue is full");
    }
    else
    {
        rear++;
        queue[rear]=ele;
    }
}
int dequeue()
{
    if(rear == front)
    {
        printf("queue is empty");
        return -1; 
    }
    else
    {
        front++;
        int ele=queue[front];
        printf("element deleted is %d",ele);
        return ele;
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
        for(int i = front + 1; i <= rear; i++) 
            printf("%d ", queue[i]); 
        }
    }

void main()
{
    int ele, ch, k;
    do
    {
        printf("\n1.enqueue\n2.dequeue\n3.display\n");
        printf("enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter queue element: ");
                scanf("%d",&ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
        printf("\nDo you want to continue? [press 1]: ");
        scanf("%d",&k);
    } while(k == 1);
}
