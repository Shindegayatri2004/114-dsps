#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL,*newnode,*temp;

void push();
void pop();
void display();

void main()
{
    int ch,t;
    do
    {
        printf("1. push\n2. pop\n3. display\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
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
            default:
                printf("Invalid choice\n");
        }
        printf("Continue? Press 1: ");
        scanf("%d",&t);
    }
    while(t==1);
}

void push()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    if(top==NULL)
    {
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack underflow\n");
    }
    else
    {
        temp=top;
        top=top->next;
        free(temp);
    }
}

void display()
{
    temp=top;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
