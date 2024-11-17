#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include "mat_functions.h"
#include "stack.h"
#define DOUBLE_DIGITS 16
#include "tokenizer.h"

int main()
{
    char *expression = "2*(1-3) + 3*cos(PI) - atan(1/4)";
    struct stack *thisStack = stack_init();

    struct token *next_token = tokenize(&expression);
    printf("%s\n", next_token->tkn);
    
    return EXIT_SUCCESS;
}
