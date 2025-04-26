#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head, *newnode, *temp, *nextnode;

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertatfirst()
{
    newnode = malloc(sizeof(struct Node));
    printf("enter element: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
    newnode->prev = NULL;
}

void insertatlast()
{
    newnode = malloc(sizeof(struct Node));
    printf("enter element: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insertatposition()
{
    int pos, i2 = 1, count = 0;
    printf("enter position: ");
    scanf("%d", &pos);
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (pos < 1 || pos > count)
    {
        printf("invalid position");
    }
    else
    {
        temp = head;
        while (i2 < pos)
        {
            temp = temp->next;
            i2++;
        }
        newnode = malloc(sizeof(struct Node));
        printf("enter element: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deleteatfirst()
{
    if (head == NULL)
        printf("singly linked list is empty");
    else
    {
        temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
}

void deleteatlast()
{
    if (head == NULL)
    {
        printf("Singly linked list is empty\n");
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        temp->prev->next = NULL;
        free(temp);
    }
}

void deleteatposition()
{
    int pos, i = 1, count = 0;
    printf("enter position which you want to delete: ");
    scanf("%d", &pos);
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (pos < 1 || pos > count)
    {
        printf("invalid position");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        if (nextnode->next != NULL)
            nextnode->next->prev = temp;
        temp->next = nextnode->next;
        free(nextnode);
    }
}

int main()
{
    int choice,n,choice1;
    head = NULL;
    printf("enter total nodes to create: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct Node));
        printf("enter element: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    do
    {
        printf("1.Insert at start\n2.Insert at last\n3.Insert after position\n4.Display\n5.Delete at first\n6.Delete at last\n7.Delete at position\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertatfirst();
            break;
        case 2:
            insertatlast();
            break;
        case 3:
            insertatposition();
            break;
        case 4:
            display();
            break;
        case 5:
            deleteatfirst();
            break;
        case 6:
            deleteatlast();
            break;
        case 7:
            deleteatposition();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("Press 1 to continue: ");
        scanf("%d", &choice1);
    } while (choice1 == 1);
    return 0;
}
