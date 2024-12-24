#include "tokenizer.h"

char *math_functions[] = {"sin", "cos", "tan", "asn", "acs", "atn"};

bool is_operator(char token)
{
    return token == '+' || token == '-' || token == '*' || token == '/' || token == '^';
}

bool is_function(char *token)
{
    bool is_function = 0;
    
    for(int i = 0; i < sizeof(math_functions)/sizeof(math_functions[0]); i++)
    {
	char *tmp = malloc(sizeof(char) * FUNCTION_LENGTH);
	strncpy(tmp, token, FUNCTION_LENGTH);
	
	if(strcmp(tmp, math_functions[i]) == 0)
	{
	    is_function = 1;
	    break;
	}
    }
    
    return is_function;
}


int number_size(char *token)
{
    int num_size = 0;

    while(isdigit(token[0]))
    {
	num_size++;
	token++;
    }
    return num_size;
}


bool is_number(char *token)
{
    bool is_number = 0;
    int num_size = number_size(token);
   
    if(num_size != 0)
    {
	return 1;
    }
}

struct token *get_token(char *exp)
{
    struct token *token = malloc(sizeof *token);

    if (!token)
    {
	exit(EXIT_FAILURE);
    }

    if(is_operator(exp[0]))
    {
	token->tkn = malloc((OPERATOR_LENGTH + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), OPERATOR_LENGTH);
	token->tt = Operator;
    }
    else if(is_function(&(exp[0])))
    {
	token->tkn = malloc((FUNCTION_LENGTH + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), FUNCTION_LENGTH);
	token->tt = Function;
    }
    else if(is_number(&(exp[0])))
    {
	token->tkn = malloc((number_size(&(exp[0])) + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), number_size(&(exp[0])));
	token->tt = Operand;
    }
    
    return token;
}
