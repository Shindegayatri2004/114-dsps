#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *rear,*front,*newnode,*temp;
void enqueue();
void dequeue();
void display();


void main()
{
    int ch,choice;
    rear=NULL;
    front=NULL;
    do
    {
        printf("1. enqueue\n2. dequeue\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                enqueue();
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
        printf("Continue? Press 1: ");
        scanf("%d",&choice);
    }
    while(choice==1);
}
 void enqueue()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    if(front==NULL && rear==NULL)
    {
        front=newnode;
        rear=newnode;
        front->next=NULL;
        rear->next=NULL;
    }
    else
    {
        rear->next=newnode;
        newnode->next=NULL;
        rear=newnode;
    }
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        temp=front;
        front=front->next;
        free(temp);
    }
}

void display()
{
    temp=front;
    if(temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
