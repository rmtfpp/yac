#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "string_f.h"

struct stack_entry
{
    char *data;
    struct stack_entry *next;
};

struct stack
{
    struct stack_entry *head;
    size_t stackSize;
};

struct stack *stack_init(void);

void push(struct stack *Istack, char *value);

char *top(struct stack *Istack);

void pop(struct stack *Istack);

void clear (struct stack *Istack);

void destroyStack(struct stack **Istack);

int stack_size(struct stack *Istack);

#endif
