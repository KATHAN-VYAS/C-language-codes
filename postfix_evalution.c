#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct stack{
    int top;
    unsigned capacity;
    int* array;
};
struct stack* creatstck(unsigned capacity)
{
    struct stack* stack1 = (struct stack*) malloc(sizeof (struct stack));
    if (!stack1)
    {
        return NULL;
    }
    stack1->top = -1;
    stack1 ->capacity = capacity;
    stack1->array = (int*)malloc(stack1->capacity*sizeof(int));
    if (!stack1->array)
    {
        return stack1;
    }
    return stack1;
}
int isEmpty (struct stack* stack1)
{
    return stack1->top == -1 ;
}
char peek (struct stack* stack1)
{
    return stack1->array[stack1->top];
}
char pop(struct stack* stack1)
{
    if(!isEmpty(stack1))
    {
        return stack1->array[stack1->top--];
    }
    return '$';
}
void push(struct stack* stack1,char op)
{
    stack1 ->array [++stack1->top]= op;
}
int evalutepostfix (char* exp)
{
    struct stack*stack1 = creatstck(strlen(exp));
    int i;
    if(!stack1)
    {
        return -1;
    }
    for (int i =0;exp[i];++i){
        if (isdigit(exp[i]))
        {
            push (stack1, exp[i]-'0');
        }
        else
        {
            int val1 = pop(stack1);
            int val2 = pop(stack1);
            switch (exp[i]){
                case'+':push(stack1,val2+val1);break;
                case'-':push(stack1,val2-val1);break;
                case'*':push(stack1,val2*val1);break;
                case'/':push(stack1,val2/val1);break;
            }
        }
    }
    return pop(stack1);
}
int main ()
{
    char exp[]= "231*+9-";
    printf("postfix evelution : %d",evalutepostfix(exp));
    return 0;
}
