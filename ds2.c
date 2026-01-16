//linked list and deleting from linked list
#include<stdlib.h>
#include <stdio.h>

struct node {
    int data;   
    struct node *next;
};

void traverse(struct node *start)
{
    struct node*current = start;
    while (current != NULL)
    {
        printf("%d \n",current ->data);
        current = current -> next;
    }
}
void deletefirst(struct node *start)
{
    if (start ==NULL )
    {
        printf("underflow");
        exit;
    }
    else
    {
        *start = *start->next;
    }
}
void deletelast(struct node *start)
{
    if (start == NULL)
    {
        printf("underflow");
        exit;
    }
    else
    {
        struct node*current = start;
        while ((current->next)->next!=NULL)
        {
            current = current->next;
        }
        current->next = NULL;
    }

}
void main()
{
    struct node *first,*second,*third,*forth,*start;

    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof (struct node));

    first ->data =10;
    first ->next = second;
    second ->data = 20;
    second ->next = third;
    third ->data = 30;
    third->next = forth;
    forth-> data = 40;
    forth->next = NULL;
    start =first;
    printf("linked list is: \n");
    traverse(start);
    deletefirst(start);
    printf("after deleting first node: \n");
    traverse(start);
    deletelast(start);
    printf("after deleting last node: \n");
    traverse(start);
}