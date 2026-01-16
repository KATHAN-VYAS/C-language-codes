//deleting 1st and last element in circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void traverse(struct node *start) 
{
    if (start == NULL) {
        printf("underflow\n");
        return;
    }

    struct node *current = start;
    do
    {
        printf("%d \n", current->data);
        current = current->next;
    } while (current != start);
}

void delfirst(struct node** start)      //refer algorithm from book more easy
{
    if (*start == NULL) {
        printf("underflow\n");
        return;
    }

    struct node* current = *start;
    while (current->next != *start)
    {
        current = current->next;
    }
    
    if (*start == current) {
        free(*start);
        *start = NULL;
    } else {
        struct node* new_start = (*start)->next;
        current->next = new_start;
        free(*start);
        *start = new_start;
    }
}

void dellast(struct node *start)
{
    if (start == NULL) {
        printf("underflow\n");
        return;
    }

    struct node* current = start;
    while((current->next)->next != start)
    {
        current = current->next ;
    }
    
    struct node* last = current->next;
    current->next = start;
    free(last);
}

int main()
{
    struct node* first, * second, * third, * forth, * start;
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    forth = (struct node*)malloc(sizeof(struct node));
    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = forth;
    forth->data = 40;
    forth->next = first;
    start = first;
    
    printf("linked list is:\n");
    traverse(first);

    printf("after deleting last element:\n");
    dellast(start);
    traverse(first);

    printf("after deleting first element:\n");
    delfirst(&start);
    traverse(start);

    return 0;
}
