//concate 2 linked list and sort 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *start)
{
    while (start != NULL)
    {
        printf("%d \n", start->data);
        start = start->next;
    }
}
void concate(struct node *start, struct node *start2)
{
    struct node *current = start;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = start2;
}

void sort(struct node*first)
{

    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = first;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data of adjacent nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


void main()
{
    struct node*first,*second,*third,*start;

    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    first ->data = 20;
    first ->next = second;
    second ->data = 10;
    second ->next = third;
    third ->data = 30;
    third ->next = NULL;
    start = first;
    printf("first linked list is \n");
    traverse(start);

    struct node*first2,*second2,*third2,*start2;

    first2 = (struct node*)malloc(sizeof(struct node));
    second2 = (struct node*)malloc(sizeof(struct node));
    third2 = (struct node*)malloc(sizeof(struct node));

    first2 ->data = 40;
    first2 ->next = second2;
    second2 ->data = 60;
    second2 ->next = third2;
    third2 ->data = 50;
    third2 ->next = NULL;
    start2 = first2;
    printf("second linked list is \n");
    traverse(start2);
    printf("merged linkedlist is \n");
    concate(start,start2);
    traverse(start);
    sort(start);
    printf("after sorting \n");
    traverse(start);
    


}