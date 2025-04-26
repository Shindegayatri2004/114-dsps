#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int ch,n,i;
   struct Node *head,*newnode,*temp,*nextnode;
   

void display()
{   struct Node *temp;
    temp=head;
   while(temp!=NULL)
   {
       printf("%d\t",temp->data);
       temp=temp->next;
   }
   printf("\n"); 
}
void insertatfirst()
{  
    nextnode=malloc(sizeof(struct Node));
    newnode=malloc(sizeof(struct Node));
    printf("enter element");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insertatlast()
{  
    nextnode=malloc(sizeof(struct Node));
    newnode=malloc(sizeof(struct Node));
    printf("enter element");
    scanf("%d",&newnode->data);
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
}


void insertatposition()
{
int pos,i2=1,count=0;
printf("enter position");
scanf("%d",&pos);
temp=head;
while(temp!=NULL)
{
    temp=temp->next;
    count++;
}
if(pos>count)
{
 printf("invalid");
}
else
{
 temp=head;
 while(i2<pos-1)
 {
     temp=temp->next;
     i2++;
 }
    newnode=malloc(sizeof(struct Node));
    printf("enter element");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
}
}


void deleteatfirst()
{
   
    if(head==NULL)
    printf("singly linked list is empty");
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}



void deleteatlast()
{    struct Node *temp;
    struct Node *previousnode;
    temp=head;
    while(temp->next!=NULL)
    {
        previousnode=temp;
        temp=temp->next;
    }
    previousnode->next=NULL;
    free(temp);
}

void deleteatposition()
{    
    int pos,i3=1;
    struct Node *nextnode;
    printf("enter position");
    scanf("%d",&pos);
    temp=head;
    while(i3<pos-1)
    {
        temp=temp->next;
        i3++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}

int main()
{
   int ch,n,i;
//   struct Node *head,*newnode,*temp;
   head=NULL;
   printf("enter total node to create ");
   scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       newnode=malloc(sizeof(struct Node));
       printf("enter element");
       scanf("%d",&newnode->data);
       newnode->next=NULL;
       if(head==NULL)
       {
           head=newnode;
           temp=newnode;
       }
       else
       {
           temp->next=newnode;
           temp=newnode;
       }
    }
    int choice,i1,choice1;
    do
    {
        printf("1.Insert at start\n2.Insert at last\n3.Insert after position\n4.display\n5.delete at first\n6.delete at last\n7.delete at position\n");
    printf("enter choice");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insertatfirst();break;
        case 2:insertatlast();break;
        case 3:insertatposition();break;
        case 4:display();break;
         case 5:deleteatfirst();break;
         case 6:deleteatlast();break;
         case 7:deleteatposition();break;
        default:printf("invalid choice");break;
    }
     printf("press 1 to continue");
     scanf("%d",&choice1);
    }while(choice1==1);
    return 0;
}
