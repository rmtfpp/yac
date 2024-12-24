#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
// #include "mat_functions.h"
#include "stack.h"
#include "queue.h"
#define DOUBLE_DIGITS 16
#include "tokenizer.h"

int precedence(char token)
{
    
    if (token == '+' || token == '-') return 0;
    else if (token == '*' || token == '/') return 1;
    else if (token == '^') return 2;
    else return -1;
}

bool is_left_assoc(char token)
{
    if (token != '^') return true;
    return false;
}

void postfix_enqueue(char *exp, struct stack *operator_stack, struct queue *output_queue)
{
    char *ptr = exp;
    
    while(*ptr)
    {
        while(isspace(*ptr)) ptr++;
        if(!*ptr || *ptr == '\'') break;
        
        struct token *token = get_token(ptr);
        if(!token->tkn)
	{
            free(token);
            ptr++;
            continue;
        }
        
        switch (token->tt)
	{
        case Number:
            enqueue(output_queue, token->tkn);
            break;
        case Function:
            push(operator_stack, token->tkn);
            break;
        case Operator:
            while (top(operator_stack) && *top(operator_stack) != '(' && 
            (precedence(*top(operator_stack)) > precedence(*token->tkn) ||
            (precedence(*top(operator_stack)) == precedence(*token->tkn) && 
            is_left_assoc(*token->tkn))))
	    {
                enqueue(output_queue, top(operator_stack));
                pop(operator_stack);
            }
            push(operator_stack, token->tkn);
            break;
        case Comma:
            while (top(operator_stack) && *top(operator_stack) != '(')
	    {
                enqueue(output_queue, top(operator_stack));
                pop(operator_stack);
            }
            break;
        case LBracket:
            push(operator_stack, token->tkn);
            break;
        case RBracket:
            while (top(operator_stack) && *top(operator_stack) != '(')
	    {
                enqueue(output_queue, top(operator_stack));
                pop(operator_stack);
            }
            if (!top(operator_stack))
	    {
                free(token);
                return;
            }
            pop(operator_stack);
            if (top(operator_stack) && strlen(top(operator_stack)) > 1)
	    {
                enqueue(output_queue, top(operator_stack));
                pop(operator_stack);
            }
            break;
        }
        
        ptr += strlen(token->tkn);
        free(token);
    }
    
    while(top(operator_stack))
    {
        if(*top(operator_stack) == '(')
	{
            pop(operator_stack);
            continue;
        }
        enqueue(output_queue, top(operator_stack));
        pop(operator_stack);
    }
}

void evaluate(char *exp)
{
    struct stack *operator_stack = stack_init();
    struct queue *output_queue = queue_init();

    postfix_enqueue(exp, operator_stack, output_queue);
}

int main()
{
    char *exp = "tan ( 2 + 1 ) - 4 * cos(1)'\0'";

    evaluate(exp);

    return EXIT_SUCCESS;
}
