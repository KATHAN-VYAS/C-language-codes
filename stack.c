    #include<stdio.h>
#include <stdlib.h>
#include<limits.h>

struct stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct stack *creatstack(unsigned capacity)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack ->capacity = capacity;
    stack ->top = -1;
    stack->array = (int *)malloc (stack ->capacity*sizeof(int)); //2nd * is for multiplication
    return stack ; //upp //This part is a typecast. Since malloc returns a void * (a generic pointer), you need to typecast it to the appropriate pointer type, which is int * in this case.
}
int isfull(struct stack* stack)
{
    return stack->top == stack->capacity-1;
}
int isempty (struct stack* stack )
{
    return stack ->top ==1;
}
void push (struct stack* stack,int item)
{
    if (isfull(stack))
        return ;
    stack->array [++stack ->top]= item;
    printf("%d pushed to stack \n",item);
}

int pop(struct stack* stack)
{
    if(isempty(stack))
        return INT_MIN; //INT_MIN is a macro that specifies that an integer variable cannot store any value below this limit
    return stack->array[stack->top-- ];
}                                       // instead of INT_MIN we can also use "\0"

int peek (struct stack* stack)
{
    if (isempty(stack))
        return INT_MIN;
    return stack ->array [stack->top];// after returning top is decreased so top element is changed
}

int main()
{
    struct stack* stack = creatstack(100);
    push (stack,10);
    push(stack,20);
    push (stack,30);
    printf(" %d \n",peek(stack));

    printf("%d popped from stack \n",pop(stack));
    return 0;
}