#include "stack.h"

// Function to initialize the stack initialize(&stack)
void initialize(Stack *stack) {
    stack->top = -1;  
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;  
}

bool isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;  
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = stack->arr[stack->top];
    stack->top--;
    printf("Popped %d from the stack\n", popped);
    return popped;
}

// Function to peek the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}
