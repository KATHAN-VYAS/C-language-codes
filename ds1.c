//linked list and adding elements in linked list
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
        printf("%d \n",current ->data)  ;
        current = current -> next;
    }
}

void addfirst(struct node **first, int newData) {
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = *first; // Make the new node point to the current first node

    *first = newNode; // Update the first pointer to point to the new node
}

void addlast(struct node *start, int newdata)
{
    struct node *newnode = (struct node *)malloc (sizeof(struct node));
    newnode->data = newdata;
    newnode->next = NULL;
    struct node *current = start;
    while (current->next != NULL)
    {
        current = current ->next;
    }
    current->next = newnode;
}

void main()
{
    struct node *first,*second,*third,*start;

    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    first ->data =10;
    first ->next = second;
    second ->data = 20;
    second ->next = third;
    third ->data = 30;
    third->next = NULL;
    start =first;
    printf("linked list :\n");
    traverse(start);
    addfirst(&start, 40); 
    printf("linked list after adding 1st element:\n");
    traverse(start);
    printf("linked list after adding last element:\n");
    addlast(start,50); 
    traverse(start);
    traverse(start);
}