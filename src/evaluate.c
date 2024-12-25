#include "evaluate.h"

// POSTFIX TRANSCRIPTER

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

void postfix_enqueue(char *expression, struct stack *operator_stack, struct queue *output_queue)
{
    char *ptr = expression;
    
    while(*ptr)
    {
        while(isspace(*ptr)) ptr++;
        if(!*ptr || *ptr == '\'') break;
        
        struct token *token = get_token(ptr, expression);
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
	    if (*token->tkn == '-' &&
            (ptr == expression || *(ptr - 1) == '(' ||  *(ptr - 1) == ',' || is_operator(*(ptr - 1)))) 
	    {
		enqueue(output_queue, "0");
		push(operator_stack, token->tkn);
	    }
	    else 
	    {
		while (top(operator_stack) && *top(operator_stack) != '(' && 
		(precedence(*top(operator_stack)) > precedence(*token->tkn) || 
		(precedence(*top(operator_stack)) == precedence(*token->tkn) && 
		is_left_assoc(*token->tkn)))) 
		{
		    enqueue(output_queue, top(operator_stack));
		    pop(operator_stack);
		}
		push(operator_stack, token->tkn);
	    }
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



// POSTFIX EVALUATION

double postfix_eval(struct queue *output_queue, struct stack *eval_stack)
{
    while(front(output_queue))
    {
	if(is_number(front(output_queue)))
	{
	    push(eval_stack, front(output_queue));
	    popQueue(output_queue);
	}
	else if (is_operator(*front(output_queue)))
	{
	    if (*front(output_queue) == '-' && stack_size(eval_stack) == 1) 
	    {
		double A = strtod(top(eval_stack), NULL);
		pop(eval_stack);
		double result = -A;

		char *result_str = malloc(64);
		if (!result_str) exit(EXIT_FAILURE);
		sprintf(result_str, "%f", result);
		push(eval_stack, result_str);

		popQueue(output_queue);
	    } 
	    else 
	    {
		double A = strtod(top(eval_stack), NULL);
		pop(eval_stack);
		double B = strtod(top(eval_stack), NULL);
		pop(eval_stack);

		double result;

		switch (*front(output_queue))
		{
		    case '+': result = B + A; break;
		    case '-': result = B - A; break;
		    case '*': result = B * A; break;
		    case '/': result = B / A; break;
		    case '^': result = pow(B, A); break;
		}

		char *result_str = malloc(64);
		if (!result_str) exit(EXIT_FAILURE);
		sprintf(result_str, "%f", result);
		push(eval_stack, result_str);

		popQueue(output_queue);
	    }
	}
	else if(is_function(front(output_queue)))
	{
	    double A = strtod(top(eval_stack), NULL);
	    pop(eval_stack);

	    double result;

	    // ricordati di definirle sempre anche in tokenizer

	    if (strcmp(front(output_queue), "tan") == 0) {  
		result = tan(A);
	    } else if (strcmp(front(output_queue), "sin") == 0) {
		result = sin(A);
	    } else if (strcmp(front(output_queue), "cos") == 0) {
		result = cos(A);
	    } else if (strcmp(front(output_queue), "atn") == 0) {
		result = atan(A);
	    } else if (strcmp(front(output_queue), "asn") == 0) {
		result = asin(A);
	    } else if (strcmp(front(output_queue), "acs") == 0) {
		result = acos(A);
	    } else if (strcmp(front(output_queue), "lne") == 0) {
		result = log(A);
	    } else if (strcmp(front(output_queue), "exp") == 0) {
		result = exp(A);
	    } else if (strcmp(front(output_queue), "srt") == 0) {
		result = sqrt(A);
	    } else if (strcmp(front(output_queue), "crt") == 0) {
		result = pow(A, 1/3.);
	    } else if (strcmp(front(output_queue), "log") == 0) {
		double B = strtod(top(eval_stack), NULL);
		pop(eval_stack);
		result = log(A) / log(B); 
	    } else if (strcmp(front(output_queue), "nrt") == 0) {
		double B = strtod(top(eval_stack), NULL);
		pop(eval_stack);
		result = (A < 0 && ceilf(B) == B && (int)ceilf(B) % 2 == 1) ? -pow(-A, 1.0 / B) : pow(A, 1.0 / B);
	    } else if (strcmp(front(output_queue), "max") == 0){
		double B = strtod(top(eval_stack), NULL);
		pop(eval_stack);
		result = A > B ? A : B;
	    } else if (strcmp(front(output_queue), "min") == 0){
		double B = strtod(top(eval_stack), NULL);
		pop(eval_stack);
		result = A > B ? B : A;
	    } else {
		printf("operazione non valida: %s\n", front(output_queue));
	    }
	    
	    char *result_str = malloc(64);
	    if (!result_str)
	    {
		exit(EXIT_FAILURE);
	    }
	    
	    sprintf(result_str, "%f", result);
	    push(eval_stack, result_str);

	    popQueue(output_queue);   
	}
    }
    double res = strtod(top(eval_stack), NULL);
    destroyStack(&eval_stack);
    return res;
}


void evaluate(char *expression)
{    
    struct stack *operator_stack = stack_init();
    struct queue *output_queue = queue_init();

    struct stack *eval_stack = stack_init();

    postfix_enqueue(expression, operator_stack, output_queue);
    double result = postfix_eval(output_queue, eval_stack);
    printf("%s = %f\n", expression, result);
}
