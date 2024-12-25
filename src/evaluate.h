#ifndef EVALUATE_H
#define EVALUATE_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "tokenizer.h"
// POSTFIX TRANSCRIPTER

int precedence(char token);

bool is_left_assoc(char token);

void postfix_enqueue(char *expression, struct stack *operator_stack, struct queue *output_queue);

double postfix_eval(struct queue *output_queue, struct stack *eval_stack);

void evaluate(char *expression);

#endif
