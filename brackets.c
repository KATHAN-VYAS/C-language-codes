#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Structure to represent a stack
struct Stack 
{
 char data;
 struct Stack* next;
};
// Function to create a new stack node
struct Stack* newNode(char data) 
{
 struct Stack* stackNode = (struct Stack*)malloc(sizeof(struct Stack));
 stackNode ->data = data;
 stackNode ->next = NULL;
 return stackNode;
}
// Function to check if the stack is empty
bool isEmpty(struct Stack* root) {
 return (root == NULL);
}
// Function to push a character onto the stack
void push(struct Stack** root, char data) {
 struct Stack* stackNode = newNode(data);
 stackNode->next = *root;
 *root = stackNode;
}
// Function to pop a character from the stack
char pop(struct Stack** root) {
 if (isEmpty(*root))
 return '\0';
struct Stack* temp = *root;
 *root = (*root)->next;
 char popped = temp->data;
 free(temp);  
 return popped;
}
// Function to check if the given string has balanced parentheses
bool isBalanced(char* expression) {
 struct Stack* stack = NULL;
 int length = strlen(expression);
 for (int i = 0; i < length; i++) {
 if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') 
 {
 push(&stack, expression[i]);
 } 
 else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') 
 {
 if (isEmpty(stack))
 return false;
 char top = pop(&stack);
 // Check if the popped character matches the current closing character
 if ((expression[i] == ')' && top != '(') ||
 (expression[i] == '}' && top != '{') ||
 (expression[i] == ']' && top != '[')) {
 return false;
 }
 }
 }
 return isEmpty(stack); // If the stack is empty at the end, it's balanced
}
int main() {
 char expression[100];
 printf("Enter a string containing parentheses: ");
 fgets(expression, sizeof(expression), stdin);
 expression[strcspn(expression, "\n")] = '\0'; // Remove the newline character
if (isBalanced(expression))
 printf("Balanced\n");
 else
 printf("Not balanced\n");
}
