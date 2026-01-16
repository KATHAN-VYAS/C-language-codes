#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
void main(){
    struct node *head;
    struct node *forth;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));

    second = (struct node *)malloc(sizeof(struct node));

    third = (struct node *)malloc(sizeof(struct node));

    forth= (struct node *)malloc(sizeof(struct node));

    head ->data = 1;
    head->next = second;
    second ->data =2;
    second ->next = third;
    third ->data =3;
    third-> next = forth;
    forth->data = 4;
    forth ->next =NULL;

} 



