#include <stdio.h>
#include <string.h>
#include <stdlib.h>
                        //## can try algo of notes look better !! ##//
struct Stack {
    int top;
    unsigned capacity;
    char* array; // Changed data type to 'char*' for characters
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (char*)malloc(stack->capacity * sizeof(char));

    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}   

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
    switch (ch) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

// The main function that converts given infix to postfix expression
void infixToPostfix(char* exp)
{
    int i, k;

    struct Stack* stack = createStack(strlen(exp));
    if (!stack)     // Check if stack was created successfully
    {
        printf("Stack creation failed.\n");
        return;
    }

    for (i = 0, k = -1; exp[i]; ++i)        //can do with k = 0 -->use postincreament
    {
        // If the scanned character is an operand, add it to output
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an '(', push it to the stack
        else if (exp[i] == '(')
            push(stack, exp[i]);

        // If the scanned character is an ')', pop and output from the stack
        // until a '(' is encountered.
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression\n");
                return;
            } else
                pop(stack);
        } else // An operator is encountered
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("%s\n", exp);
}

int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";

    // Function call
    infixToPostfix(exp);
    return 0;
}
