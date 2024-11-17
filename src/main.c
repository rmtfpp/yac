#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include "mat_functions.h"
#include "stack.h"
#define DOUBLE_DIGITS 16
#include "tokenizer.h"

int main()
{
    char *exp = "2*(1-3) + 3*sin(PI) - atan(1/4)'\0'";
    struct stack *thisStack = stack_init();

    while(exp[0] != '\0')
    {
	struct token *token = get_token(exp);
	if (token->tkn)
	{
	    exp = exp + strlen(token->tkn);
	}
	else
	{
	    exp++;
	}
	
    }
    
    
    return EXIT_SUCCESS;
}
