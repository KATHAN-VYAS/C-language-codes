#include <stdio.h>
#include<stdlib.h>
#include <limits.h>

struct stack{
    int capacity;
    int top;
    int *arr;
};

struct stack *creatstack(int capacity)
{
    struct stack* stack = (struct stack *)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack ->top = -1;
    stack ->arr = (int*)malloc(stack-> capacity*sizeof(int));
    return stack;
};
int issfull(struct stack*stack)
{
    if (stack ->top == stack->capacity-1)
    {
        return 1;
    }
    else {
        return 0;
    }
}
int issempty (struct stack*stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void push (struct stack * stack,int item)
{   
    
    if(issfull(stack))
    {
        return ;
    }
    
    stack->arr[++stack->top]= item;
    printf("%d is pushed \n",item);
}
int pop(struct stack*stack)
{
    if(issempty(stack))
    {
        return INT_MIN;
    }
    printf("item popped \n");
    return stack->arr[stack->top--];
    
}
int peek (struct stack*stack)
{
    if (issempty(stack))
    {
        return INT_MIN;
    }
    printf("%d is peeked \n",stack->arr[stack->top]);
    return stack->arr[stack->top];

}
int main()
{
    struct stack *stack= creatstack(100);
    push(stack,10); 
    push(stack,20);
    push(stack,30);
    pop(stack);
    pop(stack);

    peek (stack);
    if (issempty(stack))
    {
        printf("its empty");
    }

    return 0;
}