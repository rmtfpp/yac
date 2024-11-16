#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct {
    // Array to store stack elements
    int arr[MAX_STACK_SIZE];  
    // Index of the top element in the stack
    int top;        
} Stack;

void initialize(Stack *stack);

bool isEmpty(Stack *stack);

bool isFull(Stack *stack);

void push(Stack *stack, int value);

int pop(Stack *stack);

int peek(Stack *stack);

#endif
