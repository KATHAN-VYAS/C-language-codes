//insertion in circular linked list  
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *start) 
{
    if (start == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct node *current = start;
    while(current->next != start)
    {
        printf("%d \n",current->data);
        current = current ->next;
    }
    printf("%d\n", current->data);

/*using do while it becomes easy

do {
    printf("%d \n",current->data);
    current = current ->next;
}
while (current != start);
*/
}
void addfirst(struct node**start,int newdata)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node ));
    newnode->data = newdata;
    newnode->next = *start;
    struct node *current = *start;
    
    while(current->next != *start)
    {
        current = current->next;
    }
    current->next = newnode;
    newnode->next = *start;
    *start= newnode;

}
void addlast(struct node*start,int newdata)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node ));
    newnode->data = newdata;
    struct node*current = start;
    while(current ->next != start)
    {
        current = current->next;
    }
    current ->next = newnode;
    newnode->next = start;
}
void main()
{
    struct node*first,*second,*third,*start;

    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    first ->data = 10;
    first ->next = second;
    second ->data = 20;
    second ->next = third;
    third ->data = 30;
    third ->next = first;
    start = first;
    printf("printing elements of circular linked list \n");
    traverse(start);
    printf("list after adding element to first \n");
    addfirst(&start,0);
    traverse(start);
    printf("list after adding element to last \n");
    addlast(start,40);
    traverse(start);
}