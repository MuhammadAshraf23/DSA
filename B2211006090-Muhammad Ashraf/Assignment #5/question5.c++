#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack structure
typedef struct {
    int top;
    int capacity;
    int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack operations
int isFull(Stack* stack) { return stack->top == stack->capacity - 1; }
int isEmpty(Stack* stack) { return stack->top == -1; }
void push(Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}
int peek(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top];
}

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform arithmetic operations
int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Function to evaluate the expression
int evaluate(char* expression) {
    Stack* values = createStack(strlen(expression));
    Stack* operators = createStack(strlen(expression));

    for (int i = 0; i < strlen(expression); i++) {
        // Skip spaces
        if (expression[i] == ' ') continue;

        // If the character is a digit, extract the number
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Go back one step
            push(values, num);
        }
        // If the character is an operator
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!isEmpty(operators) && precedence(peek(operators)) >= precedence(expression[i])) {
                char op = pop(operators);
                int val2 = pop(values);
                int val1 = pop(values);
                push(values, applyOperator(val1, val2, op));
            }
            push(operators, expression[i]);
        }
    }

    // Apply remaining operators
    while (!isEmpty(operators)) {
        char op = pop(operators);
        int val2 = pop(values);
        int val1 = pop(values);
        push(values, applyOperator(val1, val2, op));
    }

    // The result is the only element in the values stack
    return pop(values);
}

int main() {
    char expression[] = "3 + 5 * 2 - 8 / 4";
    printf("Result: %d\n", evaluate(expression));
    return 0;
}